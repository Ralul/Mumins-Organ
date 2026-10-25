#include "MIDIUSB.h"

#define NUM_BUTTONS 6

const int buttonPins[NUM_BUTTONS] = {2, 3, 4, 5, 6, 7};

// Store previous button states for edge detection
bool previousButtonStates[NUM_BUTTONS] = {false};

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {

  for (int i = 0; i < NUM_BUTTONS; i++) {
    bool currentState = digitalRead(buttonPins[i]) == LOW;
    
    if (currentState != previousButtonStates[i]) {
      Serial.print("Pin ");
      Serial.print(buttonPins[i]);
      Serial.println(" changed");
      previousButtonStates[i] = currentState;

      if (currentState) {
        noteOn(0, i, 126 );
        Serial.println("note on");
      } else {
        noteOff(0, i, 0 );
        Serial.println("note off");
      }
    }

  }
  
  // Small delay to debounce and reduce Serial output flood
  delay(10);
}


// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
  MidiUSB.flush();
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
  MidiUSB.flush();
}
