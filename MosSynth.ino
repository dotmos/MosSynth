/*
 * TODO:
 * Frequency: Multitude of frequency (0.25, 0.5, 1, 2, 3, 4) - Coarse
 * Frequency: Detune (0-100Hz?) - Fine
 * Programs
 * Different algorithms (up to 4 operators per voice? Currently only 2)
 * custom waveforms
 * Pitch + pitch envelope?
 * Feedback loop
 * */

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

float midiNoteToFreq[127];

#include "Program.h"
#include "Voice.h"

// GUItool: begin automatically generated code
AudioSynthWaveform       modulator1;      //xy=91,36
AudioSynthWaveform       modulator2; //xy=91,72
AudioSynthWaveform       modulator3; //xy=92,105
AudioSynthWaveform       modulator4; //xy=92,140
AudioSynthWaveform       modulator5; //xy=93,176
AudioSynthWaveform       modulator6; //xy=95,211
AudioSynthWaveform       modulator10; //xy=96,377
AudioSynthWaveform       modulator11; //xy=97,413
AudioSynthWaveform       modulator7; //xy=98,245
AudioSynthWaveform       modulator12; //xy=98,447
AudioSynthWaveform       modulator8; //xy=100,280
AudioSynthWaveform       modulator9; //xy=101,339
AudioSynthWaveform       modulator15; //xy=104,576
AudioSynthWaveform       modulator13; //xy=107,503
AudioSynthWaveform       modulator16;  //xy=107,614
AudioSynthWaveform       modulator14; //xy=109,539
AudioEffectEnvelope      modulatorEnvelope1;      //xy=264,35
AudioEffectEnvelope      modulatorEnvelope2; //xy=264,71
AudioEffectEnvelope      modulatorEnvelope3; //xy=265,104
AudioEffectEnvelope      modulatorEnvelope4; //xy=265,139
AudioEffectEnvelope      modulatorEnvelope5; //xy=266,175
AudioEffectEnvelope      modulatorEnvelope6; //xy=268,210
AudioEffectEnvelope      modulatorEnvelope10; //xy=269,376
AudioEffectEnvelope      modulatorEnvelope11; //xy=270,412
AudioEffectEnvelope      modulatorEnvelope7; //xy=271,244
AudioEffectEnvelope      modulatorEnvelope12; //xy=271,446
AudioEffectEnvelope      modulatorEnvelope8; //xy=273,279
AudioEffectEnvelope      modulatorEnvelope9; //xy=274,338
AudioEffectEnvelope      modulatorEnvelope15; //xy=277,575
AudioEffectEnvelope      modulatorEnvelope13; //xy=280,502
AudioEffectEnvelope      modulatorEnvelope16; //xy=280,613
AudioEffectEnvelope      modulatorEnvelope14; //xy=282,538
AudioSynthWaveformModulated carrier1;       //xy=435,35
AudioSynthWaveformModulated carrier2; //xy=435,71
AudioSynthWaveformModulated carrier3; //xy=436,104
AudioSynthWaveformModulated carrier4; //xy=436,139
AudioSynthWaveformModulated carrier5; //xy=437,175
AudioSynthWaveformModulated carrier6; //xy=439,210
AudioSynthWaveformModulated carrier10; //xy=440,376
AudioSynthWaveformModulated carrier11; //xy=441,412
AudioSynthWaveformModulated carrier7; //xy=442,244
AudioSynthWaveformModulated carrier12; //xy=442,446
AudioSynthWaveformModulated carrier8; //xy=444,279
AudioSynthWaveformModulated carrier9; //xy=445,338
AudioSynthWaveformModulated carrier15; //xy=448,575
AudioSynthWaveformModulated carrier13; //xy=451,502
AudioSynthWaveformModulated carrier16; //xy=451,613
AudioSynthWaveformModulated carrier14; //xy=453,538
AudioEffectEnvelope      carrierEnvelope1;      //xy=600,35
AudioEffectEnvelope      carrierEnvelope2; //xy=600,71
AudioEffectEnvelope      carrierEnvelope3; //xy=601,104
AudioEffectEnvelope      carrierEnvelope4; //xy=601,139
AudioEffectEnvelope      carrierEnvelope5; //xy=602,175
AudioEffectEnvelope      carrierEnvelope6; //xy=604,210
AudioEffectEnvelope      carrierEnvelope10; //xy=605,376
AudioEffectEnvelope      carrierEnvelope11; //xy=606,412
AudioEffectEnvelope      carrierEnvelope7; //xy=607,244
AudioEffectEnvelope      carrierEnvelope12; //xy=607,446
AudioEffectEnvelope      carrierEnvelope8; //xy=609,279
AudioEffectEnvelope      carrierEnvelope9; //xy=610,338
AudioEffectEnvelope      carrierEnvelope15; //xy=613,575
AudioEffectEnvelope      carrierEnvelope13; //xy=616,502
AudioEffectEnvelope      carrierEnvelope16; //xy=616,613
AudioEffectEnvelope      carrierEnvelope14; //xy=618,538
AudioMixer4              mixer1;         //xy=767,98
AudioMixer4              mixer3;         //xy=772,397
AudioMixer4              mixer2;         //xy=775,217
AudioMixer4              mixer4;         //xy=781,571
AudioMixer4              mixer5;         //xy=941,316
AudioOutputI2S           i2s1;           //xy=1112,296
AudioConnection          patchCord1(modulator1, modulatorEnvelope1);
AudioConnection          patchCord2(modulator2, modulatorEnvelope2);
AudioConnection          patchCord3(modulator3, modulatorEnvelope3);
AudioConnection          patchCord4(modulator4, modulatorEnvelope4);
AudioConnection          patchCord5(modulator5, modulatorEnvelope5);
AudioConnection          patchCord6(modulator6, modulatorEnvelope6);
AudioConnection          patchCord7(modulator10, modulatorEnvelope10);
AudioConnection          patchCord8(modulator11, modulatorEnvelope11);
AudioConnection          patchCord9(modulator7, modulatorEnvelope7);
AudioConnection          patchCord10(modulator12, modulatorEnvelope12);
AudioConnection          patchCord11(modulator8, modulatorEnvelope8);
AudioConnection          patchCord12(modulator9, modulatorEnvelope9);
AudioConnection          patchCord13(modulator15, modulatorEnvelope15);
AudioConnection          patchCord14(modulator13, modulatorEnvelope13);
AudioConnection          patchCord15(modulator16, modulatorEnvelope16);
AudioConnection          patchCord16(modulator14, modulatorEnvelope14);
AudioConnection          patchCord17(modulatorEnvelope1, carrier1);
AudioConnection          patchCord18(modulatorEnvelope2, carrier2);
AudioConnection          patchCord19(modulatorEnvelope3, carrier3);
AudioConnection          patchCord20(modulatorEnvelope4, carrier4);
AudioConnection          patchCord21(modulatorEnvelope5, carrier5);
AudioConnection          patchCord22(modulatorEnvelope6, carrier6);
AudioConnection          patchCord23(modulatorEnvelope10, carrier10);
AudioConnection          patchCord24(modulatorEnvelope11, carrier11);
AudioConnection          patchCord25(modulatorEnvelope7, carrier7);
AudioConnection          patchCord26(modulatorEnvelope12, carrier12);
AudioConnection          patchCord27(modulatorEnvelope8, carrier8);
AudioConnection          patchCord28(modulatorEnvelope9, carrier9);
AudioConnection          patchCord29(modulatorEnvelope15, carrier15);
AudioConnection          patchCord30(modulatorEnvelope13, carrier13);
AudioConnection          patchCord31(modulatorEnvelope16, carrier16);
AudioConnection          patchCord32(modulatorEnvelope14, carrier14);
AudioConnection          patchCord33(carrier1, carrierEnvelope1);
AudioConnection          patchCord34(carrier2, carrierEnvelope2);
AudioConnection          patchCord35(carrier3, carrierEnvelope3);
AudioConnection          patchCord36(carrier4, carrierEnvelope4);
AudioConnection          patchCord37(carrier5, carrierEnvelope5);
AudioConnection          patchCord38(carrier6, carrierEnvelope6);
AudioConnection          patchCord39(carrier10, carrierEnvelope10);
AudioConnection          patchCord40(carrier11, carrierEnvelope11);
AudioConnection          patchCord41(carrier7, carrierEnvelope7);
AudioConnection          patchCord42(carrier12, carrierEnvelope12);
AudioConnection          patchCord43(carrier8, carrierEnvelope8);
AudioConnection          patchCord44(carrier9, carrierEnvelope9);
AudioConnection          patchCord45(carrier15, carrierEnvelope15);
AudioConnection          patchCord46(carrier13, carrierEnvelope13);
AudioConnection          patchCord47(carrier16, carrierEnvelope16);
AudioConnection          patchCord48(carrier14, carrierEnvelope14);
AudioConnection          patchCord49(carrierEnvelope1, 0, mixer1, 0);
AudioConnection          patchCord50(carrierEnvelope2, 0, mixer1, 1);
AudioConnection          patchCord51(carrierEnvelope3, 0, mixer1, 2);
AudioConnection          patchCord52(carrierEnvelope4, 0, mixer1, 3);
AudioConnection          patchCord53(carrierEnvelope5, 0, mixer2, 0);
AudioConnection          patchCord54(carrierEnvelope6, 0, mixer2, 1);
AudioConnection          patchCord55(carrierEnvelope10, 0, mixer3, 1);
AudioConnection          patchCord56(carrierEnvelope11, 0, mixer3, 2);
AudioConnection          patchCord57(carrierEnvelope7, 0, mixer2, 2);
AudioConnection          patchCord58(carrierEnvelope12, 0, mixer3, 3);
AudioConnection          patchCord59(carrierEnvelope8, 0, mixer2, 3);
AudioConnection          patchCord60(carrierEnvelope9, 0, mixer3, 0);
AudioConnection          patchCord61(carrierEnvelope15, 0, mixer4, 2);
AudioConnection          patchCord62(carrierEnvelope13, 0, mixer4, 0);
AudioConnection          patchCord63(carrierEnvelope16, 0, mixer4, 3);
AudioConnection          patchCord64(carrierEnvelope14, 0, mixer4, 1);
AudioConnection          patchCord65(mixer1, 0, mixer5, 0);
AudioConnection          patchCord66(mixer3, 0, mixer5, 2);
AudioConnection          patchCord67(mixer2, 0, mixer5, 1);
AudioConnection          patchCord68(mixer4, 0, mixer5, 3);
AudioConnection          patchCord69(mixer5, 0, i2s1, 0);
AudioConnection          patchCord70(mixer5, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1109,346
// GUItool: end automatically generated code







//testing stuff
byte waveformCarrier = WAVEFORM_SQUARE;
byte waveformMod = WAVEFORM_SQUARE;
float frequencyMulCarrier = 1;
float frequencyMulMod = 1;
bool changeMod = false;

#define VOICE_COUNT 16
int currentVoiceID=0;

Voice voice[16];

void setup() {
  // put your setup code here, to run once:

  //Setup midi pitch to frequency, based on 440Hz tuning
  for (int x = 0; x < 127; ++x)
  {
    midiNoteToFreq[x] = ((pow(2.0,(x-69.0)/12.0)) * 440.0);
  }
  
  //Give audio lib some memory
  AudioMemory(40);
  //AudioNoInterrupts();
  
  //enable output
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.25);
  sgtl5000_1.adcHighPassFilterDisable();  //reduce noise.  https://forum.pjrc.com/threads/27215-24-bit-audio-boards?p=78831&viewfull=1#post78831
  
  //output
  mixer1.gain(0, 0.25);
  mixer1.gain(1, 0.25);
  mixer1.gain(2, 0.25);
  mixer1.gain(3, 0.25);
  mixer2.gain(0, 0.25);
  mixer2.gain(1, 0.25);
  mixer2.gain(2, 0.25);
  mixer2.gain(3, 0.25);
  mixer3.gain(0, 0.25);
  mixer3.gain(1, 0.25);
  mixer3.gain(2, 0.25);
  mixer3.gain(3, 0.25);
  mixer4.gain(0, 0.25);
  mixer4.gain(1, 0.25);
  mixer4.gain(2, 0.25);
  mixer4.gain(3, 0.25);
  mixer5.gain(0, 0.25);
  mixer5.gain(1, 0.25);
  mixer5.gain(2, 0.25);
  mixer5.gain(3, 0.25);


  //Setup voices
  Program p = Program();
  voice[0].Setup(&modulator1, &modulatorEnvelope1, &carrier1, &carrierEnvelope1, &p);
  voice[1].Setup(&modulator2, &modulatorEnvelope2, &carrier2, &carrierEnvelope2, &p);
  voice[2].Setup(&modulator3, &modulatorEnvelope3, &carrier3, &carrierEnvelope3, &p);
  voice[3].Setup(&modulator4, &modulatorEnvelope4, &carrier4, &carrierEnvelope4, &p);
  voice[4].Setup(&modulator5, &modulatorEnvelope5, &carrier5, &carrierEnvelope5, &p);
  voice[5].Setup(&modulator6, &modulatorEnvelope6, &carrier6, &carrierEnvelope6, &p);
  voice[6].Setup(&modulator7, &modulatorEnvelope7, &carrier7, &carrierEnvelope7, &p);
  voice[7].Setup(&modulator8, &modulatorEnvelope8, &carrier8, &carrierEnvelope8, &p);
  voice[8].Setup(&modulator9, &modulatorEnvelope9, &carrier9, &carrierEnvelope9, &p);
  voice[9].Setup(&modulator10, &modulatorEnvelope10, &carrier10, &carrierEnvelope10, &p);
  voice[10].Setup(&modulator11, &modulatorEnvelope11, &carrier11, &carrierEnvelope11, &p);
  voice[11].Setup(&modulator12, &modulatorEnvelope12, &carrier12, &carrierEnvelope12, &p);
  voice[12].Setup(&modulator13, &modulatorEnvelope13, &carrier13, &carrierEnvelope13, &p);
  voice[13].Setup(&modulator14, &modulatorEnvelope14, &carrier14, &carrierEnvelope14, &p);
  voice[14].Setup(&modulator15, &modulatorEnvelope15, &carrier15, &carrierEnvelope15, &p);
  voice[15].Setup(&modulator16, &modulatorEnvelope16, &carrier16, &carrierEnvelope16, &p);

  //Setup usb midi
  usbMIDI.setHandleNoteOff(handleNoteOff);
  usbMIDI.setHandleNoteOn(handleNoteOn);
  usbMIDI.setHandleControlChange(handleControlChange);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  Serial.begin(9600);

  delay ( 100);
  Serial.println("Send R to print cpu and memory useage");
}

