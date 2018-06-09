#ifndef Program_h_
#define Program_h_

class Program {
  private:
    //Waveform of operators [2]
    short waveform[2];
    //Original frequency of operator will be multiplied by this value [2]
    float freqMul[2];
    //This value (in Hz) will be added to the operator frequency after freqMul was applied [2]
    float freqAdd[2];

    //Operator volume DAHDSR envelope [2][6]
    float volumeDAHDSR[2][6];
    //TODO: Operator pitch DAHDSR [2][6]

    //The maximum volume of the operators
    float operatorVolume[2];

    //The waveshape of the operators
    float waveshape[2][WAVESHAPE_SAMPLE_SIZE];

    //float feedback; //feedback amount
    //byte fmAlgorithm; //the fm algorithm to use (1x4 op, 2x2op, 4x1op etc.) UPDATE: This is not possible at the moment since the audio library can not really be reconnected/instanced at runtime
    //byte algorithm; //The modulation algorithm to use. Frequency modulation or phase modulation
    //string name; //name of the program

    float filterCutoff; //Filter cutoff frequency
    float filterResonance; //Filter resonance. Range 0-5. Values > 0.7 will amplify the signal near the corner frequency.
    float filterOctaveControl; //Range is 0 to 7 octaves. For example, when set to 2.5, a full scale positive signal (1.0) will shift the filter frequency up 2.5 octaves, and a full scale negative signal will shift it down 2.5 octaves.
    float filterMixer[3]; //Filter mixer settings. 0 = lowpass, 1 = bandpass, 2 = highpass
    float filterDAHDSR[6];

    void Setup(short waveform[2],
              float waveshape[2][WAVESHAPE_SAMPLE_SIZE],
              float freqMul[2],
              float freqAdd[2],
              float volumeDAHDSR[2][6],
              float operatorVolume[2],
              float filterCutoff,
              float filterResonance,
              float filterOctaveControl,
              float filterMixer[3],
              float filterDAHDSR[6]);
    
  public:
    Program();
    Program(short waveform[2],
            float waveshape[2][WAVESHAPE_SAMPLE_SIZE],
            float freqMul[2],
            float freqAdd[2],
            float volumeDAHDSR[2][6],
            float operatorVolume[2],
            float filterCutoff,
            float filterResonance,
            float filterOctaveControl,
            float filterMixer[3],
            float filterDAHDSR[6]);

    void SetWaveform(byte operatorIndex, short waveform);
    short GetWaveform(byte operatorIndex);

    void SetFreqMul(byte operatorIndex, float factor);
    float GetFreqMul(byte operatorIndex);

    void SetFreqAdd(byte operatorIndex, float hz);
    float GetFreqAdd(byte operatorIndex);

    void SetVolumeDAHDSR(byte operatorIndex, float dahdsr[6]);
    float *GetVolumeDAHDSR(byte operatorIndex);

    void SetOperatorVolume(byte operatorIndex, float volume);
    float GetOperatorVolume(byte operatorIndex);

    void SetWaveshape(byte operatorIndex, float samples[WAVESHAPE_SAMPLE_SIZE]);
    void SetWaveshape(byte operatorIndex, byte sampleIndex, float sample);
    float *GetWaveshape(byte operatorIndex);
    float GetWaveshape(byte operatorIndex, byte sampleIndex);

    void SetFilterCutoff(float cutoff);
    float GetFilterCutoff();
    void SetFilterResonance(float resonance);
    float GetFilterResonance();
    void SetFilterOctaveControl(float factor);
    float GetFilterOctaveControl();

    void SetFilterLowpassVolume(float volume);
    float GetFilterLowpassVolume();
    void SetFilterBandpassVolume(float volume);
    float GetFilterBandpassVolume();
    void SetFilterHighpassVolume(float volume);
    float GetFilterHighpassVolume();
    
    void SetFilterDAHDSR(float dahdsr[6]);
    float *GetFilterDAHDSR();
};

Program::Program() {
  short _waveform[2] = {WAVEFORM_SINE, WAVEFORM_SINE};
  float _freqMul[2] = {1.0, 1.0};
  float _freqAdd[2] = {0.0, 0.0};
  /*
  uint16_t _volumeDAHDSR[4][6] = { 
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10}
  };
  */
  float _volumeDAHDSR[2][6] = { 
    {0, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 1, 1}
    //{0, 1, 0, 1, 1, 1},
    //{0, 1, 0, 1, 1, 1}
  };

  float _operatorVolume[2] = {0, 1};

  float _waveshape[2][WAVESHAPE_SAMPLE_SIZE] = {
    {-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1},
    {-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1}
  };

  float _filterMixer[3] = {1,1,1};
  float _filterDAHDSR[6] = {0, 0,0,0,0,0};

  this->Setup(_waveform, _waveshape, _freqMul, _freqAdd, _volumeDAHDSR, _operatorVolume, 11025, 0.707, 0, _filterMixer, _filterDAHDSR);
}
Program::Program(short waveform[2],
                float waveshape[2][WAVESHAPE_SAMPLE_SIZE],
                float freqMul[2],
                float freqAdd[2],
                float volumeDAHDSR[2][6],
                float operatorVolume[2],
                float filterCutoff,
                float filterResonance,
                float filterOctaveControl,
                float filterMixer[3],
                float filterDAHDSR[6]) {
  this->Setup(waveform, waveshape, freqMul, freqAdd, volumeDAHDSR, operatorVolume, filterCutoff, filterResonance, filterOctaveControl, filterMixer, filterDAHDSR);
}

