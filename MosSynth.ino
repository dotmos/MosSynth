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
AudioSynthWaveformModulated modulator1;     //xy=150,58
AudioSynthWaveformModulated modulator2;     //xy=150,94
AudioSynthWaveformModulated modulator3;     //xy=151,127
AudioSynthWaveformModulated modulator4;     //xy=151,162
AudioSynthWaveformModulated modulator5;     //xy=152,198
AudioSynthWaveformModulated modulator6;     //xy=154,233
AudioSynthWaveformModulated modulator10;    //xy=155,399
AudioSynthWaveformModulated modulator11;    //xy=156,435
AudioSynthWaveformModulated modulator7;     //xy=157,267
AudioSynthWaveformModulated modulator12;    //xy=157,469
AudioSynthWaveformModulated modulator8;     //xy=159,302
AudioSynthWaveformModulated modulator9;     //xy=160,361
AudioSynthWaveformModulated modulator13;    //xy=162,523
AudioSynthWaveformModulated modulator15;    //xy=163,598
AudioSynthWaveformModulated modulator18; //xy=164.5,729
AudioSynthWaveformModulated modulator16;    //xy=166,636
AudioSynthWaveformModulated modulator17; //xy=165.5,804
AudioSynthWaveformModulated modulator14;    //xy=168,561
AudioSynthWaveformModulated modulator19; //xy=168.5,842
AudioSynthWaveformModulated modulator20; //xy=170.5,767
AudioEffectEnvelope      modulatorEnvelope1; //xy=323,57
AudioEffectEnvelope      modulatorEnvelope2; //xy=323,93
AudioEffectEnvelope      modulatorEnvelope3; //xy=324,126
AudioEffectEnvelope      modulatorEnvelope4; //xy=324,161
AudioEffectEnvelope      modulatorEnvelope5; //xy=325,197
AudioEffectEnvelope      modulatorEnvelope6; //xy=327,232
AudioEffectEnvelope      modulatorEnvelope10; //xy=328,398
AudioEffectEnvelope      modulatorEnvelope11; //xy=329,434
AudioEffectEnvelope      modulatorEnvelope7; //xy=330,266
AudioEffectEnvelope      modulatorEnvelope12; //xy=330,468
AudioEffectEnvelope      modulatorEnvelope8; //xy=332,301
AudioEffectEnvelope      modulatorEnvelope9; //xy=333,360
AudioEffectEnvelope      modulatorEnvelope15; //xy=336,597
AudioEffectEnvelope      modulatorEnvelope13; //xy=339,524
AudioEffectEnvelope      modulatorEnvelope16; //xy=339,635
AudioEffectEnvelope      modulatorEnvelope17; //xy=338.5,803
AudioEffectEnvelope      modulatorEnvelope14; //xy=341,560
AudioEffectEnvelope      modulatorEnvelope18; //xy=341.5,730
AudioEffectEnvelope      modulatorEnvelope19; //xy=341.5,841
AudioEffectEnvelope      modulatorEnvelope20; //xy=343.5,766
AudioSynthWaveformModulated carrier1;       //xy=494,57
AudioSynthWaveformModulated carrier2;       //xy=494,93
AudioSynthWaveformModulated carrier3;       //xy=495,126
AudioSynthWaveformModulated carrier4;       //xy=495,161
AudioSynthWaveformModulated carrier5;       //xy=496,197
AudioSynthWaveformModulated carrier6;       //xy=498,232
AudioSynthWaveformModulated carrier10;      //xy=499,398
AudioSynthWaveformModulated carrier11;      //xy=500,434
AudioSynthWaveformModulated carrier7;       //xy=501,266
AudioSynthWaveformModulated carrier12;      //xy=501,468
AudioSynthWaveformModulated carrier8;       //xy=503,301
AudioSynthWaveformModulated carrier9;       //xy=504,360
AudioSynthWaveformModulated carrier15;      //xy=507,597
AudioSynthWaveformModulated carrier13;      //xy=510,524
AudioSynthWaveformModulated carrier16;      //xy=510,635
AudioSynthWaveformModulated carrier17; //xy=509.5,803
AudioSynthWaveformModulated carrier14;      //xy=512,560
AudioSynthWaveformModulated carrier18; //xy=512.5,730
AudioSynthWaveformModulated carrier19; //xy=512.5,841
AudioSynthWaveformModulated carrier20; //xy=514.5,766
AudioEffectEnvelope      carrierEnvelope1; //xy=659,57
AudioEffectEnvelope      carrierEnvelope2; //xy=659,93
AudioEffectEnvelope      carrierEnvelope3; //xy=660,126
AudioEffectEnvelope      carrierEnvelope4; //xy=660,161
AudioEffectEnvelope      carrierEnvelope5; //xy=661,197
AudioEffectEnvelope      carrierEnvelope6; //xy=663,232
AudioEffectEnvelope      carrierEnvelope10; //xy=664,398
AudioEffectEnvelope      carrierEnvelope11; //xy=665,434
AudioEffectEnvelope      carrierEnvelope7; //xy=666,266
AudioEffectEnvelope      carrierEnvelope12; //xy=666,468
AudioEffectEnvelope      carrierEnvelope8; //xy=668,301
AudioEffectEnvelope      carrierEnvelope9; //xy=669,360
AudioEffectEnvelope      carrierEnvelope15; //xy=672,597
AudioEffectEnvelope      carrierEnvelope13; //xy=675,524
AudioEffectEnvelope      carrierEnvelope16; //xy=675,635
AudioEffectEnvelope      carrierEnvelope17; //xy=674.5,803
AudioEffectEnvelope      carrierEnvelope14; //xy=677,560
AudioEffectEnvelope      carrierEnvelope18; //xy=677.5,730
AudioEffectEnvelope      carrierEnvelope19; //xy=677.5,841
AudioEffectEnvelope      carrierEnvelope20; //xy=679.5,766
AudioMixer4              mixer1;         //xy=826,120
AudioMixer4              mixer3;         //xy=831,419
AudioMixer4              mixer2;         //xy=834,239
AudioMixer4              mixer4;         //xy=840,593
AudioMixer4              mixer6; //xy=842.5,799
AudioMixer4              mixer5;         //xy=1000,338
AudioMixer4              mixerMaster;         //xy=1190,471
AudioOutputI2S           i2s1;           //xy=1347,437
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
AudioConnection          patchCord13(modulator13, modulatorEnvelope13);
AudioConnection          patchCord14(modulator15, modulatorEnvelope15);
AudioConnection          patchCord15(modulator18, modulatorEnvelope18);
AudioConnection          patchCord16(modulator16, modulatorEnvelope16);
AudioConnection          patchCord17(modulator17, modulatorEnvelope17);
AudioConnection          patchCord18(modulator14, modulatorEnvelope14);
AudioConnection          patchCord19(modulator19, modulatorEnvelope19);
AudioConnection          patchCord20(modulator20, modulatorEnvelope20);
AudioConnection          patchCord21(modulatorEnvelope1, 0, carrier1, 0);
AudioConnection          patchCord22(modulatorEnvelope2, 0, carrier2, 0);
AudioConnection          patchCord23(modulatorEnvelope3, 0, carrier3, 0);
AudioConnection          patchCord24(modulatorEnvelope4, 0, carrier4, 0);
AudioConnection          patchCord25(modulatorEnvelope5, 0, carrier5, 0);
AudioConnection          patchCord26(modulatorEnvelope6, 0, carrier6, 0);
AudioConnection          patchCord27(modulatorEnvelope10, 0, carrier10, 0);
AudioConnection          patchCord28(modulatorEnvelope11, 0, carrier11, 0);
AudioConnection          patchCord29(modulatorEnvelope7, 0, carrier7, 0);
AudioConnection          patchCord30(modulatorEnvelope12, 0, carrier12, 0);
AudioConnection          patchCord31(modulatorEnvelope8, 0, carrier8, 0);
AudioConnection          patchCord32(modulatorEnvelope9, 0, carrier9, 0);
AudioConnection          patchCord33(modulatorEnvelope15, 0, carrier15, 0);
AudioConnection          patchCord34(modulatorEnvelope13, 0, carrier13, 0);
AudioConnection          patchCord35(modulatorEnvelope16, 0, carrier16, 0);
AudioConnection          patchCord36(modulatorEnvelope17, 0, carrier17, 0);
AudioConnection          patchCord37(modulatorEnvelope14, 0, carrier14, 0);
AudioConnection          patchCord38(modulatorEnvelope18, 0, carrier18, 0);
AudioConnection          patchCord39(modulatorEnvelope19, 0, carrier19, 0);
AudioConnection          patchCord40(modulatorEnvelope20, 0, carrier20, 0);
AudioConnection          patchCord41(carrier1, carrierEnvelope1);
AudioConnection          patchCord42(carrier2, carrierEnvelope2);
AudioConnection          patchCord43(carrier3, carrierEnvelope3);
AudioConnection          patchCord44(carrier4, carrierEnvelope4);
AudioConnection          patchCord45(carrier5, carrierEnvelope5);
AudioConnection          patchCord46(carrier6, carrierEnvelope6);
AudioConnection          patchCord47(carrier10, carrierEnvelope10);
AudioConnection          patchCord48(carrier11, carrierEnvelope11);
AudioConnection          patchCord49(carrier7, carrierEnvelope7);
AudioConnection          patchCord50(carrier12, carrierEnvelope12);
AudioConnection          patchCord51(carrier8, carrierEnvelope8);
AudioConnection          patchCord52(carrier9, carrierEnvelope9);
AudioConnection          patchCord53(carrier15, carrierEnvelope15);
AudioConnection          patchCord54(carrier13, carrierEnvelope13);
AudioConnection          patchCord55(carrier16, carrierEnvelope16);
AudioConnection          patchCord56(carrier17, carrierEnvelope17);
AudioConnection          patchCord57(carrier14, carrierEnvelope14);
AudioConnection          patchCord58(carrier18, carrierEnvelope18);
AudioConnection          patchCord59(carrier19, carrierEnvelope19);
AudioConnection          patchCord60(carrier20, carrierEnvelope20);
AudioConnection          patchCord61(carrierEnvelope1, 0, mixer1, 0);
AudioConnection          patchCord62(carrierEnvelope2, 0, mixer1, 1);
AudioConnection          patchCord63(carrierEnvelope3, 0, mixer1, 2);
AudioConnection          patchCord64(carrierEnvelope4, 0, mixer1, 3);
AudioConnection          patchCord65(carrierEnvelope5, 0, mixer2, 0);
AudioConnection          patchCord66(carrierEnvelope6, 0, mixer2, 1);
AudioConnection          patchCord67(carrierEnvelope10, 0, mixer3, 1);
AudioConnection          patchCord68(carrierEnvelope11, 0, mixer3, 2);
AudioConnection          patchCord69(carrierEnvelope7, 0, mixer2, 2);
AudioConnection          patchCord70(carrierEnvelope12, 0, mixer3, 3);
AudioConnection          patchCord71(carrierEnvelope8, 0, mixer2, 3);
AudioConnection          patchCord72(carrierEnvelope9, 0, mixer3, 0);
AudioConnection          patchCord73(carrierEnvelope15, 0, mixer4, 2);
AudioConnection          patchCord74(carrierEnvelope13, 0, mixer4, 0);
AudioConnection          patchCord75(carrierEnvelope16, 0, mixer4, 3);
AudioConnection          patchCord76(carrierEnvelope17, 0, mixer6, 2);
AudioConnection          patchCord77(carrierEnvelope14, 0, mixer4, 1);
AudioConnection          patchCord78(carrierEnvelope18, 0, mixer6, 0);
AudioConnection          patchCord79(carrierEnvelope19, 0, mixer6, 3);
AudioConnection          patchCord80(carrierEnvelope20, 0, mixer6, 1);
AudioConnection          patchCord81(mixer1, 0, mixer5, 0);
AudioConnection          patchCord82(mixer3, 0, mixer5, 2);
AudioConnection          patchCord83(mixer2, 0, mixer5, 1);
AudioConnection          patchCord84(mixer4, 0, mixer5, 3);
AudioConnection          patchCord85(mixer6, 0, mixerMaster, 1);
AudioConnection          patchCord86(mixer5, 0, mixerMaster, 0);
AudioConnection          patchCord87(mixerMaster, 0, i2s1, 0);
AudioConnection          patchCord88(mixerMaster, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1344,487
// GUItool: end automatically generated code








//testing stuff
byte waveformCarrier = WAVEFORM_SQUARE;
byte waveformMod = WAVEFORM_SQUARE;
float frequencyMulCarrier = 1;
float frequencyMulMod = 1;
bool changeMod = false;

#define VOICE_COUNT 20
int currentVoiceID=0;

//All voices
Voice voice[VOICE_COUNT];

//Current channel programs
#define CHANNEL_COUNT 16
Program *channelProgram[CHANNEL_COUNT];

//Program bank nr 1. 128 programs per bank
#define PROGRAMS_PER_BANK 128
Program programBank1[PROGRAMS_PER_BANK];

void setup() {
  // put your setup code here, to run once:

  //Setup midi pitch to frequency, based on 440Hz tuning
  for (int x = 0; x < 127; ++x)
  {
    midiNoteToFreq[x] = ((pow(2.0,(x-69.0)/12.0)) * 440.0);
  }
  
  //Give audio lib some memory
  AudioMemory(64);
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
  mixer6.gain(0, 0.25);
  mixer6.gain(1, 0.25);
  mixer6.gain(2, 0.25);
  mixer6.gain(3, 0.25);
  mixerMaster.gain(0, 0.8);
  mixerMaster.gain(1, 0.2);
  mixerMaster.gain(2, 0);
  mixerMaster.gain(3, 0);

  //Create program bank 1
  for(int i=0; i<PROGRAMS_PER_BANK; ++i){
    programBank1[i] = Program();
  }
  
  //Setup channel programs
  Program *firstProgram = &programBank1[0];
  for(int i=0; i<CHANNEL_COUNT; ++i){
    channelProgram[i] = firstProgram;
  }

  //Create some unique programs
  //
  programBank1[1].SetWaveform(0, WAVEFORM_TRIANGLE);
  programBank1[1].SetFreqMul(0, 2.0);
  float _volumeDAHDSR0[6] = {0, 10, 0, 2000, 0.2, 700};
  programBank1[1].SetVolumeDAHDSR(0, _volumeDAHDSR0);
  programBank1[1].SetFreqAdd(0, 0);
  programBank1[1].SetOperatorVolume(0,0.2);
  programBank1[1].SetWaveform(1, WAVEFORM_SINE);
  programBank1[1].SetFreqMul(1, 1.0);
  float _volumeDAHDSR1[6] = {0, 10, 0, 100, 1, 700};
  programBank1[1].SetVolumeDAHDSR(1, _volumeDAHDSR1);
  programBank1[1].SetFreqAdd(1, 0);
  programBank1[1].SetOperatorVolume(1,1);

  //queek quaak ;)
  programBank1[2].SetWaveform(0, WAVEFORM_TRIANGLE);
  programBank1[2].SetFreqMul(0, 1);
  float _volumeDAHDSR2[6] = {0, 250, 0, 1500, 0.25, 1};
  programBank1[2].SetVolumeDAHDSR(0, _volumeDAHDSR2);
  programBank1[2].SetFreqAdd(0, 0);
  programBank1[2].SetOperatorVolume(0, 0.08);
  programBank1[2].SetWaveform(1, WAVEFORM_SINE);
  programBank1[2].SetFreqMul(1, 2);
  float _volumeDAHDSR3[6] = {0, 10, 0, 1500, 0.25, 1};
  programBank1[2].SetVolumeDAHDSR(1, _volumeDAHDSR3);
  programBank1[2].SetFreqAdd(1, 0);
  programBank1[2].SetOperatorVolume(1,1);

  //bass thingy
  programBank1[3].SetWaveform(0, WAVEFORM_SINE);
  programBank1[3].SetFreqMul(0, 0.5);
  float _volumeDAHDSR4[6] = {0, 100, 0, 100, 0.5, 10};
  programBank1[3].SetVolumeDAHDSR(0, _volumeDAHDSR4);
  programBank1[3].SetFreqAdd(0, 0);
  programBank1[3].SetOperatorVolume(0,1);
  programBank1[3].SetWaveform(1, WAVEFORM_SQUARE);
  programBank1[3].SetFreqMul(1, 1);
  float _volumeDAHDSR5[6] = {0, 10, 0, 50, 1, 50};
  programBank1[3].SetVolumeDAHDSR(1, _volumeDAHDSR5);
  programBank1[3].SetFreqAdd(1, 0);
  programBank1[3].SetOperatorVolume(1,0.5);

  //noisy lofi bass thingy
  programBank1[4].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[4].SetFreqMul(0, 1.0);
  float _volumeDAHDSR6[6] = {0, 1, 0, 300, 0.9, 250};
  programBank1[4].SetVolumeDAHDSR(0, _volumeDAHDSR6);
  programBank1[4].SetFreqAdd(0, 0.1);
  programBank1[4].SetOperatorVolume(0,1);
  programBank1[4].SetWaveform(1, WAVEFORM_SQUARE);
  programBank1[4].SetFreqMul(1, 1);
  float _volumeDAHDSR7[6] = {0, 10, 0, 30, 0.8, 100};
  programBank1[4].SetVolumeDAHDSR(1, _volumeDAHDSR7);
  programBank1[4].SetFreqAdd(1, 0);
  programBank1[4].SetOperatorVolume(1, 0.7);

  //bassy wasp thingy
  programBank1[5].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[5].SetFreqMul(0, 1);
  float _volumeDAHDSR8[6] = {0, 50, 0, 250, 0.5, 300};
  programBank1[5].SetVolumeDAHDSR(0, _volumeDAHDSR8);
  programBank1[5].SetFreqAdd(0, 0.1);
  programBank1[5].SetOperatorVolume(0, 0.90);
  programBank1[5].SetWaveform(1, WAVEFORM_SINE);
  programBank1[5].SetFreqMul(1, 1);
  float _volumeDAHDSR9[6] = {0, 10, 0, 10, 1, 300};
  programBank1[5].SetVolumeDAHDSR(1, _volumeDAHDSR9);
  programBank1[5].SetFreqAdd(1, 0);
  programBank1[5].SetOperatorVolume(1, 1.0);
  

  //Setup voices
  voice[0] = Voice(&modulator1, &modulatorEnvelope1, &carrier1, &carrierEnvelope1, firstProgram);
  voice[1] = Voice(&modulator2, &modulatorEnvelope2, &carrier2, &carrierEnvelope2, firstProgram);
  voice[2] = Voice(&modulator3, &modulatorEnvelope3, &carrier3, &carrierEnvelope3, firstProgram);
  voice[3] = Voice(&modulator4, &modulatorEnvelope4, &carrier4, &carrierEnvelope4, firstProgram);
  voice[4] = Voice(&modulator5, &modulatorEnvelope5, &carrier5, &carrierEnvelope5, firstProgram);
  voice[5] = Voice(&modulator6, &modulatorEnvelope6, &carrier6, &carrierEnvelope6, firstProgram);
  voice[6] = Voice(&modulator7, &modulatorEnvelope7, &carrier7, &carrierEnvelope7, firstProgram);
  voice[7] = Voice(&modulator8, &modulatorEnvelope8, &carrier8, &carrierEnvelope8, firstProgram);
  voice[8] = Voice(&modulator9, &modulatorEnvelope9, &carrier9, &carrierEnvelope9, firstProgram);
  voice[9] = Voice(&modulator10, &modulatorEnvelope10, &carrier10, &carrierEnvelope10, firstProgram);
  voice[10] = Voice(&modulator11, &modulatorEnvelope11, &carrier11, &carrierEnvelope11, firstProgram);
  voice[11] = Voice(&modulator12, &modulatorEnvelope12, &carrier12, &carrierEnvelope12, firstProgram);
  voice[12] = Voice(&modulator13, &modulatorEnvelope13, &carrier13, &carrierEnvelope13, firstProgram);
  voice[13] = Voice(&modulator14, &modulatorEnvelope14, &carrier14, &carrierEnvelope14, firstProgram);
  voice[14] = Voice(&modulator15, &modulatorEnvelope15, &carrier15, &carrierEnvelope15, firstProgram);
  voice[15] = Voice(&modulator16, &modulatorEnvelope16, &carrier16, &carrierEnvelope16, firstProgram);
  voice[16] = Voice(&modulator17, &modulatorEnvelope17, &carrier17, &carrierEnvelope17, firstProgram);
  voice[17] = Voice(&modulator18, &modulatorEnvelope18, &carrier18, &carrierEnvelope18, firstProgram);
  voice[18] = Voice(&modulator19, &modulatorEnvelope18, &carrier19, &carrierEnvelope19, firstProgram);
  voice[19] = Voice(&modulator20, &modulatorEnvelope20, &carrier20, &carrierEnvelope20, firstProgram);

  //Setup usb midi handlers
  usbMIDI.setHandleNoteOff(handleNoteOff);
  usbMIDI.setHandleNoteOn(handleNoteOn);
  usbMIDI.setHandleControlChange(handleControlChange);
  usbMIDI.setHandleProgramChange(handleProgramChange);
  

  

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
    Serial.print("/");
    Serial.print(AudioProcessorUsageMax());
    Serial.print("    ");
    Serial.print("Memory: ");
    Serial.print(AudioMemoryUsage());
    Serial.print("/");
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
    //Serial.println(pitch);
    //Serial.println(midiNoteToFreq[pitch]);
    // put your main code here, to run repeatedly:

    //Try to find a free voice
    //Note: This implementation results in pops/clicks as the voice might still be in the release phase
    for(int i=0; i<VOICE_COUNT; ++i){
      if(voice[i].IsPlaying() == false){
        voice[i].SetProgram(channelProgram[channel]);
        voice[i].NoteOn(channel, pitch, velocity/127.0);
        return;
      }
    }

    //Otherwise simply use the next voice in stack
    voice[currentVoiceID].SetProgram(channelProgram[channel]);
    voice[currentVoiceID].NoteOn(channel, pitch, velocity/127.0);
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
    //Find voice with correct pitch and turn it off
    for(int i=0; i<VOICE_COUNT; ++i){
      if(voice[i].channel == channel && voice[i].pitch == pitch){
        voice[i].NoteOff();
      }
    }
    
    // Do something when the note is released.
    // Note that NoteOn messages with 0 velocity are interpreted as NoteOffs.
}

//Set program for a channel
void handleProgramChange(byte channel, byte program){
  channelProgram[channel] = &programBank1[program];
}

//Handle control change (knobs, sliders, etc.). Not doing much at the moment
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

