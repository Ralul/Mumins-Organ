
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

//MIDI_CREATE_DEFAULT_INSTANCE();

//grosse Oktave
int button1 = 2; //button1 on digital pin 2
int button2 = 3; //button2 on digital pin 3
int button3 = 4; //button3 on digital pin 4
int button4 = 5; //button4 on digital pin 5
int button5 = 6; //button5 on digital pin 6
int button6 = 7; //button6 on digital pin 7
int button7 = 8; //button7 on digital pin 8
int button8 = 9; //button8 on digital pin 9
int button9 = 10; //button9 on digital pin 10
int button10 = 11; //button10 on digital pin 11
int button11 = 12; //button11 on digital pin 12
int button12 = 13;

//0 oktave -> Analogeingänge!!

int button13 = A1; //C
int button14 = A2; //Cs
int button15 = A3; //D
int button16 = A4; //Ds
int button17 = A5; //E
int button18 = A6; //F
int button19 = A7; //Fs
int button20 = A8; //G
int button21 = A9; //Gs
int button22 = A10; //A
int button23 = A11; //B
int button24 = A12;

//eingestrichene Oktave

int button25 = 22;
int button26 = 23;
int button27 = 24;
int button28 = 25;
int button29 = 26;
int button30 = 27;
int button31 = 28;
int button32 = 29;
int button33 = 30;
int button34 = 31;
int button35 = 32;
int button36 = 33;

//zweigestrichene Oktave

int button37 = 34;
int button38 = 35;
int button39 = 36;
int button40 = 37;
int button41 = 38;
int button42 = 39;
int button43 = 40;
int button44 = 41;
int button45 = 42;
int button46 = 43;
int button47 = 44;
int button48 = 45;

//dreigestrichene Oktave bis g

int button49 = 46;
int button50 = 47;
int button51 = 48;
int button52 = 49;
int button53 = 50;
int button54 = 51;
int button55 = 52;
int button56 = 53;

//Grosse

int button1beans = 0;
int button2beans = 0;
int button3beans = 0;
int button4beans = 0;
int button5beans = 0;
int button6beans = 0;
int button7beans = 0;
int button8beans = 0;
int button9beans = 0;
int button10beans = 0;
int button11beans = 0;
int button12beans = 0;

//0 Okt.

int button13beans = 0;
int button14beans = 0;
int button15beans = 0;
int button16beans = 0;
int button17beans = 0;
int button18beans = 0;
int button19beans = 0;
int button20beans = 0;
int button21beans = 0;
int button22beans = 0;
int button23beans = 0;
int button24beans = 0;

//1

int button25beans = 0;
int button26beans = 0;
int button27beans = 0;
int button28beans = 0;
int button29beans = 0;
int button30beans = 0;
int button31beans = 0;
int button32beans = 0;
int button33beans = 0;
int button34beans = 0;
int button35beans = 0;
int button36beans = 0;

//2

int button37beans = 0;
int button38beans = 0;
int button39beans = 0;
int button40beans = 0;
int button41beans = 0;
int button42beans = 0;
int button43beans = 0;
int button44beans = 0;
int button45beans = 0;
int button46beans = 0;
int button47beans = 0;
int button48beans = 0;

//3

int button49beans = 0;
int button50beans = 0;
int button51beans = 0;
int button52beans = 0;
int button53beans = 0;
int button54beans = 0;
int button55beans = 0;
int button56beans = 0;



//Grosse

int button1state = 0; //these state values help us only sendmidi commands once for every button put
int button2state = 0; //bear in mind this will only be a problem if you plan on having lots of midi things going on at once
int button3state = 0; //it just stops clogging up the midi feed with constant midi off commands.
int button4state = 0; //as themore keys you send the more midi off commands are constantly being sent
int button5state = 0; //so this just neatens the midi stream a bit to prevent mistakes. 
int button6state = 0;
int button7state = 0;
int button8state = 0;
int button9state = 0;
int button10state = 0;
int button11state = 0;
int button12state = 0;

//0 Okt.

int button13state = 0;
int button14state = 0;
int button15state = 0;
int button16state = 0;
int button17state = 0;
int button18state = 0;
int button19state = 0;
int button20state = 0;
int button21state = 0;
int button22state = 0;
int button23state = 0;
int button24state = 0;

