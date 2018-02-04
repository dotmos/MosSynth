class Program{
  private:
    //The waveformtype to use for an operator 
    byte *waveform;
    //Original frequency will be multiplied by this value
    float *freqMul;
    //This value (in Hz) will be added to the frequency after freqMul was applied
    int16_t *freqAdd;

    //float feedback; //feedback amount
    //fmAlgorithm; //the fm algorithm to use (1x4 op, 2x2op, 4x1op etc.)
    //name of the program

    void Setup(byte waveform[4], float freqMul[4], int16_t freqAdd[4]);

  public:
    Program();
    Program(byte waveform[4], float freqMul[4], int16_t freqAdd[4]);
    
    void SetWaveform(byte operatorIndex, byte waveform);
    byte GetWaveform(byte operatorIndex);

    void SetFreqMul(byte operatorIndex, float factor);
    float GetFreqMul(byte operatorIndex);

    void SetFreqAdd(byte operatorIndex, int16_t hz);
    int16_t GetFreqAdd(byte operatorIndex);
};

Program::Program(){
  byte _waveform[4] = {WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE, WAVEFORM_SINE};
  float _freqMul[4] = {1.0, 1.0, 1.0, 1.0};
  int16_t _freqAdd[4] = {0, 0, 0, 0};
  this->Setup(_waveform, _freqMul, _freqAdd);
}

Program::Program(byte waveform[4], float freqMul[4], int16_t freqAdd[4]){
  this->Setup(waveform, freqMul, freqAdd);
}

void Program::Setup(byte waveform[4], float freqMul[4], int16_t freqAdd[4]){
  this->waveform = waveform;
  this->freqMul = freqMul;
  this->freqAdd = freqAdd;
}

//Sets the waveforms of an operator
void Program::SetWaveform(byte operatorIndex, byte waveform){
  this->waveform[operatorIndex] = waveform;
}
//Gets the waveform of an operator
byte Program::GetWaveform(byte operatorIndex){
  return this->waveform[operatorIndex];
}

//Sets the frequency multiplicator of an operator
void Program::SetFreqMul(byte operatorIndex, float factor){
  this->freqMul[operatorIndex] = factor;
}
//Gets the frequency multiplicator of an operator
float Program::GetFreqMul(byte operatorIndex){
  return this->freqMul[operatorIndex];
}

//Sets a frequency to be added to an operator
void Program::SetFreqAdd(byte operatorIndex, int16_t hz){
  this->freqAdd[operatorIndex] = hz;
}
//Get the frequency that is added to an operator
int16_t Program::GetFreqAdd(byte operatorIndex){
  return this->freqAdd[operatorIndex];
}

