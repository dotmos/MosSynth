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

#define WAVESHAPE_SAMPLE_SIZE 17
#include "Program.h"
#include "Voice.h"

// GUItool: begin automatically generated code
AudioSynthWaveformModulated modulator1;     //xy=205,55
AudioSynthWaveformModulated modulator2;     //xy=205,91
AudioSynthWaveformModulated modulator3; //xy=206,126
AudioSynthWaveformModulated modulator4; //xy=208,162
AudioSynthWaveformModulated modulator5; //xy=210,214
AudioSynthWaveformModulated modulator6; //xy=210,249
AudioSynthWaveformModulated modulator7; //xy=210,283
AudioSynthWaveformModulated modulator8; //xy=214,318
AudioSynthWaveformModulated modulator10; //xy=217,423
AudioSynthWaveformModulated modulator9; //xy=218,387
AudioSynthWaveformModulated modulator11; //xy=218,457
AudioSynthWaveformModulated modulator12; //xy=218,492
AudioSynthWaveformModulated modulator13; //xy=220,563
AudioSynthWaveformModulated modulator14; //xy=223,602
AudioSynthWaveformModulated modulator15; //xy=223,638
AudioSynthWaveformModulated modulator16; //xy=223,674
AudioSynthWaveformModulated modulator17; //xy=224,760
AudioSynthWaveformModulated modulator18; //xy=226,798
AudioSynthWaveformModulated modulator19; //xy=227,835
AudioSynthWaveformModulated modulator20; //xy=227,872
AudioEffectWaveshaper    modulatorWaveshape1;     //xy=390,54
AudioEffectWaveshaper    modulatorWaveshape2; //xy=390,91
AudioEffectWaveshaper    modulatorWaveshape3; //xy=391,126
AudioEffectWaveshaper    modulatorWaveshape4; //xy=393,162
AudioEffectWaveshaper    modulatorWaveshape5; //xy=395,214
AudioEffectWaveshaper    modulatorWaveshape6; //xy=395,249
AudioEffectWaveshaper    modulatorWaveshape7; //xy=395,283
AudioEffectWaveshaper    modulatorWaveshape8; //xy=399,318
AudioEffectWaveshaper    modulatorWaveshape10; //xy=402,423
AudioEffectWaveshaper    modulatorWaveshape9; //xy=403,387
AudioEffectWaveshaper    modulatorWaveshape11; //xy=403,457
AudioEffectWaveshaper    modulatorWaveshape12; //xy=403,492
AudioEffectWaveshaper    modulatorWaveshape13; //xy=405,563
AudioEffectWaveshaper    modulatorWaveshape14; //xy=408,602
AudioEffectWaveshaper    modulatorWaveshape15; //xy=408,638
AudioEffectWaveshaper    modulatorWaveshape16; //xy=408,674
AudioEffectWaveshaper    modulatorWaveshape17; //xy=409,760
AudioEffectWaveshaper    modulatorWaveshape18; //xy=411,798
AudioEffectWaveshaper    modulatorWaveshape19; //xy=412,835
AudioEffectWaveshaper    modulatorWaveshape20; //xy=412,872
AudioEffectEnvelope      modulatorEnvelope1; //xy=603,54
AudioEffectEnvelope      modulatorEnvelope2; //xy=603,90
AudioEffectEnvelope      modulatorEnvelope3; //xy=604,125
AudioEffectEnvelope      modulatorEnvelope4; //xy=606,161
AudioEffectEnvelope      modulatorEnvelope5; //xy=608,213
AudioEffectEnvelope      modulatorEnvelope6; //xy=608,248
AudioEffectEnvelope      modulatorEnvelope7; //xy=608,282
AudioEffectEnvelope      modulatorEnvelope8; //xy=612,317
AudioEffectEnvelope      modulatorEnvelope10; //xy=615,422
AudioEffectEnvelope      modulatorEnvelope9; //xy=616,386
AudioEffectEnvelope      modulatorEnvelope11; //xy=616,456
AudioEffectEnvelope      modulatorEnvelope12; //xy=616,491
AudioEffectEnvelope      modulatorEnvelope13; //xy=618,562
AudioEffectEnvelope      modulatorEnvelope14; //xy=621,601
AudioEffectEnvelope      modulatorEnvelope15; //xy=621,637
AudioEffectEnvelope      modulatorEnvelope16; //xy=621,673
AudioEffectEnvelope      modulatorEnvelope17; //xy=622,759
AudioEffectEnvelope      modulatorEnvelope18; //xy=624,797
AudioEffectEnvelope      modulatorEnvelope19; //xy=625,834
AudioEffectEnvelope      modulatorEnvelope20; //xy=625,871
AudioSynthWaveformModulated carrier1;       //xy=774,54
AudioSynthWaveformModulated carrier2;       //xy=774,90
AudioSynthWaveformModulated carrier3; //xy=775,125
AudioSynthWaveformModulated carrier4; //xy=777,161
AudioSynthWaveformModulated carrier5; //xy=779,213
AudioSynthWaveformModulated carrier6; //xy=779,248
AudioSynthWaveformModulated carrier7; //xy=779,282
AudioSynthWaveformModulated carrier8; //xy=783,317
AudioSynthWaveformModulated carrier10; //xy=786,422
AudioSynthWaveformModulated carrier9; //xy=787,386
AudioSynthWaveformModulated carrier11; //xy=787,456
AudioSynthWaveformModulated carrier12; //xy=787,491
AudioSynthWaveformModulated carrier13; //xy=789,562
AudioSynthWaveformModulated carrier14; //xy=792,601
AudioSynthWaveformModulated carrier15; //xy=792,637
AudioSynthWaveformModulated carrier16; //xy=792,673
AudioSynthWaveformModulated carrier17; //xy=793,759
AudioSynthWaveformModulated carrier18; //xy=795,797
AudioSynthWaveformModulated carrier19; //xy=796,834
AudioSynthWaveformModulated carrier20; //xy=796,871
AudioEffectWaveshaper    carrierWaveshape2; //xy=942,90
AudioEffectWaveshaper    carrierWaveshape3; //xy=943,125
AudioEffectWaveshaper    carrierWaveshape1; //xy=944,54
AudioEffectWaveshaper    carrierWaveshape4; //xy=945,161
AudioEffectWaveshaper    carrierWaveshape5; //xy=947,213
AudioEffectWaveshaper    carrierWaveshape6; //xy=947,248
AudioEffectWaveshaper    carrierWaveshape7; //xy=947,282
AudioEffectWaveshaper    carrierWaveshape8; //xy=951,317
AudioEffectWaveshaper    carrierWaveshape10; //xy=954,422
AudioEffectWaveshaper    carrierWaveshape9; //xy=955,386
AudioEffectWaveshaper    carrierWaveshape11; //xy=955,456
AudioEffectWaveshaper    carrierWaveshape12; //xy=955,491
AudioEffectWaveshaper    carrierWaveshape13; //xy=957,562
AudioEffectWaveshaper    carrierWaveshape14; //xy=960,601
AudioEffectWaveshaper    carrierWaveshape15; //xy=960,637
AudioEffectWaveshaper    carrierWaveshape16; //xy=960,673
AudioEffectWaveshaper    carrierWaveshape17; //xy=961,759
AudioEffectWaveshaper    carrierWaveshape18; //xy=963,797
AudioEffectWaveshaper    carrierWaveshape19; //xy=964,834
AudioEffectWaveshaper    carrierWaveshape20; //xy=964,871
AudioEffectEnvelope      carrierEnvelope1; //xy=1139,54
AudioEffectEnvelope      carrierEnvelope2; //xy=1139,90
AudioEffectEnvelope      carrierEnvelope3; //xy=1140,125
AudioEffectEnvelope      carrierEnvelope4; //xy=1142,161
AudioEffectEnvelope      carrierEnvelope5; //xy=1144,213
AudioEffectEnvelope      carrierEnvelope6; //xy=1144,248
AudioEffectEnvelope      carrierEnvelope7; //xy=1144,282
AudioEffectEnvelope      carrierEnvelope8; //xy=1148,317
AudioEffectEnvelope      carrierEnvelope10; //xy=1151,422
AudioEffectEnvelope      carrierEnvelope9; //xy=1152,386
AudioEffectEnvelope      carrierEnvelope11; //xy=1152,456
AudioEffectEnvelope      carrierEnvelope12; //xy=1152,491
AudioEffectEnvelope      carrierEnvelope13; //xy=1154,562
AudioEffectEnvelope      carrierEnvelope14; //xy=1157,601
AudioEffectEnvelope      carrierEnvelope15; //xy=1157,637
AudioEffectEnvelope      carrierEnvelope16; //xy=1157,673
AudioEffectEnvelope      carrierEnvelope17; //xy=1158,759
AudioEffectEnvelope      carrierEnvelope18; //xy=1160,797
AudioEffectEnvelope      carrierEnvelope19; //xy=1161,834
AudioEffectEnvelope      carrierEnvelope20; //xy=1161,871
AudioMixer4              mixer1;         //xy=1306,117
AudioMixer4              mixer3;         //xy=1309,446
AudioMixer4              mixer2;         //xy=1312,266
AudioMixer4              mixer4;         //xy=1317,626
AudioMixer4              mixer6;         //xy=1320,826
AudioMixer4              mixer5;         //xy=1478,365
AudioMixer4              mixerMaster;    //xy=1668,498
AudioOutputI2S           i2s1;           //xy=1994,487
AudioConnection          patchCord1(modulator1, modulatorWaveshape1);
AudioConnection          patchCord2(modulator2, modulatorWaveshape2);
AudioConnection          patchCord3(modulator3, modulatorWaveshape3);
AudioConnection          patchCord4(modulator4, modulatorWaveshape4);
AudioConnection          patchCord5(modulator5, modulatorWaveshape5);
AudioConnection          patchCord6(modulator6, modulatorWaveshape6);
AudioConnection          patchCord7(modulator7, modulatorWaveshape7);
AudioConnection          patchCord8(modulator8, modulatorWaveshape8);
AudioConnection          patchCord9(modulator10, modulatorWaveshape10);
AudioConnection          patchCord10(modulator9, modulatorWaveshape9);
AudioConnection          patchCord11(modulator11, modulatorWaveshape11);
AudioConnection          patchCord12(modulator12, modulatorWaveshape12);
AudioConnection          patchCord13(modulator13, modulatorWaveshape13);
AudioConnection          patchCord14(modulator14, modulatorWaveshape14);
AudioConnection          patchCord15(modulator15, modulatorWaveshape15);
AudioConnection          patchCord16(modulator16, modulatorWaveshape16);
AudioConnection          patchCord17(modulator17, modulatorWaveshape17);
AudioConnection          patchCord18(modulator18, modulatorWaveshape18);
AudioConnection          patchCord19(modulator19, modulatorWaveshape19);
AudioConnection          patchCord20(modulator20, modulatorWaveshape20);
AudioConnection          patchCord21(modulatorWaveshape1, modulatorEnvelope1);
AudioConnection          patchCord22(modulatorWaveshape2, modulatorEnvelope2);
AudioConnection          patchCord23(modulatorWaveshape3, modulatorEnvelope3);
AudioConnection          patchCord24(modulatorWaveshape4, modulatorEnvelope4);
AudioConnection          patchCord25(modulatorWaveshape5, modulatorEnvelope5);
AudioConnection          patchCord26(modulatorWaveshape6, modulatorEnvelope6);
AudioConnection          patchCord27(modulatorWaveshape7, modulatorEnvelope7);
AudioConnection          patchCord28(modulatorWaveshape8, modulatorEnvelope8);
AudioConnection          patchCord29(modulatorWaveshape10, modulatorEnvelope10);
AudioConnection          patchCord30(modulatorWaveshape9, modulatorEnvelope9);
AudioConnection          patchCord31(modulatorWaveshape11, modulatorEnvelope11);
AudioConnection          patchCord32(modulatorWaveshape12, modulatorEnvelope12);
AudioConnection          patchCord33(modulatorWaveshape13, modulatorEnvelope13);
AudioConnection          patchCord34(modulatorWaveshape14, modulatorEnvelope14);
AudioConnection          patchCord35(modulatorWaveshape15, modulatorEnvelope15);
AudioConnection          patchCord36(modulatorWaveshape16, modulatorEnvelope16);
AudioConnection          patchCord37(modulatorWaveshape17, modulatorEnvelope17);
AudioConnection          patchCord38(modulatorWaveshape18, modulatorEnvelope18);
AudioConnection          patchCord39(modulatorWaveshape19, modulatorEnvelope19);
AudioConnection          patchCord40(modulatorWaveshape20, modulatorEnvelope20);
AudioConnection          patchCord41(modulatorEnvelope1, 0, carrier1, 0);
AudioConnection          patchCord42(modulatorEnvelope2, 0, carrier2, 0);
AudioConnection          patchCord43(modulatorEnvelope3, 0, carrier3, 0);
AudioConnection          patchCord44(modulatorEnvelope4, 0, carrier4, 0);
AudioConnection          patchCord45(modulatorEnvelope5, 0, carrier5, 0);
AudioConnection          patchCord46(modulatorEnvelope6, 0, carrier6, 0);
AudioConnection          patchCord47(modulatorEnvelope7, 0, carrier7, 0);
AudioConnection          patchCord48(modulatorEnvelope8, 0, carrier8, 0);
AudioConnection          patchCord49(modulatorEnvelope10, 0, carrier10, 0);
AudioConnection          patchCord50(modulatorEnvelope9, 0, carrier9, 0);
AudioConnection          patchCord51(modulatorEnvelope11, 0, carrier11, 0);
AudioConnection          patchCord52(modulatorEnvelope12, 0, carrier12, 0);
AudioConnection          patchCord53(modulatorEnvelope13, 0, carrier13, 0);
AudioConnection          patchCord54(modulatorEnvelope14, 0, carrier14, 0);
AudioConnection          patchCord55(modulatorEnvelope15, 0, carrier15, 0);
AudioConnection          patchCord56(modulatorEnvelope16, 0, carrier16, 0);
AudioConnection          patchCord57(modulatorEnvelope17, 0, carrier17, 0);
AudioConnection          patchCord58(modulatorEnvelope18, 0, carrier18, 0);
AudioConnection          patchCord59(modulatorEnvelope19, 0, carrier19, 0);
AudioConnection          patchCord60(modulatorEnvelope20, 0, carrier20, 0);
AudioConnection          patchCord61(carrier1, carrierWaveshape1);
AudioConnection          patchCord62(carrier2, carrierWaveshape2);
AudioConnection          patchCord63(carrier3, carrierWaveshape3);
AudioConnection          patchCord64(carrier4, carrierWaveshape4);
AudioConnection          patchCord65(carrier5, carrierWaveshape5);
AudioConnection          patchCord66(carrier6, carrierWaveshape6);
AudioConnection          patchCord67(carrier7, carrierWaveshape7);
AudioConnection          patchCord68(carrier8, carrierWaveshape8);
AudioConnection          patchCord69(carrier10, carrierWaveshape10);
AudioConnection          patchCord70(carrier9, carrierWaveshape9);
AudioConnection          patchCord71(carrier11, carrierWaveshape11);
AudioConnection          patchCord72(carrier12, carrierWaveshape12);
AudioConnection          patchCord73(carrier13, carrierWaveshape13);
AudioConnection          patchCord74(carrier14, carrierWaveshape14);
AudioConnection          patchCord75(carrier15, carrierWaveshape15);
AudioConnection          patchCord76(carrier16, carrierWaveshape16);
AudioConnection          patchCord77(carrier17, carrierWaveshape17);
AudioConnection          patchCord78(carrier18, carrierWaveshape18);
AudioConnection          patchCord79(carrier19, carrierWaveshape19);
AudioConnection          patchCord80(carrier20, carrierWaveshape20);
AudioConnection          patchCord81(carrierWaveshape2, carrierEnvelope2);
AudioConnection          patchCord82(carrierWaveshape3, carrierEnvelope3);
AudioConnection          patchCord83(carrierWaveshape1, carrierEnvelope1);
AudioConnection          patchCord84(carrierWaveshape4, carrierEnvelope4);
AudioConnection          patchCord85(carrierWaveshape5, carrierEnvelope5);
AudioConnection          patchCord86(carrierWaveshape6, carrierEnvelope6);
AudioConnection          patchCord87(carrierWaveshape7, carrierEnvelope7);
AudioConnection          patchCord88(carrierWaveshape8, carrierEnvelope8);
AudioConnection          patchCord89(carrierWaveshape10, carrierEnvelope10);
AudioConnection          patchCord90(carrierWaveshape9, carrierEnvelope9);
AudioConnection          patchCord91(carrierWaveshape11, carrierEnvelope11);
AudioConnection          patchCord92(carrierWaveshape12, carrierEnvelope12);
AudioConnection          patchCord93(carrierWaveshape13, carrierEnvelope13);
AudioConnection          patchCord94(carrierWaveshape14, carrierEnvelope14);
AudioConnection          patchCord95(carrierWaveshape15, carrierEnvelope15);
AudioConnection          patchCord96(carrierWaveshape16, carrierEnvelope16);
AudioConnection          patchCord97(carrierWaveshape17, carrierEnvelope17);
AudioConnection          patchCord98(carrierWaveshape18, carrierEnvelope18);
AudioConnection          patchCord99(carrierWaveshape19, carrierEnvelope19);
AudioConnection          patchCord100(carrierWaveshape20, carrierEnvelope20);
AudioConnection          patchCord101(carrierEnvelope1, 0, mixer1, 0);
AudioConnection          patchCord102(carrierEnvelope2, 0, mixer1, 1);
AudioConnection          patchCord103(carrierEnvelope3, 0, mixer1, 2);
AudioConnection          patchCord104(carrierEnvelope4, 0, mixer1, 3);
AudioConnection          patchCord105(carrierEnvelope5, 0, mixer2, 0);
AudioConnection          patchCord106(carrierEnvelope6, 0, mixer2, 1);
AudioConnection          patchCord107(carrierEnvelope7, 0, mixer2, 2);
AudioConnection          patchCord108(carrierEnvelope8, 0, mixer2, 3);
AudioConnection          patchCord109(carrierEnvelope10, 0, mixer3, 1);
AudioConnection          patchCord110(carrierEnvelope9, 0, mixer3, 0);
AudioConnection          patchCord111(carrierEnvelope11, 0, mixer3, 2);
AudioConnection          patchCord112(carrierEnvelope12, 0, mixer3, 3);
AudioConnection          patchCord113(carrierEnvelope13, 0, mixer4, 0);
AudioConnection          patchCord114(carrierEnvelope14, 0, mixer4, 1);
AudioConnection          patchCord115(carrierEnvelope15, 0, mixer4, 2);
AudioConnection          patchCord116(carrierEnvelope16, 0, mixer4, 3);
AudioConnection          patchCord117(carrierEnvelope17, 0, mixer6, 0);
AudioConnection          patchCord118(carrierEnvelope18, 0, mixer6, 1);
AudioConnection          patchCord119(carrierEnvelope19, 0, mixer6, 2);
AudioConnection          patchCord120(carrierEnvelope20, 0, mixer6, 3);
AudioConnection          patchCord121(mixer1, 0, mixer5, 0);
AudioConnection          patchCord122(mixer3, 0, mixer5, 2);
AudioConnection          patchCord123(mixer2, 0, mixer5, 1);
AudioConnection          patchCord124(mixer4, 0, mixer5, 3);
AudioConnection          patchCord125(mixer6, 0, mixerMaster, 1);
AudioConnection          patchCord126(mixer5, 0, mixerMaster, 0);
AudioConnection          patchCord127(mixerMaster, 0, i2s1, 0);
AudioConnection          patchCord128(mixerMaster, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1998,536
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
  AudioMemory(96);
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

  //noisy bass thingy
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
  programBank1[4].SetOperatorVolume(0,0.9);
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

  float _volumeDAHDSR10[6] = {0, 2500, 0, 2500, 0.5, 500};
  programBank1[6].SetVolumeDAHDSR(0, _volumeDAHDSR10);
  programBank1[6].SetWaveform(0, WAVEFORM_SINE);
  programBank1[6].SetOperatorVolume(0, 0.6);
  programBank1[6].SetFreqMul(0, 0.25);
  programBank1[6].SetFreqAdd(0, 0.025);
  programBank1[6].SetWaveform(1, WAVEFORM_SINE);
  programBank1[6].SetOperatorVolume(1, 1);


  programBank1[7].SetWaveform(0, WAVEFORM_SAWTOOTH_REVERSE);
  programBank1[7].SetFreqMul(0, 2.0);
  float _volumeDAHDSR12[6] = {500, 1500, 0, 500, 0.3, 700};
  programBank1[7].SetVolumeDAHDSR(0, _volumeDAHDSR12);
  programBank1[7].SetFreqAdd(0, 0.1);
  programBank1[7].SetOperatorVolume(0,0.15);
  //float _waveshape12[17] = {-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1};
  float _waveshape12[17] = {-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //pow(x,2) curve
  programBank1[7].SetWaveshape(0, _waveshape12);
  programBank1[7].SetWaveform(1, WAVEFORM_SAWTOOTH_REVERSE);
  programBank1[7].SetFreqMul(1, 1.0);
  float _volumeDAHDSR13[6] = {0, 10, 0, 100, 1, 700};
  programBank1[7].SetVolumeDAHDSR(1, _volumeDAHDSR13);
  programBank1[7].SetFreqAdd(1, 0);
  programBank1[7].SetOperatorVolume(1,1);
  float _waveshape13[17] = {-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0, 0, 1, 1, 1, 0-.625, -0.625, -0.625}; 
  programBank1[7].SetWaveshape(1, _waveshape13);

  //
  programBank1[8].SetWaveform(0, WAVEFORM_SAWTOOTH_REVERSE);
  programBank1[8].SetFreqMul(0, 2.0);
  float _volumeDAHDSR14[6] = {0, 10, 0, 300, 0.2, 700};
  programBank1[8].SetVolumeDAHDSR(0, _volumeDAHDSR14);
  programBank1[8].SetFreqAdd(0, 0.05);
  programBank1[8].SetOperatorVolume(0,0.7);
  programBank1[8].SetWaveform(1, WAVEFORM_SINE);
  programBank1[8].SetFreqMul(1, 1.0);
  float _volumeDAHDSR15[6] = {0, 10, 0, 100, 1, 700};
  programBank1[8].SetVolumeDAHDSR(1, _volumeDAHDSR15);
  programBank1[8].SetFreqAdd(1, 0);
  programBank1[8].SetOperatorVolume(1,1);
  float _waveshape15[17] = {-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //pow(x,2) curve
  programBank1[8].SetWaveshape(0, _waveshape15); 


  //w00tness
  programBank1[9].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[9].SetFreqMul(0, 1);
  float _volumeDAHDSR16[6] = {0, 50, 0, 250, 0.75, 300};
  programBank1[9].SetVolumeDAHDSR(0, _volumeDAHDSR16);
  programBank1[9].SetFreqAdd(0, 0.1);
  programBank1[9].SetOperatorVolume(0, 0.90);
  float _waveshape16[17] = {-1, 0, -1, 0, -1, 0,-1, 0, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1}; //"lowpass" beim kick
  //{-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 1, 0, 1, 0, 1, 0, 1, 0};  //"lowpass" nach dem kick
  programBank1[9].SetWaveshape(0, _waveshape16); 
  programBank1[9].SetWaveform(1, WAVEFORM_SINE);
  programBank1[9].SetFreqMul(1, 1);
  float _volumeDAHDSR17[6] = {0, 10, 0, 10, 1, 300};
  programBank1[9].SetVolumeDAHDSR(1, _volumeDAHDSR17);
  programBank1[9].SetFreqAdd(1, 0);
  programBank1[9].SetOperatorVolume(1, 1.0);
  float _waveshape17[17] = {-1, -1, -1, -1, -1, 0,0, 0, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1};
  //{-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 1, 0, 1, 0, 1, 0, 1, 0}; //"high noise"
  programBank1[9].SetWaveshape(1, _waveshape17); 

  //w00tness 2
  programBank1[10].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[10].SetFreqMul(0, 1);
  float _volumeDAHDSR18[6] = {0, 60, 0, 250, 0.5, 300};
  programBank1[10].SetVolumeDAHDSR(0, _volumeDAHDSR18);
  programBank1[10].SetFreqAdd(0, 0.1);
  programBank1[10].SetOperatorVolume(0, 0.9);
  float _waveshape18[17] = {-1, 0, -1, 0, -1, 0,-1, 0, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1}; //"lowpass" beim kick
  //{-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 1, 0, 1, 0, 1, 0, 1, 0};  //"lowpass" nach dem kick
  programBank1[10].SetWaveshape(0, _waveshape18); 
  programBank1[10].SetWaveform(1, WAVEFORM_SINE);
  programBank1[10].SetFreqMul(1, 1);
  float _volumeDAHDSR19[6] = {0, 10, 0, 10, 1, 300};
  programBank1[10].SetVolumeDAHDSR(1, _volumeDAHDSR19);
  programBank1[10].SetFreqAdd(1, 0);
  programBank1[10].SetOperatorVolume(1, 1.0);
  float _waveshape19[17] = {-1, 0, -1, 0, -1, 0,-1, 0, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1};
  //{-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 1, 0, 1, 0, 1, 0, 1, 0}; //"high noise"
  //programBank1[10].SetWaveshape(1, _waveshape19); 

  //Noisy stuff
   programBank1[11].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[11].SetFreqMul(0, 1);
  float _volumeDAHDSR20[6] = {0, 100, 0, 50, 0.5, 300};
  programBank1[11].SetVolumeDAHDSR(0, _volumeDAHDSR20);
  programBank1[11].SetFreqAdd(0, 0.1);
  programBank1[11].SetOperatorVolume(0, 0.9);
  float _waveshape20[17] = {-1, -1, -1, -1, -1, -1, 0, 0.5, 0, 1, 0, 1, 0, 1, 0, 1, 0};//{-1, -1, -1, -1, -1, -1, 0, 0.5, 0, 1, 0, 1, 0, 1, 0, 1, 0};
  //{-1, 0, -1, 0, -1, 0,-1, 0, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1}; //"lowpass" beim kick
  //{-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 1, 0, 1, 0, 1, 0, 1, 0};  //"lowpass" nach dem kick
  //{-1, -0.765625, -0.5625, -0.390625, 0, 0,0, 0, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1};
  programBank1[11].SetWaveshape(0, _waveshape20); 
  programBank1[11].SetWaveform(1, WAVEFORM_SINE);
  programBank1[11].SetFreqMul(1, 1);
  float _volumeDAHDSR21[6] = {0, 10, 0, 10, 1, 300};
  programBank1[11].SetVolumeDAHDSR(1, _volumeDAHDSR21);
  programBank1[11].SetFreqAdd(1, 0);
  programBank1[11].SetOperatorVolume(1, 1);
  float _waveshape21[17] = {-1, -1, -1, -1, -1, -1, 0, 0.5, 0, 1, 0, 1, 0, 1, 0, 1, 0};
  //{-1, 0, -1, 0, -1, 0,-1, 0, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1}; "low" noise
  //{-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 1, 0, 1, 0, 1, 0, 1, 0}; //"high noise"
  programBank1[11].SetWaveshape(1, _waveshape21); 


  programBank1[12].SetWaveform(0, WAVEFORM_SAWTOOTH_REVERSE);
  programBank1[12].SetFreqMul(0, 0.5);
  float _volumeDAHDSR22[6] = {0, 30, 0, 100, 0.5, 70};
  programBank1[12].SetVolumeDAHDSR(0, _volumeDAHDSR22);
  programBank1[12].SetFreqAdd(0, 0.05);
  programBank1[12].SetOperatorVolume(0,0.3);
  float _waveshape22[17] = {-1, 0, -1, 0, -1, 0,-1, 0, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[12].SetWaveshape(0, _waveshape22); 
  programBank1[12].SetWaveform(1, WAVEFORM_SINE);
  programBank1[12].SetFreqMul(1, 2.0);
  float _volumeDAHDSR23[6] = {0, 10, 0, 100, 1, 100};
  programBank1[12].SetVolumeDAHDSR(1, _volumeDAHDSR23);
  programBank1[12].SetFreqAdd(1, 0);
  programBank1[12].SetOperatorVolume(1,1);


  programBank1[13].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[13].SetFreqMul(0, 0.5);
  float _volumeDAHDSR24[6] = {0, 8, 0, 100, 0.3, 70};
  programBank1[13].SetVolumeDAHDSR(0, _volumeDAHDSR24);
  programBank1[13].SetFreqAdd(0, 1);
  programBank1[13].SetOperatorVolume(0,0.25);
  float _waveshape24[17] = {-1, -1, -1, -1, -1, -0.75, -0.5, -0.25, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[13].SetWaveshape(0, _waveshape24); 
  programBank1[13].SetWaveform(1, WAVEFORM_SINE);
  programBank1[13].SetFreqMul(1, 1.0);
  float _volumeDAHDSR25[6] = {0, 30, 0, 100, 1, 100};
  programBank1[13].SetVolumeDAHDSR(1, _volumeDAHDSR25);
  programBank1[13].SetFreqAdd(1, 0);
  programBank1[13].SetOperatorVolume(1,0.9);
  float _waveshape25[17] = {-1, -1, -1, -1, -1, -1,-1, -1, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[13].SetWaveshape(1, _waveshape25); 


  programBank1[14].SetWaveform(0, WAVEFORM_TRIANGLE);
  programBank1[14].SetFreqMul(0, 0.5);
  float _volumeDAHDSR26[6] = {0, 8, 0, 20, 0.3, 70};
  programBank1[14].SetVolumeDAHDSR(0, _volumeDAHDSR26);
  programBank1[14].SetFreqAdd(0, 1);
  programBank1[14].SetOperatorVolume(0,0.4);
  float _waveshape26[17] = {-1, 0, -1, 0, -1, 0,-1, 0, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[14].SetWaveshape(0, _waveshape26); 
  programBank1[14].SetWaveform(1, WAVEFORM_SINE);
  programBank1[14].SetFreqMul(1, 1.0);
  float _volumeDAHDSR27[6] = {0, 10, 0, 100, 1, 100};
  programBank1[14].SetVolumeDAHDSR(1, _volumeDAHDSR27);
  programBank1[14].SetFreqAdd(1, 0);
  programBank1[14].SetOperatorVolume(1,0.9);
  float _waveshape27[17] = {-1, -1, -1, -1, -1, -1,-1, -1, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[14].SetWaveshape(1, _waveshape27); 

  //80s bass
  programBank1[15].SetWaveform(0, WAVEFORM_SINE);
  programBank1[15].SetFreqMul(0, 1);
  float _volumeDAHDSR28[6] = {0, 10, 0, 40, 0.3, 70};
  programBank1[15].SetVolumeDAHDSR(0, _volumeDAHDSR28);
  programBank1[15].SetFreqAdd(0, 1);
  programBank1[15].SetOperatorVolume(0,0.3);
  float _waveshape28[17] = {-1, -1, -1, -1, -1, -0.75, -0.5, -0.25, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[15].SetWaveshape(0, _waveshape28); 
  programBank1[15].SetWaveform(1, WAVEFORM_SINE);
  programBank1[15].SetFreqMul(1, 1.0);
  float _volumeDAHDSR29[6] = {0, 10, 0, 100, 1, 100};
  programBank1[15].SetVolumeDAHDSR(1, _volumeDAHDSR29);
  programBank1[15].SetFreqAdd(1, 0);
  programBank1[15].SetOperatorVolume(1,1);
  float _waveshape29[17] = {-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //pow2
  // {-1, -1, -1, -1, -1, -1,-1, -1, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //guitary
  // {-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //pow2
  //programBank1[15].SetWaveshape(1, _waveshape29); 

  //
  programBank1[16].SetWaveform(0, WAVEFORM_SINE);
  programBank1[16].SetFreqMul(0, 1);
  float _volumeDAHDSR30[6] = {0, 2, 0, 40, 0.3, 200};
  programBank1[16].SetVolumeDAHDSR(0, _volumeDAHDSR30);
  programBank1[16].SetFreqAdd(0, 1);
  programBank1[16].SetOperatorVolume(0,0.3);
  float _waveshape30[17] = {-1, -1, -1, -1, -1, -1, -1, -1, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[16].SetWaveshape(0, _waveshape30); 
  programBank1[16].SetWaveform(1, WAVEFORM_SINE);
  programBank1[16].SetFreqMul(1, 1.0);
  float _volumeDAHDSR31[6] = {0, 10, 0, 100, 1, 150};
  programBank1[16].SetVolumeDAHDSR(1, _volumeDAHDSR31);
  programBank1[16].SetFreqAdd(1, 0);
  programBank1[16].SetOperatorVolume(1,1);
  float _waveshape31[17] = {-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //pow2
  // {-1, -1, -1, -1, -1, -1,-1, -1, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //guitary
  // {-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //pow2
  programBank1[16].SetWaveshape(1, _waveshape31); 
  

  //
  programBank1[17].SetWaveform(0, WAVEFORM_TRIANGLE);
  programBank1[17].SetFreqMul(0, 2.0);
  float _volumeDAHDSR32[6] = {0, 30, 0, 200, 0.2, 700};
  programBank1[17].SetVolumeDAHDSR(0, _volumeDAHDSR32);
  programBank1[17].SetFreqAdd(0, 1);
  programBank1[17].SetOperatorVolume(0,0.2);
  float _waveshape32[17] = {-1, -1, -1, -1, -1, -0.75, -0.5, -0.25, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[17].SetWaveshape(0, _waveshape32); 
  programBank1[17].SetWaveform(1, WAVEFORM_SINE);
  programBank1[17].SetFreqMul(1, 1.0);
  float _volumeDAHDSR33[6] = {0, 10, 0, 100, 1, 100};
  programBank1[17].SetVolumeDAHDSR(1, _volumeDAHDSR33);
  programBank1[17].SetFreqAdd(1, 0);
  programBank1[17].SetOperatorVolume(1,1);
  

  //Setup voices
  voice[0] = Voice(&modulator1, &modulatorWaveshape1, &modulatorEnvelope1, &carrier1, &carrierWaveshape1, &carrierEnvelope1, firstProgram);
  voice[1] = Voice(&modulator2, &modulatorWaveshape2, &modulatorEnvelope2, &carrier2, &carrierWaveshape2, &carrierEnvelope2, firstProgram);
  voice[2] = Voice(&modulator3, &modulatorWaveshape3, &modulatorEnvelope3, &carrier3, &carrierWaveshape3, &carrierEnvelope3, firstProgram);
  voice[3] = Voice(&modulator4, &modulatorWaveshape4, &modulatorEnvelope4, &carrier4, &carrierWaveshape4, &carrierEnvelope4, firstProgram);
  voice[4] = Voice(&modulator5, &modulatorWaveshape5, &modulatorEnvelope5, &carrier5, &carrierWaveshape5, &carrierEnvelope5, firstProgram);
  voice[5] = Voice(&modulator6, &modulatorWaveshape6, &modulatorEnvelope6, &carrier6, &carrierWaveshape6, &carrierEnvelope6, firstProgram);
  voice[6] = Voice(&modulator7, &modulatorWaveshape7, &modulatorEnvelope7, &carrier7, &carrierWaveshape7, &carrierEnvelope7, firstProgram);
  voice[7] = Voice(&modulator8, &modulatorWaveshape8, &modulatorEnvelope8, &carrier8, &carrierWaveshape8, &carrierEnvelope8, firstProgram);
  voice[8] = Voice(&modulator9, &modulatorWaveshape9, &modulatorEnvelope9, &carrier9, &carrierWaveshape9, &carrierEnvelope9, firstProgram);
  voice[9] = Voice(&modulator10, &modulatorWaveshape10, &modulatorEnvelope10, &carrier10, &carrierWaveshape10, &carrierEnvelope10, firstProgram);
  voice[10] = Voice(&modulator11, &modulatorWaveshape11, &modulatorEnvelope11, &carrier11, &carrierWaveshape11, &carrierEnvelope11, firstProgram);
  voice[11] = Voice(&modulator12, &modulatorWaveshape12, &modulatorEnvelope12, &carrier12, &carrierWaveshape12, &carrierEnvelope12, firstProgram);
  voice[12] = Voice(&modulator13, &modulatorWaveshape13, &modulatorEnvelope13, &carrier13, &carrierWaveshape13, &carrierEnvelope13, firstProgram);
  voice[13] = Voice(&modulator14, &modulatorWaveshape14, &modulatorEnvelope14, &carrier14, &carrierWaveshape14, &carrierEnvelope14, firstProgram);
  voice[14] = Voice(&modulator15, &modulatorWaveshape15, &modulatorEnvelope15, &carrier15, &carrierWaveshape15, &carrierEnvelope15, firstProgram);
  voice[15] = Voice(&modulator16, &modulatorWaveshape16, &modulatorEnvelope16, &carrier16, &carrierWaveshape16, &carrierEnvelope16, firstProgram);
  voice[16] = Voice(&modulator17, &modulatorWaveshape17, &modulatorEnvelope17, &carrier17, &carrierWaveshape17, &carrierEnvelope17, firstProgram);
  voice[17] = Voice(&modulator18, &modulatorWaveshape18, &modulatorEnvelope18, &carrier18, &carrierWaveshape18, &carrierEnvelope18, firstProgram);
  voice[18] = Voice(&modulator19, &modulatorWaveshape19, &modulatorEnvelope18, &carrier19, &carrierWaveshape19, &carrierEnvelope19, firstProgram);
  voice[19] = Voice(&modulator20, &modulatorWaveshape20, &modulatorEnvelope20, &carrier20, &carrierWaveshape20, &carrierEnvelope20, firstProgram);

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

