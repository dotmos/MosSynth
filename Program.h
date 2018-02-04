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

    //Operator volume DADHSR [4][6]
    //Operator pitch DADHSR [4][6]

    //float feedback; //feedback amount
    //fmAlgorithm; //the fm algorithm to use (1x4 op, 2x2op, 4x1op etc.)
    //name of the program

    void Setup(short waveform[4], float freqMul[4], int16_t freqAdd[4]);
    
  public:
    Program();
    Program(short waveform[4], float freqMul[4], int16_t freqAdd[4]);

    void SetWaveform(byte operatorIndex, short waveform);
    short GetWaveform(byte operatorIndex);

    void SetFreqMul(byte operatorIndex, float factor);
    float GetFreqMul(byte operatorIndex);

    void SetFreqAdd(byte operatorIndex, int16_t hz);
    int16_t GetFreqAdd(byte operatorIndex);
};

Program::Program() {
  /*
  this->waveform = new short[4];
  for(int i=0; i<4; ++i){
    (this->waveform)[i] = WAVEFORM_SINE;//_waveform[i];  
  }
  */
  
  short _waveform[4] = {WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE};
  float _freqMul[4] = {1.0, 1.0, 1.0, 1.0};
  int16_t _freqAdd[4] = {0, 0, 0, 0};
  this->Setup(_waveform, _freqMul, _freqAdd);
}
Program::Program(short waveform[4], float freqMul[4], int16_t freqAdd[4]) {
  this->Setup(waveform, freqMul, freqAdd);
}

void Program::Setup(short waveform[4], float freqMul[4], int16_t freqAdd[4]) {

  //Copy settings
  for(int i=0; i<4; ++i){
    this->waveform[i] = waveform[i];
    this->freqMul[i] = freqMul[i];
    this->freqAdd[i] = freqAdd[i];
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

#endif