//1

int button25state = 0;
int button26state = 0;
int button27state = 0;
int button28state = 0;
int button29state = 0;
int button30state = 0;
int button31state = 0;
int button32state = 0;
int button33state = 0;
int button34state = 0;
int button35state = 0;
int button36state = 0;

//2

int button37state = 0;
int button38state = 0;
int button39state = 0;
int button40state = 0;
int button41state = 0;
int button42state = 0;
int button43state = 0;
int button44state = 0;
int button45state = 0;
int button46state = 0;
int button47state = 0;
int button48state = 0;

//3

int button49state = 0;
int button50state = 0;
int button51state = 0;
int button52state = 0;
int button53state = 0;
int button54state = 0;
int button55state = 0;
int button56state = 0;



void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);  //BEINNINFG IDIU TGHUBGS

  pinMode(button1, INPUT_PULLUP);   
  pinMode(button2, INPUT_PULLUP);   
  pinMode(button3, INPUT_PULLUP);   
  pinMode(button4, INPUT_PULLUP);   
  pinMode(button5, INPUT_PULLUP);   
  pinMode(button6, INPUT_PULLUP);   
  pinMode(button7, INPUT_PULLUP);   
  pinMode(button8, INPUT_PULLUP);   
  pinMode(button9, INPUT_PULLUP);  
  pinMode(button10, INPUT_PULLUP);  
  pinMode(button11, INPUT_PULLUP);
  pinMode(button12, INPUT_PULLUP); 

  pinMode(button13, INPUT_PULLUP);   
  pinMode(button14, INPUT_PULLUP);   
  pinMode(button15, INPUT_PULLUP);   
  pinMode(button16, INPUT_PULLUP);   
  pinMode(button17, INPUT_PULLUP);   
  pinMode(button18, INPUT_PULLUP);   
  pinMode(button19, INPUT_PULLUP);   
  pinMode(button20, INPUT_PULLUP);   
  pinMode(button21, INPUT_PULLUP);  
  pinMode(button22, INPUT_PULLUP);  
  pinMode(button23, INPUT_PULLUP);
  pinMode(button24, INPUT_PULLUP); 

  pinMode(button25, INPUT_PULLUP);   
  pinMode(button26, INPUT_PULLUP);   
  pinMode(button27, INPUT_PULLUP);   
  pinMode(button28, INPUT_PULLUP);   
  pinMode(button29, INPUT_PULLUP);   
  pinMode(button30, INPUT_PULLUP);   
  pinMode(button31, INPUT_PULLUP);   
  pinMode(button32, INPUT_PULLUP);   
  pinMode(button33, INPUT_PULLUP);  
  pinMode(button34, INPUT_PULLUP);  
  pinMode(button35, INPUT_PULLUP);
  pinMode(button36, INPUT_PULLUP); 

  pinMode(button37, INPUT_PULLUP);   
  pinMode(button38, INPUT_PULLUP);   
  pinMode(button39, INPUT_PULLUP);   
  pinMode(button40, INPUT_PULLUP);   
  pinMode(button41, INPUT_PULLUP);   
  pinMode(button42, INPUT_PULLUP);   
  pinMode(button43, INPUT_PULLUP);   
  pinMode(button44, INPUT_PULLUP);   
  pinMode(button45, INPUT_PULLUP);  
  pinMode(button46, INPUT_PULLUP);  
  pinMode(button47, INPUT_PULLUP);
  pinMode(button48, INPUT_PULLUP); 

  pinMode(button49, INPUT_PULLUP);   
  pinMode(button50, INPUT_PULLUP);   
  pinMode(button51, INPUT_PULLUP);   
  pinMode(button52, INPUT_PULLUP);   
  pinMode(button53, INPUT_PULLUP);   
  pinMode(button54, INPUT_PULLUP);   
  pinMode(button55, INPUT_PULLUP);   
  pinMode(button56, INPUT_PULLUP);  
 

}

