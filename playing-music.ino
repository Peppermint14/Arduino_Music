#include "headers/notes.hpp"
#include "assert.h"

// #include <stdio.h>

// #include <ezButton.h>


short int piezzoPin = 10; //
short int buttonPin = 3;
const int onBoradLEDPin = 13;

// Serial baud rate
const int baudRate = 9600;


int onBoardLEDState = LOW;
const int Debounce_Delay = 100;
bool isPlaying;
int ButtonLastState;
int ButtonCurrentState;

int count;

void playMelody(int notes[], int notes_len, int duration[], int dur_len, int dots[], int dot_len){
    assert(notes_len == dur_len && dur_len == dot_len);
    int tempo = 144;

    for(int it = 0; it < notes_len; it++){
        int noteDur = noteDuration(duration[it], tempo); 
        playTone(piezzoPin, notes[it], noteDur);
    }
}

void playTone(const short int pin, const int note, const int duration){

}

void setup()
{
    Serial.begin(baudRate);
    Serial.print("test2134");

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    pinMode(buttonPin, INPUT);
    count = 0;
    isPlaying = false;
    ButtonLastState = digitalRead(buttonPin);

}

void loop()
{   
    // Recognizing Button Press
    ButtonLastState = ButtonCurrentState;
    ButtonCurrentState = digitalRead(buttonPin);
    if(ButtonCurrentState == LOW && ButtonCurrentState != ButtonLastState){
        Serial.println("LOW");
        digitalWrite(LED_BUILTIN, LOW);
        tone(piezzoPin,NOTE_C4, 100);
    }else if(ButtonCurrentState == HIGH && ButtonCurrentState != ButtonLastState){
        Serial.println("HIGH");
        digitalWrite(LED_BUILTIN, HIGH);
        tone(piezzoPin,NOTE_C6, 100);
    }
    delay(150);
}