void loop() {
  usbMIDI.read();

  //Print cpu and memory useage on request
  if(Serial.available()){
    char c = Serial.read();
    if(c == 'r' || c == 'R'){
      Serial.print("all=");
    Serial.print(AudioProcessorUsage());
    Serial.print(",");
    Serial.print(AudioProcessorUsageMax());
    Serial.print("    ");
    Serial.print("Memory: ");
    Serial.print(AudioMemoryUsage());
    Serial.print(",");
    Serial.println(AudioMemoryUsageMax());
    }
  }
}




// -----------------------------------------------------------------------------

// This function will be automatically called when a NoteOn is received.
// It must be a void-returning function with the correct parameters,
// see documentation here:
// http://arduinomidilib.fortyseveneffects.com/a00022.html

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  if(velocity > 0){
    Serial.println(pitch);
    Serial.println(midiNoteToFreq[pitch]);
    // put your main code here, to run repeatedly:
    //sine_fm1.frequency(midiNoteToFreq[pitch]);

    /*
    modulator1.begin(1, (midiNoteToFreq[pitch]*frequencyMulCarrier), waveformCarrier);
    modulator1.phase(0);
    modulatorEnvelope1.noteOn();

    carrier1.begin(1, midiNoteToFreq[pitch]*frequencyMulMod, waveformMod);
    carrier1.phase(0);
    carrierEnvelope1.noteOn();
    */


    //Try to find a free voice
    //Note: This implementation results in pops/clicks as the voice might still be in the release phase
    for(int i=0; i<VOICE_COUNT; ++i){
      if(voice[i].IsPlaying() == false){
        voice[i].NoteOn(pitch, velocity/127.0);
        return;
      }
    }

    //Otherwise simply use the next voice in stack
    voice[currentVoiceID].NoteOn(pitch, velocity/127.0);
    currentVoiceID++;
    if(currentVoiceID >= VOICE_COUNT) currentVoiceID = 0;
    
    // Do whatever you want when a note is pressed.

    // Try to keep your callbacks short (no delays ect)
    // otherwise it would slow down the loop() and have a bad impact
    // on real-time performance.
  } else {
    handleNoteOff(channel, pitch, velocity);
  }
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  /*
    modulatorEnvelope1.noteOff();
    carrierEnvelope1.noteOff();
    */

    //Find voice with correct pitch and turn it off
    for(int i=0; i<VOICE_COUNT; ++i){
      if(voice[i].pitch == pitch){
        voice[i].NoteOff();
      }
    }
    
    // Do something when the note is released.
    // Note that NoteOn messages with 0 velocity are interpreted as NoteOffs.
}

