import sys
import time
import queue
import rtmidi
import serial
import threading
import logging
import json
import argparse

class SerialToMidiBridge:
    def __init__(self, serial_port_name, baud, midi_channel):
        self.receiving_message = []
        self.midiout_message_queue = queue.Queue()
        self.serial_port_name = serial_port_name
        self.baud = baud
        self.midi_channel = midi_channel
        self.is_initialized = False
        self.thread_running = True
        self.lock = threading.Lock()

        try:
            # Initialize MIDI output
            self.midi_out = rtmidi.MidiOut()
            self.available_ports = self.midi_out.get_ports()
            if self.available_ports:
                self.midi_out.open_port(self.midi_channel)
            else:
                self.midi_out.open_virtual_port()

            # Initialize serial port
            self.ser = serial.Serial(serial_port_name, baud)
            self.is_initialized = True
        except Exception as e:
            logging.error(f"Error during initialization: {e}")

    def __del__(self):
        """Destructor to release resources."""
        if hasattr(self, 'ser'):
            self.ser.close()
        if hasattr(self, 'midi_out'):
            self.midi_out.close_port()

    def _get_midi_length(self, message):
        """
        Determines the expected length of a MIDI message.
        """
        if len(message) == 0:
            return 100
        opcode = message[0]
        if opcode >= 0xf4:
            return 1
        if opcode in [0xf1, 0xf3]:
            return 2
        if opcode == 0xf2:
            return 3
        if opcode == 0xf0:
            if message[-1] == 0xf7:
                return len(message)
        opcode = opcode & 0xf0
        if opcode in [0x80, 0x90, 0xa0, 0xb0, 0xe0]:
            return 3
        if opcode in [0xc0, 0xd0]:
            return 2
        return 100

    def serial_watcher(self):
        """
        Continuously reads from the serial port and forwards the data to the MIDI output port.
        """
        running_status = None  # Store the running status
        while self.thread_running:
            with self.lock:
                try:
                    data = self.ser.read()
                    if data:
                        for elem in data:
                            self.receiving_message.append(elem)
                        # Running status
                        if len(self.receiving_message) == 1:
                            if (self.receiving_message[0] & 0xf0) != 0:
                                running_status = self.receiving_message[0]
                            else:
                                self.receiving_message = [running_status, self.receiving_message[0]]

                        message_length = self._get_midi_length(self.receiving_message)
                        if message_length <= len(self.receiving_message):
                            logging.debug(f"Received Serial Message: {self.receiving_message}")
                            self.midiout_message_queue.put(self.receiving_message)
                            self.receiving_message = []
                            
                except Exception as e:
                    logging.error(f"Error reading from serial or sending to MIDI: {e}")
 
    def midi_sender(self):
        while self.thread_running:
            try:
                message = self.midiout_message_queue.get(timeout=0.4)  # wait up to 0.4 second
                if message:
                    self.midi_out.send_message(message)
            except queue.Empty:
                pass
            except Exception as e:
                logging.error(f"Error sending to MIDI: {e}")

class SerialMidiManager:
    def __init__(self, configurations):
        self.bridges = []
        self.watcher_threads = []
        self.sender_threads = []
        for config in configurations:
            bridge = SerialToMidiBridge(
                config['serial_port_name'], 
                config['baud'], 
                config['midi_channel']
            )
            if bridge.is_initialized:
                self.bridges.append(bridge)
                watcher_thread = threading.Thread(target=bridge.serial_watcher)
                sender_thread = threading.Thread(target=bridge.midi_sender)
                self.watcher_threads.append(watcher_thread)
                self.sender_threads.append(sender_thread)

    def __del__(self):
        """Destructor to release resources."""
        for bridge in self.bridges:
            del bridge

    def start(self):
        """Starts all watcher and sender threads."""
        for thread in self.watcher_threads + self.sender_threads:
            thread.start()
            
    def stop(self):
        """Stops all watcher and sender threads."""
        for bridge in self.bridges:
            bridge.thread_running = False
        for thread in self.watcher_threads + self.sender_threads:
            thread.join()

def load_configurations(config_file):
    """
    Loads configurations from a specified JSON file.
    
    Args:
    - config_file (str): Path to the configuration file.
    
    Returns:
    - list: List of configurations.
    """
    try:
        with open(config_file, 'r') as file:
            configurations = json.load(file)
        return configurations
    except Exception as e:
        logging.error(f"Error loading configurations from {config_file}: {e}")
        return []

if __name__ == "__main__":
    # Argument parsing
    parser = argparse.ArgumentParser(description="Serial to MIDI bridge")
    parser.add_argument("config_file", type=str, default="config.json", help="Path to the configuration JSON file. Default is 'config.json'")
    parser.add_argument("--loglevel", choices=['DEBUG', 'INFO', 'WARNING', 'ERROR', 'CRITICAL'], default='DEBUG', help="Logging level.")
    
    args = parser.parse_args()

    # Set logging level
    numeric_level = getattr(logging, args.loglevel.upper(), None)
    if not isinstance(numeric_level, int):
        raise ValueError(f"Invalid log level: {args.loglevel}")
    logging.basicConfig(level=numeric_level)

    # Load configurations
    configurations = load_configurations(args.config_file)
    if not configurations:
        logging.error("No configurations loaded. Exiting.")
        sys.exit(1)

    # Initialize and start the manager
    manager = SerialMidiManager(configurations)
    manager.start()

    # Keep the program running.
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        logging.info("Received keyboard interrupt. Stopping manager...")
        manager.stop()
        logging.info("Program terminated.")
