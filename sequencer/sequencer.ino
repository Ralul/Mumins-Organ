// Pipe Organ Sequencer - Button Input with MIDI USB Output
// Uses Arduino Micro's native USB MIDI capability
// Appears as a MIDI device on the computer

#include <MIDIUSB.h>

// Define the number of buttons/contacts
#define NUM_BUTTONS 8

// Define the digital input pins for each button/contact
// These can be adjusted based on your wiring
// Wire: Switch between pin and GND (uses built-in pull-up resistors)
const int buttonPins[NUM_BUTTONS] = {2, 3, 4, 5, 6, 7, 8, 9};

// MIDI channel (0-15, typically 0 = channel 1)
#define MIDI_CHANNEL 0

// MIDI note numbers for each button
const int midiNotes[NUM_BUTTONS] = {60, 62, 64, 65, 67, 69, 71, 72}; // C4, D4, E4, F4, G4, A4, B4, C5

// MIDI velocity (0-127)
#define MIDI_VELOCITY 100

// Store previous button states for edge detection
bool previousButtonStates[NUM_BUTTONS] = {false};

void setup() {
  
}

void loop() {
  // Read each button and check for state changes
  for (int i = 0; i < NUM_BUTTONS; i++) {
    // Read the current state
    // With INPUT_PULLUP: switch closed = GND = LOW, switch open = HIGH (pulled up)
    bool currentState = digitalRead(buttonPins[i]) == LOW;
    
    // Check if state changed from previous reading
    if (currentState != previousButtonStates[i]) {
      if (currentState) {
        sendMidiNoteOn(midiNotes[i], MIDI_VELOCITY);
      } else {
        sendMidiNoteOff(midiNotes[i], 0);
      }
      
      // Update previous state
      previousButtonStates[i] = currentState;
    }
  }
  
  // Small delay to debounce and reduce Serial output flood
  delay(10);
}

// Helper function to convert MIDI note number to note name
String getNoteName(int midiNote) {
  const char* noteNames[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
  int note = midiNote % 12;
  int octave = (midiNote / 12) - 1;
  
  String result = String(noteNames[note]) + String(octave);
  return result;
}

// MIDI Note On function using MIDIUSB library
void sendMidiNoteOn(int note, int velocity) {
  // Create a MIDI Note On message
  // Status byte: 0x90 | channel (0x90 = Note On, channel 0)
  midiEventPacket_t noteOn = {0x09, 0x90 | MIDI_CHANNEL, note, velocity};
  MidiUSB.sendMIDI(noteOn);
  MidiUSB.flush();
}

// MIDI Note Off function using MIDIUSB library
void sendMidiNoteOff(int note, int velocity) {
  // Create a MIDI Note Off message
  // Status byte: 0x80 | channel (0x80 = Note Off, channel 0)
  midiEventPacket_t noteOff = {0x08, 0x80 | MIDI_CHANNEL, note, velocity};
  MidiUSB.sendMIDI(noteOff);
  MidiUSB.flush();
}
