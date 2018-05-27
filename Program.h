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

    void Setup(short waveform[2], float waveshape[2][WAVESHAPE_SAMPLE_SIZE], float freqMul[2], float freqAdd[2], float volumeDAHDSR[2][6], float operatorVolume[2]);
    
  public:
    Program();
    Program(short waveform[2], float waveshape[2][WAVESHAPE_SAMPLE_SIZE], float freqMul[2], float freqAdd[2], float volumeDAHDSR[2][6], float operatorVolume[2]);

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
};

Program::Program() {
  short _waveform[2] = {WAVEFORM_SINE, WAVEFORM_SQUARE};
  float _freqMul[2] = {0.5, 1.0};
  float _freqAdd[2] = {0.0, 0};
  /*
  uint16_t _volumeDAHDSR[4][6] = { 
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10}
  };
  */
  float _volumeDAHDSR[2][6] = { 
    {0, 2500, 0, 1, 1, 120},
    {0, 10, 0, 50, 1, 120}
    //{0, 10, 0, 10, 1, 10},
    //{0, 10, 0, 10, 1, 10}
  };

  float _operatorVolume[2] = {0.1, 0.5};

  float _waveshape[2][WAVESHAPE_SAMPLE_SIZE] = {
    {-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1},
    {-1, -0.875, -0.75, -0.625, -0.5, -0.375, -0.25, -0.125, 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1}
  };

  this->Setup(_waveform, _waveshape, _freqMul, _freqAdd, _volumeDAHDSR, _operatorVolume);
}
Program::Program(short waveform[2], float waveshape[2][WAVESHAPE_SAMPLE_SIZE], float freqMul[2], float freqAdd[2], float volumeDAHDSR[2][6], float operatorVolume[2]) {
  this->Setup(waveform, waveshape, freqMul, freqAdd, volumeDAHDSR, operatorVolume);
}

void Program::Setup(short waveform[2], float waveshape[2][WAVESHAPE_SAMPLE_SIZE], float freqMul[2], float freqAdd[2], float volumeDAHDSR[2][6], float operatorVolume[2]) {

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

#endif