void Program::Setup(short waveform[2],
                    float waveshape[2][WAVESHAPE_SAMPLE_SIZE],
                    float freqMul[2],
                    float freqAdd[2],
                    float volumeDAHDSR[2][6],
                    float operatorVolume[2],
                    float filterCutoff,
                    float filterResonance,
                    float filterOctaveControl,
                    float filterMixer[3],
                    float filterDAHDSR[6]) {

  //TODO: Reset settings and free memory
  
  //Copy settings
  for(int i=0; i<2; ++i){
    this->waveform[i] = waveform[i];
    this->freqMul[i] = freqMul[i];
    this->freqAdd[i] = freqAdd[i];
    this->SetVolumeDAHDSR(i, volumeDAHDSR[i]);
    this->SetOperatorVolume(i, operatorVolume[i]);
    this->SetWaveshape(i, waveshape[i]);
  }

  this->SetFilterCutoff(filterCutoff);
  this->SetFilterResonance(filterResonance);
  this->SetFilterOctaveControl(filterOctaveControl);
  this->SetFilterLowpassVolume(filterMixer[0]);
  this->SetFilterBandpassVolume(filterMixer[1]);
  this->SetFilterHighpassVolume(filterMixer[2]);
  this->SetFilterDAHDSR(filterDAHDSR);
}

//Sets the waveforms of an operator
void Program::SetWaveform(byte operatorIndex, short waveform) {
  this->waveform[operatorIndex] = waveform;
}
//Gets the waveform of an operator
short Program::GetWaveform(byte operatorIndex) {
  //byte _w[2] = {WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE};
  //byte *test;
  //return *(test+0) // *(test+1) *(test+2)
  return this->waveform[operatorIndex];
}

//Sets the frequency multiplicator of an operator
void Program::SetFreqMul(byte operatorIndex, float factor) {
  this->freqMul[operatorIndex] = factor;
}
//Gets the frequency multiplicator of an operator
float Program::GetFreqMul(byte operatorIndex) {
  return this->freqMul[operatorIndex];
}

//Sets a frequency to be added to an operator
void Program::SetFreqAdd(byte operatorIndex, float hz) {
  this->freqAdd[operatorIndex] = hz;
}
//Get the frequency that is added to an operator
float Program::GetFreqAdd(byte operatorIndex) {
  return this->freqAdd[operatorIndex];
}

//Sets the volume DAHDSR envelope for an operator
void Program::SetVolumeDAHDSR(byte operatorIndex, float dahdsr[6]){
  for(int i=0; i<6; ++i){
    this->volumeDAHDSR[operatorIndex][i] = dahdsr[i];
  }
}
//Gets the volume DAHDSR envelope for an operator
float *Program::GetVolumeDAHDSR(byte operatorIndex){
  return this->volumeDAHDSR[operatorIndex];
}

void Program::SetOperatorVolume(byte operatorIndex, float volume){
  this->operatorVolume[operatorIndex] = volume;
}
float Program::GetOperatorVolume(byte operatorIndex){
  return this->operatorVolume[operatorIndex];
}

void Program::SetWaveshape(byte operatorIndex, float samples[WAVESHAPE_SAMPLE_SIZE]){
  for(int i=0; i<WAVESHAPE_SAMPLE_SIZE; ++i){
    this->waveshape[operatorIndex][i] = samples[i];
  }
}
void Program::SetWaveshape(byte operatorIndex, byte sampleIndex, float sample){
  this->waveshape[operatorIndex][sampleIndex] = sample;
}
float *Program::GetWaveshape(byte operatorIndex){
  return this->waveshape[operatorIndex];
}
float Program::GetWaveshape(byte operatorIndex, byte sampleIndex){
  return this->waveshape[operatorIndex][sampleIndex];
}

void Program::SetFilterCutoff(float cutoff){
  this->filterCutoff = cutoff;
}
float Program::GetFilterCutoff(){
  return this->filterCutoff;
}

void Program::SetFilterResonance(float resonance){
  this->filterResonance = resonance;
}
float Program::GetFilterResonance(){
  return this->filterResonance;
}

void Program::SetFilterOctaveControl(float factor){
  this->filterOctaveControl = factor;
}
float Program::GetFilterOctaveControl(){
  return this->filterOctaveControl;
}

void Program::SetFilterLowpassVolume(float volume){
  this->filterMixer[0] = volume;
}
float Program::GetFilterLowpassVolume(){
  return this->filterMixer[0];
}

void Program::SetFilterBandpassVolume(float volume){
  this->filterMixer[1] = volume;
}
float Program::GetFilterBandpassVolume(){
  return this->filterMixer[1];
}

void Program::SetFilterHighpassVolume(float volume){
  this->filterMixer[2] = volume;
}
float Program::GetFilterHighpassVolume(){
  return this->filterMixer[2];
}

void Program::SetFilterDAHDSR(float dahdsr[6]){
  for(int i=0; i<6; ++i){
    this->filterDAHDSR[i] = dahdsr[i];
  }
}
float *Program::GetFilterDAHDSR(){
  return this->filterDAHDSR;
}
#endif
