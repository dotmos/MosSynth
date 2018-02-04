#ifndef Program_h_
#define Program_h_

class Program {
  private:
    //Waveform of operators [4]
    short waveform[4];
    //Original frequency of operator will be multiplied by this value [4]
    float freqMul[4];
    //This value (in Hz) will be added to the operator frequency after freqMul was applied [4]
    int16_t freqAdd[4];

    //Operator volume DAHDSR envelope [4][6]
    uint16_t volumeDAHDSR[4][6];
    //Operator pitch DAHDSR [4][6]

    //float feedback; //feedback amount
    //fmAlgorithm; //the fm algorithm to use (1x4 op, 2x2op, 4x1op etc.)
    //name of the program

    void Setup(short waveform[4], float freqMul[4], int16_t freqAdd[4], uint16_t volumeDAHDSR[4][6]);
    
  public:
    Program();
    Program(short waveform[4], float freqMul[4], int16_t freqAdd[4], uint16_t volumeDAHDSR[4][6]);

    void SetWaveform(byte operatorIndex, short waveform);
    short GetWaveform(byte operatorIndex);

    void SetFreqMul(byte operatorIndex, float factor);
    float GetFreqMul(byte operatorIndex);

    void SetFreqAdd(byte operatorIndex, int16_t hz);
    int16_t GetFreqAdd(byte operatorIndex);

    void SetVolumeDAHDSR(byte operatorIndex, uint16_t dahdsr[6]);
    uint16_t *GetVolumeDAHDSR(byte operatorIndex);
};

Program::Program() {
  short _waveform[4] = {WAVEFORM_SINE, WAVEFORM_SQUARE, WAVEFORM_SINE, WAVEFORM_SINE};
  float _freqMul[4] = {0.5, 1.0, 1.0, 1.0};
  int16_t _freqAdd[4] = {0, 0, 0, 0};
  /*
  uint16_t _volumeDAHDSR[4][6] = { 
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10}
  };
  */
  uint16_t _volumeDAHDSR[4][6] = { 
    {0, 2500, 0, 1, 1, 120},
    {0, 10, 0, 50, 1, 120},
    {0, 10, 0, 10, 1, 10},
    {0, 10, 0, 10, 1, 10}
  };

  this->Setup(_waveform, _freqMul, _freqAdd, _volumeDAHDSR);
}
Program::Program(short waveform[4], float freqMul[4], int16_t freqAdd[4], uint16_t volumeDAHDSR[4][6]) {
  this->Setup(waveform, freqMul, freqAdd, volumeDAHDSR);
}

void Program::Setup(short waveform[4], float freqMul[4], int16_t freqAdd[4], uint16_t volumeDAHDSR[4][6]) {

  //Copy settings
  for(int i=0; i<4; ++i){
    this->waveform[i] = waveform[i];
    this->freqMul[i] = freqMul[i];
    this->freqAdd[i] = freqAdd[i];
    this->SetVolumeDAHDSR(i, volumeDAHDSR[i]);
  }
}

//Sets the waveforms of an operator
void Program::SetWaveform(byte operatorIndex, short waveform) {
  this->waveform[operatorIndex] = waveform;
}
//Gets the waveform of an operator
short Program::GetWaveform(byte operatorIndex) {
  //byte _w[4] = {WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE};
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
void Program::SetFreqAdd(byte operatorIndex, int16_t hz) {
  this->freqAdd[operatorIndex] = hz;
}
//Get the frequency that is added to an operator
int16_t Program::GetFreqAdd(byte operatorIndex) {
  return this->freqAdd[operatorIndex];
}

//Sets the volume DAHDSR envelope for an operator
void Program::SetVolumeDAHDSR(byte operatorIndex, uint16_t dahdsr[6]){
  for(int i=0; i<6; ++i){
    this->volumeDAHDSR[operatorIndex][i] = dahdsr[i];
  }
}
//Gets the volume DAHDSR envelope for an operator
uint16_t *Program::GetVolumeDAHDSR(byte operatorIndex){
  return this->volumeDAHDSR[operatorIndex];
}

#endif