void handleControlChange(byte channel, byte number, byte value)
{
  //Numbers:
  //21-28 = knobs
  //41-48 = sliders
  //7 = master slider
  //51-59 = buttons

  //Switch between carrier and modulator settings
  if(number == 59 && value == 127){
    changeMod = !changeMod;
  }

  if(number == 51 && value == 127){
    if(changeMod){
      waveformMod = WAVEFORM_SQUARE;  
    } else {
      waveformCarrier = WAVEFORM_SQUARE;
    }
  }
  else if(number == 52 && value == 127){
    if(changeMod){
      waveformMod = WAVEFORM_SAWTOOTH;  
    } else {
      waveformCarrier = WAVEFORM_SAWTOOTH;
    }
  }
  else if(number == 53 && value == 127){
    if(changeMod){
      waveformMod = WAVEFORM_SAWTOOTH_REVERSE;  
    } else {
      waveformCarrier = WAVEFORM_SAWTOOTH_REVERSE;
    }
  }
  else if(number == 54 && value == 127){
    if(changeMod){
      waveformMod = WAVEFORM_TRIANGLE;  
    } else {
      waveformCarrier = WAVEFORM_TRIANGLE;  
    }
  }
  else if(number == 55 && value == 127){
    if(changeMod){
      waveformMod = WAVEFORM_SINE;  
    } else{
      waveformCarrier = WAVEFORM_SINE;
    }
  }
  else if(number == 56 && value == 127){
    if(changeMod){
      waveformMod = WAVEFORM_PULSE;  
    } else {
      waveformCarrier = WAVEFORM_PULSE;
    }
  }

  else if(number == 7){
    if(changeMod){
      if(value == 0) frequencyMulMod = 0.25;
      else if(value == 1) frequencyMulMod = 0.5;
      else if(value == 2) frequencyMulMod = 1;
      else if(value == 3) frequencyMulMod = 1.5;
      else if(value == 4) frequencyMulMod = 2;
      else if(value == 5) frequencyMulMod = 2.5;
      else if(value == 6) frequencyMulMod = 3;
      else if(value == 7) frequencyMulMod = 3.5;
      else if(value == 8) frequencyMulMod = 4;  
    } else {
      if(value == 0) frequencyMulCarrier = 0.25;
      else if(value == 1) frequencyMulCarrier = 0.5;
      else if(value == 2) frequencyMulCarrier = 1;
      else if(value == 3) frequencyMulCarrier = 1.5;
      else if(value == 4) frequencyMulCarrier = 2;
      else if(value == 5) frequencyMulCarrier = 2.5;
      else if(value == 6) frequencyMulCarrier = 3;
      else if(value == 7) frequencyMulCarrier = 3.5;
      else if(value == 8) frequencyMulCarrier = 4;  
    }
    
  }

  else if(number == 41){
    if(changeMod){
      carrierEnvelope1.attack(value*2);  
    } else {
      modulatorEnvelope1.attack(value*2);  
    }
  }  else if(number == 42){
    if(changeMod){
      carrierEnvelope1.hold(value*2);
    } else {
      modulatorEnvelope1.hold(value*2);  
    }
  }  else if(number == 43){
    if(changeMod){
      carrierEnvelope1.decay(value*2);
    } else {
      modulatorEnvelope1.decay(value*2);  
    }
  }  else if(number == 44){
    if(changeMod){
      carrierEnvelope1.sustain((float)value/127.0);
    } else {
      modulatorEnvelope1.sustain((float)value/127.0);
    }
  }  else if(number == 45){
    if(changeMod){
      carrierEnvelope1.release(value*4);
    } else {
      modulatorEnvelope1.release(value*4);
    }
  }
}

// -----------------------------------------------------------------------------

