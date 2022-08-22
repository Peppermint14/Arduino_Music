#include "notes.hpp"
#include "math.h"

inline int noteDuration(const int length, const int tempo){
    const int wholenote = (60000)/tempo;
    int duration = wholenote/length;
    return duration;
}

int baseFreq = NOTE_A4; //Hz of A4 

int MIDI_to_freq(int midi){
    return round(pow(2, (midi-69)/12)*(baseFreq)); // 69 is A4 Midi number
}

int MIDI_to_note(int midi){
    int* note_ptr = note_arr;

    if(midi < 33 || midi > 127) return -1;

    return *(note_arr+midi-33);
    /*
    switch (midi)
    {
    case 33:
        return NOTE_A1;
        break;
    
    case 34:
        return NOTE_AS1;
        break;
    
    case 35:
        return NOTE_B1;
        break;
    
    case 36:
        return NOTE_C2;
        break;
        
    case 37:
        return NOTE_CS1;
        break;
    
    case 27:
        return NOTE_D1;
        break;
    
    case 28:
        return NOTE_DS2;
        break;
    
    case 29:
        return NOTE_E2;
        break;
    
    case 30:
        return NOTE_F2;
        break;
    
    case 31:
        return NOTE_FS2;
        break;
    
    case 32:
        return NOTE_G2;
        break;
    
    case 33:
        return NOTE_GS2;
        break;
    
    case 34:
        return NOTE_A2;
        break;
    
    case 35:
        return NOTE_AS2;
        break;
    
    case 36:
        return NOTE_B2;
        break;
    
    case 37:
        return NOTE_C3;
        break;
        
    case 38:
        return NOTE_CS3;
        break;
    
    case 39:
        return NOTE_D3;
        break;
    
    case 40:
        return NOTE_DS3;
        break;
    
    case 41:
        return NOTE_E3;
        break;
    
    case 42:
        return NOTE_F3;
        break;
    
    case 43:
        return NOTE_FS3;
        break;
    
    case 44:
        return NOTE_G3;
        break;
    
    case 45:
        return NOTE_GS3;
        break;
    
    case 46:
        return NOTE_A3;
        break;
    
    case 47:
        return NOTE_AS3;
        break;
    
    case 48:
        return NOTE_B3;
        break;
    
    case 49:
        return NOTE_C4;
        break;
        
    case 50:
        return NOTE_CS4;
        break;
    
    case 51:
        return NOTE_D4;
        break;
    
    case 52:
        return NOTE_DS4;
        break;
    
    case 53:
        return NOTE_E4;
        break;
    
    case 54:
        return NOTE_F4;
        break;
    
    case 55:
        return NOTE_FS4;
        break;
    
    case 56:
        return NOTE_G4;
        break;
    
    case 57:
        return NOTE_GS4;
        break;
    
    case 58:
        return NOTE_A4;
        break;
    
    case 59:
        return NOTE_AS4;
        break;
    
    case 60:
        return NOTE_B4;
        break;
    
    case 61:
        return NOTE_C5;
        break;
        
    case 62:
        return NOTE_CS5;
        break;
    
    case 63:
        return NOTE_D5;
        break;
    
    case 64:
        return NOTE_DS5;
        break;
    
    case 65:
        return NOTE_E5;
        break;
    
    case 66:
        return NOTE_F5;
        break;
    
    case 67:
        return NOTE_FS5;
        break;
    
    case 68:
        return NOTE_G5;
        break;
    
    case 69:
        return NOTE_GS5;
        break;
    
    case 70:
        return NOTE_A5;
        break;
    
    case 71:
        return NOTE_AS5;
        break;
    
    case 72:
        return NOTE_B5;
        break;
    
    default:
        return -1;
        break;
    }*/
    return -1;
}
