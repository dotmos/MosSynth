class Voice{
  private:
    AudioSynthWaveform       *modulator;      //xy=393,306
    AudioEffectEnvelope      *modulatorEnvelope;      //xy=576,305
    AudioSynthWaveformModulated *carrier;
    AudioEffectEnvelope      *carrierEnvelope;      //xy=872,301
    bool isPlaying;

  public:
    byte pitch;
    Voice();
    Voice(AudioSynthWaveform *modulator, AudioEffectEnvelope *modulatorEnvelope, AudioSynthWaveformModulated *carrier, AudioEffectEnvelope *carrierEnvelope);
    void Setup(AudioSynthWaveform *modulator, AudioEffectEnvelope *modulatorEnvelope, AudioSynthWaveformModulated *carrier, AudioEffectEnvelope *carrierEnvelope);
    void NoteOn(byte pitch, float level);
    void NoteOff();
    bool IsPlaying();
};

Voice::Voice(){
}

Voice::Voice(AudioSynthWaveform *modulator, AudioEffectEnvelope *modulatorEnvelope, AudioSynthWaveformModulated *carrier, AudioEffectEnvelope *carrierEnvelope)
{
 Setup(modulator, modulatorEnvelope, carrier, carrierEnvelope);
}

void Voice::Setup(AudioSynthWaveform *modulator, AudioEffectEnvelope *modulatorEnvelope, AudioSynthWaveformModulated *carrier, AudioEffectEnvelope *carrierEnvelope){
  this->carrier = carrier;
  this->carrierEnvelope = carrierEnvelope;
  this->modulator = modulator;
  this->modulatorEnvelope = modulatorEnvelope;

  //Modulator sine * 2, Carrier sine * 1 -> ?Glockenspiel?Harp? (Zelda fairy). :)

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

void Voice::NoteOn(byte pitch, float level){
  //Modulator
  (*(this->modulator)).begin(1, midiNoteToFreq[pitch]*2, WAVEFORM_SINE);
  (*(this->modulator)).phase(0);
  (*(this->modulatorEnvelope)).noteOn();
  
  //Carrier
  (*(this->carrier)).begin(1, midiNoteToFreq[pitch], WAVEFORM_SINE);
  (*(this->carrier)).phase(0);
  (*(this->carrierEnvelope)).noteOn();

  this->pitch = pitch;
  this->isPlaying = true;
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