void loop() {

  button1beans = digitalRead(button1); 
  button2beans = digitalRead(button2); 
  button3beans = digitalRead(button3); 
  button4beans = digitalRead(button4); 
  button5beans = digitalRead(button5); 
  button6beans = digitalRead(button6); 
  button7beans = digitalRead(button7); 
  button8beans = digitalRead(button8); 
  button9beans = digitalRead(button9); 
  button10beans = digitalRead(button10); 
  button11beans = digitalRead(button11); 
  button12beans = digitalRead(button12); 

  button13beans = digitalRead(button13); 
  button14beans = digitalRead(button14); 
  button15beans = digitalRead(button15); 
  button16beans = digitalRead(button16); 
  button17beans = digitalRead(button17); 
  button18beans = digitalRead(button18); 
  button19beans = digitalRead(button19); 
  button20beans = digitalRead(button20); 
  button21beans = digitalRead(button21); 
  button22beans = digitalRead(button22); 
  button23beans = digitalRead(button23); 
  button24beans = digitalRead(button24); 
 
  button25beans = digitalRead(button25); 
  button26beans = digitalRead(button26); 
  button27beans = digitalRead(button27); 
  button28beans = digitalRead(button28); 
  button29beans = digitalRead(button29); 
  button30beans = digitalRead(button30); 
  button31beans = digitalRead(button31); 
  button32beans = digitalRead(button32); 
  button33beans = digitalRead(button33); 
  button34beans = digitalRead(button34); 
  button35beans = digitalRead(button35); 
  button36beans = digitalRead(button36);

  button37beans = digitalRead(button37); 
  button38beans = digitalRead(button38); 
  button39beans = digitalRead(button39); 
  button40beans = digitalRead(button40); 
  button41beans = digitalRead(button41); 
  button42beans = digitalRead(button42); 
  button43beans = digitalRead(button43); 
  button44beans = digitalRead(button44); 
  button45beans = digitalRead(button45); 
  button46beans = digitalRead(button46); 
  button47beans = digitalRead(button47); 
  button48beans = digitalRead(button48); 

  button49beans = digitalRead(button49); 
  button50beans = digitalRead(button50); 
  button51beans = digitalRead(button51); 
  button52beans = digitalRead(button52); 
  button53beans = digitalRead(button53); 
  button54beans = digitalRead(button54); 
  button55beans = digitalRead(button55); 
  button56beans = digitalRead(button56); 

  //---------------------------------------

  if ((button1beans == LOW) && (button1state == 0))
  { MIDI.sendNoteOn(36,127,1); //turn midi note on 36 velocity 127, midi channel 1. 
    button1state = 1;}  
  if ((button1beans == HIGH) && (button1state == 1))
  { MIDI.sendNoteOff(36,0,1);  //turn midi note off 36 velocity 127, midi channel 1. 
    button1state = 0;
  }  


  if ((button2beans == LOW) && (button2state == 0))
  { MIDI.sendNoteOn(37,127,1); 
    button2state = 1;}  
  if ((button2beans == HIGH) && (button2state == 1))
  { MIDI.sendNoteOff(37,0,1); 
    button2state = 0;
  }  
  
  if ((button3beans == LOW) && (button3state == 0))
  { MIDI.sendNoteOn(38,127,1);
    button3state = 1;}  
  if ((button3beans == HIGH) && (button3state == 1))
  { MIDI.sendNoteOff(38,0,1); 
    button3state = 0;
  }  
  
  if ((button4beans == LOW) && (button4state == 0))
  { MIDI.sendNoteOn(39,127,1);
    button4state = 1;}  
  if ((button4beans == HIGH) && (button4state == 1))
  { MIDI.sendNoteOff(39,0,1); 
    button4state = 0;
  }  
  
  if ((button5beans == LOW) && (button5state == 0))
  { MIDI.sendNoteOn(40,127,1); 
    button5state = 1;}  
  if ((button5beans == HIGH) && (button5state == 1))
  { MIDI.sendNoteOff(40,0,1);  
    button5state = 0;
  }  
  
  if ((button6beans == LOW) && (button6state == 0))
  { MIDI.sendNoteOn(41,127,1); 
    button6state = 1;}  
  if ((button6beans == HIGH) && (button6state == 1))
  { MIDI.sendNoteOff(41,0,1);  
    button6state = 0;
  }  
  
  if ((button7beans == LOW) && (button7state == 0))
  { MIDI.sendNoteOn(42,127,1); 
    button7state = 1;}  
  if ((button7beans == HIGH) && (button7state == 1))
  { MIDI.sendNoteOff(42,0,1);   
    button7state = 0;
  }  
  
  if ((button8beans == LOW) && (button8state == 0))
  { MIDI.sendNoteOn(43,127,1); 
    button8state = 1;}  
  if ((button8beans == HIGH) && (button8state == 1))
  { MIDI.sendNoteOff(43,0,1);  
    button8state = 0;
  }  
  
  if ((button9beans == LOW) && (button9state == 0))
  { MIDI.sendNoteOn(44,127,1); 
    button9state = 1;}  
  if ((button9beans == HIGH) && (button9state == 1))
  { MIDI.sendNoteOff(44,0,1);   
    button9state = 0;
  }  

  if ((button10beans == LOW) && (button10state == 0))
  { MIDI.sendNoteOn(45,127,1); 
    button10state = 1;}  
  if ((button10beans == HIGH) && (button10state == 1))
  { MIDI.sendNoteOff(45,0,1);  
    button10state = 0;
  } 
  
  if ((button11beans == LOW) && (button11state == 0))
  { MIDI.sendNoteOn(46,127,1); 
    button11state = 1;}  
  if ((button11beans == HIGH) && (button11state == 1))
  { MIDI.sendNoteOff(46,0,1);  
    button11state = 0;
  }   
 
  if ((button12beans == LOW) && (button12state == 0))
  { MIDI.sendNoteOn(47,127,1);  
    button12state = 1;}  
  if ((button12beans == HIGH) && (button12state == 1))
  { MIDI.sendNoteOff(47,0,1);  
    button11state = 0;
  }  
  
  //------------- O Oktave
 if ((button13beans == LOW) && (button13state == 0))
  { MIDI.sendNoteOn(48,127,1); //turn midi note on 36 velocity 127, midi channel 1. 
    button13state = 1;}  
  if ((button1beans == HIGH) && (button13state == 1))
  { MIDI.sendNoteOff(48,0,1);  //turn midi note off 36 velocity 127, midi channel 1. 
    button13state = 0;
  }  


  if ((button14beans == LOW) && (button14state == 0))
  { MIDI.sendNoteOn(49,127,1); 
    button14state = 1;}  
  if ((button14beans == HIGH) && (button14state == 1))
  { MIDI.sendNoteOff(49,0,1); 
    button14state = 0;
  }  
  
  if ((button15beans == LOW) && (button15state == 0))
  { MIDI.sendNoteOn(50,127,1);
    button15state = 1;}  
  if ((button15beans == HIGH) && (button15state == 1))
  { MIDI.sendNoteOff(50,0,1); 
    button15state = 0;
  }  
  
  if ((button16beans == LOW) && (button16state == 0))
  { MIDI.sendNoteOn(51,127,1);
    button16state = 1;}  
  if ((button16beans == HIGH) && (button16state == 1))
  { MIDI.sendNoteOff(51,0,1); 
    button16state = 0;
  }  
  
  if ((button17beans == LOW) && (button17state == 0))
  { MIDI.sendNoteOn(52,127,1); 
    button17state = 1;}  
  if ((button17beans == HIGH) && (button17state == 1))
  { MIDI.sendNoteOff(52,0,1);  
    button17state = 0;
  }  
  
  if ((button18beans == LOW) && (button18state == 0))
  { MIDI.sendNoteOn(53,127,1); 
    button18state = 1;}  
  if ((button18beans == HIGH) && (button18state == 1))
  { MIDI.sendNoteOff(53,0,1);  
    button18state = 0;
  }  
  
  if ((button19beans == LOW) && (button19state == 0))
  { MIDI.sendNoteOn(54,127,1); 
    button19state = 1;}  
  if ((button19beans == HIGH) && (button19state == 1))
  { MIDI.sendNoteOff(54,0,1);   
    button19state = 0;
  }  
  
  if ((button20beans == LOW) && (button20state == 0))
  { MIDI.sendNoteOn(55,127,1); 
    button20state = 1;}  
  if ((button20beans == HIGH) && (button20state == 1))
  { MIDI.sendNoteOff(55,0,1);  
    button20state = 0;
  }  
  
  if ((button21beans == LOW) && (button21state == 0))
  { MIDI.sendNoteOn(56,127,1); 
    button21state = 1;}  
  if ((button21beans == HIGH) && (button21state == 1))
  { MIDI.sendNoteOff(56,0,1);   
    button21state = 0;
  }  

  if ((button10beans == LOW) && (button10state == 0))
  { MIDI.sendNoteOn(45,127,1); 
    button10state = 1;}  
  if ((button10beans == HIGH) && (button10state == 1))
  { MIDI.sendNoteOff(45,0,1);  
    button10state = 0;
  } 
  
  if ((button11beans == LOW) && (button11state == 0))
  { MIDI.sendNoteOn(46,127,1); 
    button11state = 1;}  
  if ((button11beans == HIGH) && (button11state == 1))
  { MIDI.sendNoteOff(46,0,1);  
    button11state = 0;
  }   
 
  if ((button12beans == LOW) && (button12state == 0))
  { MIDI.sendNoteOn(47,127,1);  
    button12state = 1;}  
  if ((button12beans == HIGH) && (button12state == 1))
  { MIDI.sendNoteOff(47,0,1);  
    button11state = 0;
  }  

  //------- eingestrichen

   if ((button1beans == LOW) && (button1state == 0))
  { MIDI.sendNoteOn(36,127,1); //turn midi note on 36 velocity 127, midi channel 1. 
    button1state = 1;}  
  if ((button1beans == HIGH) && (button1state == 1))
  { MIDI.sendNoteOff(36,0,1);  //turn midi note off 36 velocity 127, midi channel 1. 
    button1state = 0;
  }  


  if ((button2beans == LOW) && (button2state == 0))
  { MIDI.sendNoteOn(37,127,1); 
    button2state = 1;}  
  if ((button2beans == HIGH) && (button2state == 1))
  { MIDI.sendNoteOff(37,0,1); 
    button2state = 0;
  }  
  
  if ((button3beans == LOW) && (button3state == 0))
  { MIDI.sendNoteOn(38,127,1);
    button3state = 1;}  
  if ((button3beans == HIGH) && (button3state == 1))
  { MIDI.sendNoteOff(38,0,1); 
    button3state = 0;
  }  
  
  if ((button4beans == LOW) && (button4state == 0))
  { MIDI.sendNoteOn(39,127,1);
    button4state = 1;}  
  if ((button4beans == HIGH) && (button4state == 1))
  { MIDI.sendNoteOff(39,0,1); 
    button4state = 0;
  }  
  
  if ((button5beans == LOW) && (button5state == 0))
  { MIDI.sendNoteOn(40,127,1); 
    button5state = 1;}  
  if ((button5beans == HIGH) && (button5state == 1))
  { MIDI.sendNoteOff(40,0,1);  
    button5state = 0;
  }  
  
  if ((button6beans == LOW) && (button6state == 0))
  { MIDI.sendNoteOn(41,127,1); 
    button6state = 1;}  
  if ((button6beans == HIGH) && (button6state == 1))
  { MIDI.sendNoteOff(41,0,1);  
    button6state = 0;
  }  
  
  if ((button7beans == LOW) && (button7state == 0))
  { MIDI.sendNoteOn(42,127,1); 
    button7state = 1;}  
  if ((button7beans == HIGH) && (button7state == 1))
  { MIDI.sendNoteOff(42,0,1);   
    button7state = 0;
  }  
  
  if ((button8beans == LOW) && (button8state == 0))
  { MIDI.sendNoteOn(43,127,1); 
    button8state = 1;}  
  if ((button8beans == HIGH) && (button8state == 1))
  { MIDI.sendNoteOff(43,0,1);  
    button8state = 0;
  }  
  
  if ((button9beans == LOW) && (button9state == 0))
  { MIDI.sendNoteOn(44,127,1); 
    button9state = 1;}  
  if ((button9beans == HIGH) && (button9state == 1))
  { MIDI.sendNoteOff(44,0,1);   
    button9state = 0;
  }  

  if ((button10beans == LOW) && (button10state == 0))
  { MIDI.sendNoteOn(45,127,1); 
    button10state = 1;}  
  if ((button10beans == HIGH) && (button10state == 1))
  { MIDI.sendNoteOff(45,0,1);  
    button10state = 0;
  } 
  
  if ((button11beans == LOW) && (button11state == 0))
  { MIDI.sendNoteOn(46,127,1); 
    button11state = 1;}  
  if ((button11beans == HIGH) && (button11state == 1))
  { MIDI.sendNoteOff(46,0,1);  
    button11state = 0;
  }   
 
  if ((button12beans == LOW) && (button12state == 0))
  { MIDI.sendNoteOn(47,127,1);  
    button12state = 1;}  
  if ((button12beans == HIGH) && (button12state == 1))
  { MIDI.sendNoteOff(47,0,1);  
    button11state = 0;
  }  

  //------- zweigestrichen

   if ((button1beans == LOW) && (button1state == 0))
  { MIDI.sendNoteOn(36,127,1); //turn midi note on 36 velocity 127, midi channel 1. 
    button1state = 1;}  
  if ((button1beans == HIGH) && (button1state == 1))
  { MIDI.sendNoteOff(36,0,1);  //turn midi note off 36 velocity 127, midi channel 1. 
    button1state = 0;
  }  


  if ((button2beans == LOW) && (button2state == 0))
  { MIDI.sendNoteOn(37,127,1); 
    button2state = 1;}  
  if ((button2beans == HIGH) && (button2state == 1))
  { MIDI.sendNoteOff(37,0,1); 
    button2state = 0;
  }  
  
  if ((button3beans == LOW) && (button3state == 0))
  { MIDI.sendNoteOn(38,127,1);
    button3state = 1;}  
  if ((button3beans == HIGH) && (button3state == 1))
  { MIDI.sendNoteOff(38,0,1); 
    button3state = 0;
  }  
  
  if ((button4beans == LOW) && (button4state == 0))
  { MIDI.sendNoteOn(39,127,1);
    button4state = 1;}  
  if ((button4beans == HIGH) && (button4state == 1))
  { MIDI.sendNoteOff(39,0,1); 
    button4state = 0;
  }  
  
  if ((button5beans == LOW) && (button5state == 0))
  { MIDI.sendNoteOn(40,127,1); 
    button5state = 1;}  
  if ((button5beans == HIGH) && (button5state == 1))
  { MIDI.sendNoteOff(40,0,1);  
    button5state = 0;
  }  
  
  if ((button6beans == LOW) && (button6state == 0))
  { MIDI.sendNoteOn(41,127,1); 
    button6state = 1;}  
  if ((button6beans == HIGH) && (button6state == 1))
  { MIDI.sendNoteOff(41,0,1);  
    button6state = 0;
  }  
  
  if ((button7beans == LOW) && (button7state == 0))
  { MIDI.sendNoteOn(42,127,1); 
    button7state = 1;}  
  if ((button7beans == HIGH) && (button7state == 1))
  { MIDI.sendNoteOff(42,0,1);   
    button7state = 0;
  }  
  
  if ((button8beans == LOW) && (button8state == 0))
  { MIDI.sendNoteOn(43,127,1); 
    button8state = 1;}  
  if ((button8beans == HIGH) && (button8state == 1))
  { MIDI.sendNoteOff(43,0,1);  
    button8state = 0;
  }  
  
  if ((button9beans == LOW) && (button9state == 0))
  { MIDI.sendNoteOn(44,127,1); 
    button9state = 1;}  
  if ((button9beans == HIGH) && (button9state == 1))
  { MIDI.sendNoteOff(44,0,1);   
    button9state = 0;
  }  

  if ((button10beans == LOW) && (button10state == 0))
  { MIDI.sendNoteOn(45,127,1); 
    button10state = 1;}  
  if ((button10beans == HIGH) && (button10state == 1))
  { MIDI.sendNoteOff(45,0,1);  
    button10state = 0;
  } 
  
  if ((button11beans == LOW) && (button11state == 0))
  { MIDI.sendNoteOn(46,127,1); 
    button11state = 1;}  
  if ((button11beans == HIGH) && (button11state == 1))
  { MIDI.sendNoteOff(46,0,1);  
    button11state = 0;
  }   
 
  if ((button12beans == LOW) && (button12state == 0))
  { MIDI.sendNoteOn(47,127,1);  
    button12state = 1;}  
  if ((button12beans == HIGH) && (button12state == 1))
  { MIDI.sendNoteOff(47,0,1);  
    button11state = 0;
  }  

  //_-------- dreigestrichen

   if ((button1beans == LOW) && (button1state == 0))
  { MIDI.sendNoteOn(36,127,1); //turn midi note on 36 velocity 127, midi channel 1. 
    button1state = 1;}  
  if ((button1beans == HIGH) && (button1state == 1))
  { MIDI.sendNoteOff(36,0,1);  //turn midi note off 36 velocity 127, midi channel 1. 
    button1state = 0;
  }  


  if ((button2beans == LOW) && (button2state == 0))
  { MIDI.sendNoteOn(37,127,1); 
    button2state = 1;}  
  if ((button2beans == HIGH) && (button2state == 1))
  { MIDI.sendNoteOff(37,0,1); 
    button2state = 0;
  }  
  
  if ((button3beans == LOW) && (button3state == 0))
  { MIDI.sendNoteOn(38,127,1);
    button3state = 1;}  
  if ((button3beans == HIGH) && (button3state == 1))
  { MIDI.sendNoteOff(38,0,1); 
    button3state = 0;
  }  
  
  if ((button4beans == LOW) && (button4state == 0))
  { MIDI.sendNoteOn(39,127,1);
    button4state = 1;}  
  if ((button4beans == HIGH) && (button4state == 1))
  { MIDI.sendNoteOff(39,0,1); 
    button4state = 0;
  }  
  
  if ((button5beans == LOW) && (button5state == 0))
  { MIDI.sendNoteOn(40,127,1); 
    button5state = 1;}  
  if ((button5beans == HIGH) && (button5state == 1))
  { MIDI.sendNoteOff(40,0,1);  
    button5state = 0;
  }  
  
  if ((button6beans == LOW) && (button6state == 0))
  { MIDI.sendNoteOn(41,127,1); 
    button6state = 1;}  
  if ((button6beans == HIGH) && (button6state == 1))
  { MIDI.sendNoteOff(41,0,1);  
    button6state = 0;
  }  
  
  if ((button7beans == LOW) && (button7state == 0))
  { MIDI.sendNoteOn(42,127,1); 
    button7state = 1;}  
  if ((button7beans == HIGH) && (button7state == 1))
  { MIDI.sendNoteOff(42,0,1);   
    button7state = 0;
  }  
  
  if ((button8beans == LOW) && (button8state == 0))
  { MIDI.sendNoteOn(43,127,1); 
    button8state = 1;}  
  if ((button8beans == HIGH) && (button8state == 1))
  { MIDI.sendNoteOff(43,0,1);  
    button8state = 0;
  }  
  
  if ((button9beans == LOW) && (button9state == 0))
  { MIDI.sendNoteOn(44,127,1); 
    button9state = 1;}  
  if ((button9beans == HIGH) && (button9state == 1))
  { MIDI.sendNoteOff(44,0,1);   
    button9state = 0;
  }  

  if ((button10beans == LOW) && (button10state == 0))
  { MIDI.sendNoteOn(45,127,1); 
    button10state = 1;}  
  if ((button10beans == HIGH) && (button10state == 1))
  { MIDI.sendNoteOff(45,0,1);  
    button10state = 0;
  } 
  
  if ((button11beans == LOW) && (button11state == 0))
  { MIDI.sendNoteOn(46,127,1); 
    button11state = 1;}  
  if ((button11beans == HIGH) && (button11state == 1))
  { MIDI.sendNoteOff(46,0,1);  
    button11state = 0;
  }   
 
  if ((button12beans == LOW) && (button12state == 0))
  { MIDI.sendNoteOn(47,127,1);  
    button12state = 1;}  
  if ((button12beans == HIGH) && (button12state == 1))
  { MIDI.sendNoteOff(47,0,1);  
    button11state = 0;
  }  

  }
