#ifndef Voice_h_
#define Voice_h_

#include "Program.h"

class Voice{
  private:
    AudioSynthWaveform       *modulator;      //xy=393,306
    AudioEffectEnvelope      *modulatorEnvelope;      //xy=576,305
    AudioSynthWaveformModulated *carrier;
    AudioEffectEnvelope      *carrierEnvelope;      //xy=872,301
    bool isPlaying;
    //The program used by this voice
    Program *program; 

    void Setup(AudioSynthWaveform *modulator, AudioEffectEnvelope *modulatorEnvelope, AudioSynthWaveformModulated *carrier, AudioEffectEnvelope *carrierEnvelope, Program *program);

  public:
    byte pitch;
    byte channel;
    Voice();
    Voice(AudioSynthWaveform *modulator, AudioEffectEnvelope *modulatorEnvelope, AudioSynthWaveformModulated *carrier, AudioEffectEnvelope *carrierEnvelope, Program *program);
    

    void SetProgram(Program *program);
    
    void NoteOn(byte channel, byte pitch, float level);
    void NoteOff();
    bool IsPlaying();
};

Voice::Voice(){
}

Voice::Voice(AudioSynthWaveform *modulator, AudioEffectEnvelope *modulatorEnvelope, AudioSynthWaveformModulated *carrier, AudioEffectEnvelope *carrierEnvelope, Program *program)
{
 Setup(modulator, modulatorEnvelope, carrier, carrierEnvelope, program);
}

void Voice::Setup(AudioSynthWaveform *modulator, AudioEffectEnvelope *modulatorEnvelope, AudioSynthWaveformModulated *carrier, AudioEffectEnvelope *carrierEnvelope, Program *program){
  this->carrier = carrier;
  this->carrierEnvelope = carrierEnvelope;
  this->modulator = modulator;
  this->modulatorEnvelope = modulatorEnvelope;
  this->program = program;


  //set modulator envelope
  (*(this->modulatorEnvelope)).attack(2500);
  (*(this->modulatorEnvelope)).hold(0);
  (*(this->modulatorEnvelope)).decay(1);
  (*(this->modulatorEnvelope)).sustain(1);
  (*(this->modulatorEnvelope)).release(120);
  //set carrier envelope
  (*(this->carrierEnvelope)).attack(10);
  (*(this->carrierEnvelope)).hold(0);
  (*(this->carrierEnvelope)).decay(50);
  (*(this->carrierEnvelope)).sustain(1);
  (*(this->carrierEnvelope)).release(120);

  //Modulator sine * 2, Carrier sine * 1 -> ?Glockenspiel?Harp? (Zelda fairy). :)
/*
  //set modulator envelope
  (*(this->modulatorEnvelope)).attack(25);
  (*(this->modulatorEnvelope)).hold(0);
  (*(this->modulatorEnvelope)).decay(250);
  (*(this->modulatorEnvelope)).sustain(0.3);
  (*(this->modulatorEnvelope)).release(700);
  //set carrier envelope
  (*(this->carrierEnvelope)).attack(2);
  (*(this->carrierEnvelope)).hold(0);
  (*(this->carrierEnvelope)).decay(500);
  (*(this->carrierEnvelope)).sustain(0.6);
  (*(this->carrierEnvelope)).release(700);
  */
  

  //Modulator triangle * 2 (or 0.5), Carrier sine * 1 -> very lush
  /*
  //set modulator envelope
  (*(this->modulatorEnvelope)).attack(250);
  (*(this->modulatorEnvelope)).hold(0);
  (*(this->modulatorEnvelope)).decay(1500);
  (*(this->modulatorEnvelope)).sustain(0);
  (*(this->modulatorEnvelope)).release(1);
  //set carrier envelope
  (*(this->carrierEnvelope)).attack(10);
  (*(this->carrierEnvelope)).hold(0);
  (*(this->carrierEnvelope)).decay(1500);
  (*(this->carrierEnvelope)).sustain(0);
  (*(this->carrierEnvelope)).release(1);
  */

  //Modulator sine * 2, carrier sine * 1 -> lush
  /*
  //set modulator envelope
  (*(this->modulatorEnvelope)).attack(50);
  (*(this->modulatorEnvelope)).hold(0);
  (*(this->modulatorEnvelope)).decay(50);
  (*(this->modulatorEnvelope)).sustain(0.25);
  (*(this->modulatorEnvelope)).release(10);
  //set carrier envelope
  (*(this->carrierEnvelope)).attack(10);
  (*(this->carrierEnvelope)).hold(0);
  (*(this->carrierEnvelope)).decay(50);
  (*(this->carrierEnvelope)).sustain(0.75);
  (*(this->carrierEnvelope)).release(150);
  */


  //Modlator sine * 0.5, carrier square * 1 -> such phatness, much wow!
  /*
  //set modulator envelope
  (*(this->modulatorEnvelope)).attack(100);
  (*(this->modulatorEnvelope)).hold(0);
  (*(this->modulatorEnvelope)).decay(100);
  (*(this->modulatorEnvelope)).sustain(0.5);
  (*(this->modulatorEnvelope)).release(10);
  //set carrier envelope
  (*(this->carrierEnvelope)).attack(10);
  (*(this->carrierEnvelope)).hold(0);
  (*(this->carrierEnvelope)).decay(50);
  (*(this->carrierEnvelope)).sustain(1);
  (*(this->carrierEnvelope)).release(50);
  */
  
}

