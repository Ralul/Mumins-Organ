unsigned long lastDebounceTime[NUM_BUTTONS];

const int debounceInterval = 50;

void loop() {
  // ... (previous code)

  for (int i = 0; i < NUM_BUTTONS; i++) {
    int buttonState = digitalRead(buttonPins[i]);
    
    if (buttonState != lastButtonState[i]) {
      lastDebounceTime[i] = millis();
    }

    if ((millis() - lastDebounceTime[i]) > debounceInterval) {
      if (buttonState == LOW) {
        MIDI.sendNoteOn(noteNumbers[i], 127, 1);
        buttonStates[i] = 1;
      } else {
        MIDI.sendNoteOff(noteNumbers[i], 0, 1);
        buttonStates[i] = 0;
      }
    }

    lastButtonState[i] = buttonState;
  }
}
