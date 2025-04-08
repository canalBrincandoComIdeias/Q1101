/* 
  Hedwig's theme - Harry Potter 
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/
#include "notas.h"

// change this to make the song slower or faster
int tempo = 144;

// change this to whichever pin you want to use
int pinBuzzer = 9;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {


  // Hedwig's theme fromn the Harry Potter Movies
  // Socre from https://musescore.com/user/3811306/scores/4906610
  
  REST, 2, D4, 4,
  G4, -4, AS4, 8, A4, 4,
  G4, 2, D5, 4,
  C5, -2, 
  A4, -2,
  G4, -4, AS4, 8, A4, 4,
  F4, 2, GS4, 4,
  D4, -1, 
  D4, 4,

  G4, -4, AS4, 8, A4, 4, //10
  G4, 2, D5, 4,
  F5, 2, E5, 4,
  DS5, 2, B4, 4,
  DS5, -4, D5, 8, CS5, 4,
  CS4, 2, B4, 4,
  G4, -1,
  AS4, 4,
     
  D5, 2, AS4, 4,//18
  D5, 2, AS4, 4,
  DS5, 2, D5, 4,
  CS5, 2, A4, 4,
  AS4, -4, D5, 8, CS5, 4,
  CS4, 2, D4, 4,
  D5, -1, 
  REST,4, AS4,4,  

  D5, 2, AS4, 4,//26
  D5, 2, AS4, 4,
  F5, 2, E5, 4,
  DS5, 2, B4, 4,
  DS5, -4, D5, 8, CS5, 4,
  CS4, 2, AS4, 4,
  G4, -1, 
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  // iterate over the notes of the melody. 
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(pinBuzzer, melody[thisNote], noteDuration*0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    
    // stop the waveform generation before the next note.
    noTone(pinBuzzer);
  }
}

void loop() {
  // no need to repeat the melody.
}
