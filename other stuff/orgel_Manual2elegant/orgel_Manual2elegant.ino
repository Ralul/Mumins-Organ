#include <MIDI.h>

// Override the default MIDI baudrate to
// a decoding program such as Hairless MIDI (set baudrate to 115200)
struct CustomBaudRateSettings : public MIDI_NAMESPACE::DefaultSerialSettings {
  static const long BaudRate = 38400;
};

#if defined(ARDUINO_SAM_DUE) || defined(USBCON) || defined(__MK20DX128__) || defined(__MK20DX256__) || defined(__MKL26Z64__)
    // Leonardo, Due and other USB boards use Serial1 by default.
    MIDI_NAMESPACE::SerialMIDI<HardwareSerial, CustomBaudRateSettings> serialMIDI(Serial1);
    MIDI_NAMESPACE::MidiInterface<MIDI_NAMESPACE::SerialMIDI<HardwareSerial, CustomBaudRateSettings>> MIDI((MIDI_NAMESPACE::SerialMIDI<HardwareSerial, CustomBaudRateSettings>&)serialMIDI);
#else
    MIDI_NAMESPACE::SerialMIDI<HardwareSerial, CustomBaudRateSettings> serialMIDI(Serial);
    MIDI_NAMESPACE::MidiInterface<MIDI_NAMESPACE::SerialMIDI<HardwareSerial, CustomBaudRateSettings>> MIDI((MIDI_NAMESPACE::SerialMIDI<HardwareSerial, CustomBaudRateSettings>&)serialMIDI);
#endif


#define NUM_BUTTONS 56 // Total number of buttons

int buttons[NUM_BUTTONS] = {
  // Define the digital pin numbers for each button
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
  // Add the analog input pins for the other buttons
  A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12,
  // Add more buttons if needed
  22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53

};

int buttonStates[NUM_BUTTONS] = {0}; // Array to store the button states

//MIDI_CREATE_DEFAULT_INSTANCE(); // Create a MIDI instance

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI); // Start MIDI communication on all channels

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP); // Set all buttons as INPUT_PULLUP
  }
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int buttonState = digitalRead(buttons[i]); // Read the state of the current button
    if (buttonState == LOW && buttonStates[i] == 0) {
      // Button is pressed, and it wasn't pressed previously
      MIDI.sendNoteOn(36 + i, 127, 1); // Send MIDI note on with note number based on button index
      buttonStates[i] = 1; // Update the button state
    } else if (buttonState == HIGH && buttonStates[i] == 1) {
      // Button is released, and it was pressed previously
      MIDI.sendNoteOff(36 + i, 0, 1); // Send MIDI note off with note number based on button index
      buttonStates[i] = 0; // Update the button state
    }
  }
}