void Voice::SetProgram(Program* program){
  this->program = program;
}

void Voice::NoteOn(byte channel, byte pitch, float level){
  this->pitch = pitch;
  this->channel = channel;
  
  AudioNoInterrupts();
  //Modulator
  (*(this->modulator)).begin((*(this->program)).GetOperatorVolume(0), midiNoteToFreq[pitch] * (*(this->program)).GetFreqMul(0) + (*(this->program)).GetFreqAdd(0), (*(this->program)).GetWaveform(0));
  (*(this->modulator)).phase(0);
  //set modulator envelope
  float *modulatorVolumeEnvelopeSettings = (*(this->program)).GetVolumeDAHDSR(0);
  (*(this->modulatorEnvelope)).delay(*(modulatorVolumeEnvelopeSettings+0));
  (*(this->modulatorEnvelope)).attack(*(modulatorVolumeEnvelopeSettings+1));
  (*(this->modulatorEnvelope)).hold(*(modulatorVolumeEnvelopeSettings+2));
  (*(this->modulatorEnvelope)).decay(*(modulatorVolumeEnvelopeSettings+3));
  (*(this->modulatorEnvelope)).sustain(*(modulatorVolumeEnvelopeSettings+4));
  (*(this->modulatorEnvelope)).release(*(modulatorVolumeEnvelopeSettings+5));
  (*(this->modulatorEnvelope)).noteOn();
  
  //Carrier
  (*(this->carrier)).begin((*(this->program)).GetOperatorVolume(1) * level, midiNoteToFreq[pitch] * (*(this->program)).GetFreqMul(1) + (*(this->program)).GetFreqAdd(1), (*(this->program)).GetWaveform(1));
  (*(this->carrier)).phase(0);
  //set carrier envelope
  float *carrierVolumeEnvelopeSettings = (*(this->program)).GetVolumeDAHDSR(1);
  (*(this->carrierEnvelope)).delay(*(carrierVolumeEnvelopeSettings+0));
  (*(this->carrierEnvelope)).attack(*(carrierVolumeEnvelopeSettings+1));
  (*(this->carrierEnvelope)).hold(*(carrierVolumeEnvelopeSettings+2));
  (*(this->carrierEnvelope)).decay(*(carrierVolumeEnvelopeSettings+3));
  (*(this->carrierEnvelope)).sustain(*(carrierVolumeEnvelopeSettings+4));
  (*(this->carrierEnvelope)).release(*(carrierVolumeEnvelopeSettings+5));
  (*(this->carrierEnvelope)).noteOn();

  
  this->isPlaying = true;
  

  AudioInterrupts();
}

void Voice::NoteOff(){
  (*(this->modulatorEnvelope)).noteOff();
  (*(this->carrierEnvelope)).noteOff();
  this->isPlaying = false;
}

bool Voice::IsPlaying(){
  //Check if isPlaying is false AND carrier envelope is finished/idling (0) or in delay phase (1)
  if((this->isPlaying == false) && ((*(this->carrierEnvelope)).isPlaying() == false)){
    return false;
  } else {
    return true;
  }
}

#endif
