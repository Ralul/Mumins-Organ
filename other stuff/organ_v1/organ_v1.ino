// Include the MIDI library
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

// Pin to which the momentary switch is connected
const int buttonPin = 2;

// Variables to hold the button state
int buttonState = HIGH;
int lastButtonState = HIGH;

// Variable to store the MIDI note number (e.g., C4)
const int midiNote = 60;

void setup() {
  // Set the button pin as input
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize the MIDI library
  MIDI.begin(MIDI_CHANNEL_OMNI);

  // Allow time for MIDI device to be recognized
  delay(1000);

  // Print a message to the serial monitor
  //Serial.println("MIDI device is ready!");
}

void loop() {
  // Read the button state
  buttonState = digitalRead(buttonPin);

  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    // If the button is pressed (closed)
    if (buttonState == LOW) {
      // Send a MIDI note-on message (note number, velocity, channel)
      MIDI.sendNoteOn(midiNote, 127, 1);
      delay(10);                      // wait for a second
    } else {
      // Send a MIDI note-off message (note number, velocity, channel)
      MIDI.sendNoteOff(midiNote, 0, 1);
    }

    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    // Update the last button state
    lastButtonState = buttonState;
  }
}
