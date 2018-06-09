/*
 * TODO:
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
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     dc1;            //xy=74,906
AudioSynthWaveformModulated modulator12; //xy=256,914
AudioSynthWaveformModulated modulator13; //xy=259,993
AudioSynthWaveformModulated modulator14; //xy=261,1071
AudioSynthWaveformModulated modulator11; //xy=262,836
AudioSynthWaveformModulated modulator17;  //xy=261,1297
AudioSynthWaveformModulated modulator3; //xy=266,230
AudioSynthWaveformModulated modulator4; //xy=266,306
AudioSynthWaveformModulated modulator5; //xy=266,385
AudioSynthWaveformModulated modulator15; //xy=263,1146
AudioSynthWaveformModulated modulator16; //xy=263,1222
AudioSynthWaveformModulated modulator1;     //xy=268,77
AudioSynthWaveformModulated modulator2; //xy=268,157
AudioSynthWaveformModulated modulator10; //xy=266,760
AudioSynthWaveformModulated modulator18; //xy=264,1374
AudioSynthWaveformModulated modulator19; //xy=265,1453
AudioSynthWaveformModulated modulator6; //xy=269,460
AudioSynthWaveformModulated modulator20; //xy=265,1528
AudioSynthWaveformModulated modulator7; //xy=270,534
AudioSynthWaveformModulated modulator8; //xy=272,610
AudioSynthWaveformModulated modulator9; //xy=272,687
AudioEffectWaveshaper    modulatorWaveshape12; //xy=443,913
AudioEffectWaveshaper    modulatorWaveshape5; //xy=448,384
AudioEffectWaveshaper    modulatorWaveshape3; //xy=450,228
AudioEffectWaveshaper    modulatorWaveshape2; //xy=451,156
AudioEffectWaveshaper    modulatorWaveshape4; //xy=451,305
AudioEffectWaveshaper    modulatorWaveshape14; //xy=450,1068
AudioEffectWaveshaper    modulatorWaveshape7; //xy=453,533
AudioEffectWaveshaper    modulatorWaveshape17; //xy=450,1295
AudioEffectWaveshaper    modulatorWaveshape1;     //xy=455,77
AudioEffectWaveshaper    modulatorWaveshape11; //xy=452,836
AudioEffectWaveshaper    modulatorWaveshape13; //xy=452,992
AudioEffectWaveshaper    modulatorWaveshape10; //xy=453,760
AudioEffectWaveshaper    modulatorWaveshape6; //xy=455,460
AudioEffectWaveshaper    modulatorWaveshape15; //xy=453,1144
AudioEffectWaveshaper    modulatorWaveshape9; //xy=455,685
AudioEffectWaveshaper    modulatorWaveshape8; //xy=456,611
AudioEffectWaveshaper    modulatorWaveshape19; //xy=455,1452
AudioEffectWaveshaper    modulatorWaveshape16; //xy=456,1222
AudioEffectWaveshaper    modulatorWaveshape18; //xy=457,1372
AudioEffectWaveshaper    modulatorWaveshape20; //xy=457,1527
AudioEffectEnvelope      modulatorEnvelope3; //xy=664,229
AudioEffectEnvelope      modulatorEnvelope4; //xy=664,305
AudioEffectEnvelope      modulatorEnvelope5; //xy=664,384
AudioEffectEnvelope      modulatorEnvelope1; //xy=666,76
AudioEffectEnvelope      modulatorEnvelope2; //xy=666,156
AudioEffectEnvelope      modulatorEnvelope6; //xy=667,459
AudioEffectEnvelope      modulatorEnvelope12; //xy=666,912
AudioEffectEnvelope      modulatorEnvelope10; //xy=667,760
AudioEffectEnvelope      modulatorEnvelope7; //xy=668,533
AudioEffectEnvelope      modulatorEnvelope11; //xy=667,837
AudioEffectEnvelope      modulatorEnvelope8; //xy=670,609
AudioEffectEnvelope      modulatorEnvelope9; //xy=670,686
AudioEffectEnvelope      modulatorEnvelope13; //xy=669,991
AudioEffectEnvelope      modulatorEnvelope14; //xy=671,1069
AudioEffectEnvelope      modulatorEnvelope17; //xy=671,1295
AudioEffectEnvelope      modulatorEnvelope15; //xy=673,1144
AudioEffectEnvelope      modulatorEnvelope16; //xy=673,1220
AudioEffectEnvelope      modulatorEnvelope18; //xy=674,1372
AudioEffectEnvelope      modulatorEnvelope19; //xy=675,1451
AudioEffectEnvelope      modulatorEnvelope20; //xy=675,1526
AudioSynthWaveformModulated carrier3; //xy=835,229
AudioSynthWaveformModulated carrier4; //xy=835,305
AudioSynthWaveformModulated carrier5; //xy=835,384
AudioSynthWaveformModulated carrier1;       //xy=837,76
AudioSynthWaveformModulated carrier2; //xy=837,156
AudioSynthWaveformModulated carrier6; //xy=838,459
AudioSynthWaveformModulated carrier12; //xy=837,912
AudioSynthWaveformModulated carrier10; //xy=838,760
AudioSynthWaveformModulated carrier7; //xy=839,533
AudioSynthWaveformModulated carrier11; //xy=838,837
AudioSynthWaveformModulated carrier8; //xy=841,609
AudioSynthWaveformModulated carrier9; //xy=841,686
AudioSynthWaveformModulated carrier13; //xy=840,991
AudioSynthWaveformModulated carrier14; //xy=842,1069
AudioSynthWaveformModulated carrier17; //xy=842,1295
AudioSynthWaveformModulated carrier15; //xy=844,1144
AudioSynthWaveformModulated carrier16; //xy=844,1220
AudioSynthWaveformModulated carrier18; //xy=845,1372
AudioSynthWaveformModulated carrier19; //xy=846,1451
AudioSynthWaveformModulated carrier20; //xy=846,1526
AudioEffectWaveshaper    carrierWaveshape4; //xy=1002,305
AudioEffectWaveshaper    carrierWaveshape5; //xy=1002,382
AudioEffectWaveshaper    carrierWaveshape1;     //xy=1006,76
AudioEffectWaveshaper    carrierWaveshape3; //xy=1006,227
AudioEffectWaveshaper    carrierWaveshape12; //xy=1004,911
AudioEffectWaveshaper    carrierWaveshape7; //xy=1007,533
AudioEffectWaveshaper    carrierWaveshape11; //xy=1006,835
AudioEffectWaveshaper    carrierWaveshape8; //xy=1007,609
AudioEffectWaveshaper    carrierWaveshape10; //xy=1007,759
AudioEffectWaveshaper    carrierWaveshape2; //xy=1010,157
AudioEffectWaveshaper    carrierWaveshape6; //xy=1009,459
AudioEffectWaveshaper    carrierWaveshape13; //xy=1007,990
AudioEffectWaveshaper    carrierWaveshape9; //xy=1009,686
AudioEffectWaveshaper    carrierWaveshape15; //xy=1010,1143
AudioEffectWaveshaper    carrierWaveshape17; //xy=1010,1295
AudioEffectWaveshaper    carrierWaveshape14; //xy=1012,1069
AudioEffectWaveshaper    carrierWaveshape16; //xy=1012,1219
AudioEffectWaveshaper    carrierWaveshape20; //xy=1013,1527
AudioEffectWaveshaper    carrierWaveshape19; //xy=1015,1451
AudioEffectWaveshaper    carrierWaveshape18; //xy=1016,1372
AudioEffectEnvelope      carrierEnvelope3; //xy=1200,229
AudioEffectEnvelope      carrierEnvelope4; //xy=1200,305
AudioEffectEnvelope      carrierEnvelope5; //xy=1200,384
AudioEffectEnvelope      carrierEnvelope1; //xy=1202,76
AudioEffectEnvelope      carrierEnvelope2; //xy=1202,156
AudioEffectEnvelope      carrierEnvelope6; //xy=1203,459
AudioEffectEnvelope      carrierEnvelope12; //xy=1202,912
AudioEffectEnvelope      carrierEnvelope10; //xy=1203,760
AudioEffectEnvelope      filterEnvelope3; //xy=1205,267
AudioEffectEnvelope      carrierEnvelope7; //xy=1204,533
AudioEffectEnvelope      carrierEnvelope11; //xy=1203,837
AudioEffectEnvelope      filterEnvelope4; //xy=1205,343
AudioEffectEnvelope      filterEnvelope5; //xy=1205,422
AudioEffectEnvelope      filterEnvelope1;      //xy=1207,114
AudioEffectEnvelope      filterEnvelope2; //xy=1207,194
AudioEffectEnvelope      carrierEnvelope8; //xy=1206,609
AudioEffectEnvelope      carrierEnvelope9; //xy=1206,686
AudioEffectEnvelope      carrierEnvelope13; //xy=1205,991
AudioEffectEnvelope      filterEnvelope6; //xy=1208,497
AudioEffectEnvelope      filterEnvelope12; //xy=1207,950
AudioEffectEnvelope      filterEnvelope10; //xy=1208,798
AudioEffectEnvelope      carrierEnvelope14; //xy=1207,1069
AudioEffectEnvelope      filterEnvelope7; //xy=1209,571
AudioEffectEnvelope      filterEnvelope11; //xy=1208,875
AudioEffectEnvelope      carrierEnvelope17; //xy=1207,1295
AudioEffectEnvelope      carrierEnvelope15; //xy=1209,1144
AudioEffectEnvelope      filterEnvelope8; //xy=1211,647
AudioEffectEnvelope      carrierEnvelope16; //xy=1209,1220
AudioEffectEnvelope      filterEnvelope9; //xy=1211,724
AudioEffectEnvelope      filterEnvelope13; //xy=1210,1029
AudioEffectEnvelope      carrierEnvelope18; //xy=1210,1372
AudioEffectEnvelope      filterEnvelope14; //xy=1212,1107
AudioEffectEnvelope      carrierEnvelope19; //xy=1211,1451
AudioEffectEnvelope      carrierEnvelope20; //xy=1211,1526
AudioEffectEnvelope      filterEnvelope17; //xy=1212,1333
AudioEffectEnvelope      filterEnvelope15; //xy=1214,1182
AudioEffectEnvelope      filterEnvelope16; //xy=1214,1258
AudioEffectEnvelope      filterEnvelope18; //xy=1215,1410
AudioEffectEnvelope      filterEnvelope19; //xy=1216,1489
AudioEffectEnvelope      filterEnvelope20;  //xy=1216,1564
AudioFilterStateVariable filter3; //xy=1363,236
AudioFilterStateVariable filter4; //xy=1363,312
AudioFilterStateVariable filter5; //xy=1363,391
AudioFilterStateVariable filter1;        //xy=1365,83
AudioFilterStateVariable filter2; //xy=1365,163
AudioFilterStateVariable filter6; //xy=1366,466
AudioFilterStateVariable filter12; //xy=1365,919
AudioFilterStateVariable filter10; //xy=1366,767
AudioFilterStateVariable filter7; //xy=1367,540
AudioFilterStateVariable filter11; //xy=1366,844
AudioFilterStateVariable filter8; //xy=1369,616
AudioFilterStateVariable filter9; //xy=1369,693
AudioFilterStateVariable filter13; //xy=1368,998
AudioFilterStateVariable filter14; //xy=1370,1076
AudioFilterStateVariable filter17; //xy=1370,1302
AudioFilterStateVariable filter15; //xy=1372,1151
AudioFilterStateVariable filter16; //xy=1372,1227
AudioFilterStateVariable filter18; //xy=1373,1379
AudioFilterStateVariable filter19; //xy=1374,1458
AudioFilterStateVariable filter20; //xy=1374,1533
AudioMixer4              filterMixer3; //xy=1504,233
AudioMixer4              filterMixer4; //xy=1504,309
AudioMixer4              filterMixer5; //xy=1504,388
AudioMixer4              filterMixer1;         //xy=1506,80
AudioMixer4              filterMixer2; //xy=1506,160
AudioMixer4              filterMixer6; //xy=1507,463
AudioMixer4              filterMixer12; //xy=1506,916
AudioMixer4              filterMixer10; //xy=1507,764
AudioMixer4              filterMixer7; //xy=1508,537
AudioMixer4              filterMixer11; //xy=1507,841
AudioMixer4              filterMixer8; //xy=1510,613
AudioMixer4              filterMixer9; //xy=1510,690
AudioMixer4              filterMixer13; //xy=1509,995
AudioMixer4              filterMixer14; //xy=1511,1073
AudioMixer4              filterMixer17; //xy=1511,1299
AudioMixer4              filterMixer15; //xy=1513,1148
AudioMixer4              filterMixer16; //xy=1513,1224
AudioMixer4              filterMixer18; //xy=1514,1376
AudioMixer4              filterMixer19; //xy=1515,1455
AudioMixer4              filterMixer20; //xy=1515,1530
AudioMixer4              mixer1;         //xy=1672,177
AudioMixer4              mixer2;         //xy=1684,485
AudioMixer4              mixer3;         //xy=1695,808
AudioMixer4              mixer6;         //xy=1703,1415
AudioMixer4              mixer4;         //xy=1705,1110
AudioMixer4              mixer5;         //xy=1844,425
AudioMixer4              mixerMaster;    //xy=2034,558
AudioOutputI2S           i2s1;           //xy=2202,558
AudioConnection          patchCord1(dc1, filterEnvelope1);
AudioConnection          patchCord2(dc1, filterEnvelope2);
AudioConnection          patchCord3(dc1, filterEnvelope3);
AudioConnection          patchCord4(dc1, filterEnvelope4);
AudioConnection          patchCord5(dc1, filterEnvelope5);
AudioConnection          patchCord6(dc1, filterEnvelope6);
AudioConnection          patchCord7(dc1, filterEnvelope7);
AudioConnection          patchCord8(dc1, filterEnvelope8);
AudioConnection          patchCord9(dc1, filterEnvelope9);
AudioConnection          patchCord10(dc1, filterEnvelope10);
AudioConnection          patchCord11(dc1, filterEnvelope11);
AudioConnection          patchCord12(dc1, filterEnvelope12);
AudioConnection          patchCord13(dc1, filterEnvelope13);
AudioConnection          patchCord14(dc1, filterEnvelope14);
AudioConnection          patchCord15(dc1, filterEnvelope15);
AudioConnection          patchCord16(dc1, filterEnvelope16);
AudioConnection          patchCord17(dc1, filterEnvelope17);
AudioConnection          patchCord18(dc1, filterEnvelope18);
AudioConnection          patchCord19(dc1, filterEnvelope19);
AudioConnection          patchCord20(dc1, filterEnvelope20);
AudioConnection          patchCord21(modulator12, modulatorWaveshape12);
AudioConnection          patchCord22(modulator13, modulatorWaveshape13);
AudioConnection          patchCord23(modulator14, modulatorWaveshape14);
AudioConnection          patchCord24(modulator11, modulatorWaveshape11);
AudioConnection          patchCord25(modulator17, modulatorWaveshape17);
AudioConnection          patchCord26(modulator3, modulatorWaveshape3);
AudioConnection          patchCord27(modulator4, modulatorWaveshape4);
AudioConnection          patchCord28(modulator5, modulatorWaveshape5);
AudioConnection          patchCord29(modulator15, modulatorWaveshape15);
AudioConnection          patchCord30(modulator16, modulatorWaveshape16);
AudioConnection          patchCord31(modulator1, modulatorWaveshape1);
AudioConnection          patchCord32(modulator2, modulatorWaveshape2);
AudioConnection          patchCord33(modulator10, modulatorWaveshape10);
AudioConnection          patchCord34(modulator18, modulatorWaveshape18);
AudioConnection          patchCord35(modulator19, modulatorWaveshape19);
AudioConnection          patchCord36(modulator6, modulatorWaveshape6);
AudioConnection          patchCord37(modulator20, modulatorWaveshape20);
AudioConnection          patchCord38(modulator7, modulatorWaveshape7);
AudioConnection          patchCord39(modulator8, modulatorWaveshape8);
AudioConnection          patchCord40(modulator9, modulatorWaveshape9);
AudioConnection          patchCord41(modulatorWaveshape12, modulatorEnvelope12);
AudioConnection          patchCord42(modulatorWaveshape5, modulatorEnvelope5);
AudioConnection          patchCord43(modulatorWaveshape3, modulatorEnvelope3);
AudioConnection          patchCord44(modulatorWaveshape2, modulatorEnvelope2);
AudioConnection          patchCord45(modulatorWaveshape4, modulatorEnvelope4);
AudioConnection          patchCord46(modulatorWaveshape14, modulatorEnvelope14);
AudioConnection          patchCord47(modulatorWaveshape7, modulatorEnvelope7);
AudioConnection          patchCord48(modulatorWaveshape17, modulatorEnvelope17);
AudioConnection          patchCord49(modulatorWaveshape1, modulatorEnvelope1);
AudioConnection          patchCord50(modulatorWaveshape11, modulatorEnvelope11);
AudioConnection          patchCord51(modulatorWaveshape13, modulatorEnvelope13);
AudioConnection          patchCord52(modulatorWaveshape10, modulatorEnvelope10);
AudioConnection          patchCord53(modulatorWaveshape6, modulatorEnvelope6);
AudioConnection          patchCord54(modulatorWaveshape15, modulatorEnvelope15);
AudioConnection          patchCord55(modulatorWaveshape9, modulatorEnvelope9);
AudioConnection          patchCord56(modulatorWaveshape8, modulatorEnvelope8);
AudioConnection          patchCord57(modulatorWaveshape19, modulatorEnvelope19);
AudioConnection          patchCord58(modulatorWaveshape16, modulatorEnvelope16);
AudioConnection          patchCord59(modulatorWaveshape18, modulatorEnvelope18);
AudioConnection          patchCord60(modulatorWaveshape20, modulatorEnvelope20);
AudioConnection          patchCord61(modulatorEnvelope3, 0, carrier3, 0);
AudioConnection          patchCord62(modulatorEnvelope4, 0, carrier4, 0);
AudioConnection          patchCord63(modulatorEnvelope5, 0, carrier5, 0);
AudioConnection          patchCord64(modulatorEnvelope1, 0, carrier1, 0);
AudioConnection          patchCord65(modulatorEnvelope2, 0, carrier2, 0);
AudioConnection          patchCord66(modulatorEnvelope6, 0, carrier6, 0);
AudioConnection          patchCord67(modulatorEnvelope12, 0, carrier12, 0);
AudioConnection          patchCord68(modulatorEnvelope10, 0, carrier10, 0);
AudioConnection          patchCord69(modulatorEnvelope7, 0, carrier7, 0);
AudioConnection          patchCord70(modulatorEnvelope11, 0, carrier11, 0);
AudioConnection          patchCord71(modulatorEnvelope8, 0, carrier8, 0);
AudioConnection          patchCord72(modulatorEnvelope9, 0, carrier9, 0);
AudioConnection          patchCord73(modulatorEnvelope13, 0, carrier13, 0);
AudioConnection          patchCord74(modulatorEnvelope14, 0, carrier14, 0);
AudioConnection          patchCord75(modulatorEnvelope17, 0, carrier17, 0);
AudioConnection          patchCord76(modulatorEnvelope15, 0, carrier15, 0);
AudioConnection          patchCord77(modulatorEnvelope16, 0, carrier16, 0);
AudioConnection          patchCord78(modulatorEnvelope18, 0, carrier18, 0);
AudioConnection          patchCord79(modulatorEnvelope19, 0, carrier19, 0);
AudioConnection          patchCord80(modulatorEnvelope20, 0, carrier20, 0);
AudioConnection          patchCord81(carrier3, carrierWaveshape3);
AudioConnection          patchCord82(carrier4, carrierWaveshape4);
AudioConnection          patchCord83(carrier5, carrierWaveshape5);
AudioConnection          patchCord84(carrier1, carrierWaveshape1);
AudioConnection          patchCord85(carrier2, carrierWaveshape2);
AudioConnection          patchCord86(carrier6, carrierWaveshape6);
AudioConnection          patchCord87(carrier12, carrierWaveshape12);
AudioConnection          patchCord88(carrier10, carrierWaveshape10);
AudioConnection          patchCord89(carrier7, carrierWaveshape7);
AudioConnection          patchCord90(carrier11, carrierWaveshape11);
AudioConnection          patchCord91(carrier8, carrierWaveshape8);
AudioConnection          patchCord92(carrier9, carrierWaveshape9);
AudioConnection          patchCord93(carrier13, carrierWaveshape13);
AudioConnection          patchCord94(carrier14, carrierWaveshape14);
AudioConnection          patchCord95(carrier17, carrierWaveshape17);
AudioConnection          patchCord96(carrier15, carrierWaveshape15);
AudioConnection          patchCord97(carrier16, carrierWaveshape16);
AudioConnection          patchCord98(carrier18, carrierWaveshape18);
AudioConnection          patchCord99(carrier19, carrierWaveshape19);
AudioConnection          patchCord100(carrier20, carrierWaveshape20);
AudioConnection          patchCord101(carrierWaveshape4, carrierEnvelope4);
AudioConnection          patchCord102(carrierWaveshape5, carrierEnvelope5);
AudioConnection          patchCord103(carrierWaveshape1, carrierEnvelope1);
AudioConnection          patchCord104(carrierWaveshape3, carrierEnvelope3);
AudioConnection          patchCord105(carrierWaveshape12, carrierEnvelope12);
AudioConnection          patchCord106(carrierWaveshape7, carrierEnvelope7);
AudioConnection          patchCord107(carrierWaveshape11, carrierEnvelope11);
AudioConnection          patchCord108(carrierWaveshape8, carrierEnvelope8);
AudioConnection          patchCord109(carrierWaveshape10, carrierEnvelope10);
AudioConnection          patchCord110(carrierWaveshape2, carrierEnvelope2);
AudioConnection          patchCord111(carrierWaveshape6, carrierEnvelope6);
AudioConnection          patchCord112(carrierWaveshape13, carrierEnvelope13);
AudioConnection          patchCord113(carrierWaveshape9, carrierEnvelope9);
AudioConnection          patchCord114(carrierWaveshape15, carrierEnvelope15);
AudioConnection          patchCord115(carrierWaveshape17, carrierEnvelope17);
AudioConnection          patchCord116(carrierWaveshape14, carrierEnvelope14);
AudioConnection          patchCord117(carrierWaveshape16, carrierEnvelope16);
AudioConnection          patchCord118(carrierWaveshape20, carrierEnvelope20);
AudioConnection          patchCord119(carrierWaveshape19, carrierEnvelope19);
AudioConnection          patchCord120(carrierWaveshape18, carrierEnvelope18);
AudioConnection          patchCord121(carrierEnvelope3, 0, filter3, 0);
AudioConnection          patchCord122(carrierEnvelope4, 0, filter4, 0);
AudioConnection          patchCord123(carrierEnvelope5, 0, filter5, 0);
AudioConnection          patchCord124(carrierEnvelope1, 0, filter1, 0);
AudioConnection          patchCord125(carrierEnvelope2, 0, filter2, 0);
AudioConnection          patchCord126(carrierEnvelope6, 0, filter6, 0);
AudioConnection          patchCord127(carrierEnvelope12, 0, filter12, 0);
AudioConnection          patchCord128(carrierEnvelope10, 0, filter10, 0);
AudioConnection          patchCord129(filterEnvelope3, 0, filter3, 1);
AudioConnection          patchCord130(carrierEnvelope7, 0, filter7, 0);
AudioConnection          patchCord131(carrierEnvelope11, 0, filter11, 0);
AudioConnection          patchCord132(filterEnvelope4, 0, filter4, 1);
AudioConnection          patchCord133(filterEnvelope5, 0, filter5, 1);
AudioConnection          patchCord134(filterEnvelope1, 0, filter1, 1);
AudioConnection          patchCord135(filterEnvelope2, 0, filter2, 1);
AudioConnection          patchCord136(carrierEnvelope8, 0, filter8, 0);
AudioConnection          patchCord137(carrierEnvelope9, 0, filter9, 0);
AudioConnection          patchCord138(carrierEnvelope13, 0, filter13, 0);
AudioConnection          patchCord139(filterEnvelope6, 0, filter6, 1);
AudioConnection          patchCord140(filterEnvelope12, 0, filter12, 1);
AudioConnection          patchCord141(filterEnvelope10, 0, filter10, 1);
AudioConnection          patchCord142(carrierEnvelope14, 0, filter14, 0);
AudioConnection          patchCord143(filterEnvelope7, 0, filter7, 1);
AudioConnection          patchCord144(filterEnvelope11, 0, filter11, 1);
AudioConnection          patchCord145(carrierEnvelope17, 0, filter17, 0);
AudioConnection          patchCord146(carrierEnvelope15, 0, filter15, 0);
AudioConnection          patchCord147(filterEnvelope8, 0, filter8, 1);
AudioConnection          patchCord148(carrierEnvelope16, 0, filter16, 0);
AudioConnection          patchCord149(filterEnvelope9, 0, filter9, 1);
AudioConnection          patchCord150(filterEnvelope13, 0, filter13, 1);
AudioConnection          patchCord151(carrierEnvelope18, 0, filter18, 0);
AudioConnection          patchCord152(filterEnvelope14, 0, filter14, 1);
AudioConnection          patchCord153(carrierEnvelope19, 0, filter19, 0);
AudioConnection          patchCord154(carrierEnvelope20, 0, filter20, 0);
AudioConnection          patchCord155(filterEnvelope17, 0, filter17, 1);
AudioConnection          patchCord156(filterEnvelope15, 0, filter15, 1);
AudioConnection          patchCord157(filterEnvelope16, 0, filter16, 1);
AudioConnection          patchCord158(filterEnvelope18, 0, filter18, 1);
AudioConnection          patchCord159(filterEnvelope19, 0, filter19, 1);
AudioConnection          patchCord160(filterEnvelope20, 0, filter20, 1);
AudioConnection          patchCord161(filter3, 0, filterMixer3, 0);
AudioConnection          patchCord162(filter3, 1, filterMixer3, 1);
AudioConnection          patchCord163(filter3, 2, filterMixer3, 2);
AudioConnection          patchCord164(filter4, 0, filterMixer4, 0);
AudioConnection          patchCord165(filter4, 1, filterMixer4, 1);
AudioConnection          patchCord166(filter4, 2, filterMixer4, 2);
AudioConnection          patchCord167(filter5, 0, filterMixer5, 0);
AudioConnection          patchCord168(filter5, 1, filterMixer5, 1);
AudioConnection          patchCord169(filter5, 2, filterMixer5, 2);
AudioConnection          patchCord170(filter1, 0, filterMixer1, 0);
AudioConnection          patchCord171(filter1, 1, filterMixer1, 1);
AudioConnection          patchCord172(filter1, 2, filterMixer1, 2);
AudioConnection          patchCord173(filter2, 0, filterMixer2, 0);
AudioConnection          patchCord174(filter2, 1, filterMixer2, 1);
AudioConnection          patchCord175(filter2, 2, filterMixer2, 2);
AudioConnection          patchCord176(filter6, 0, filterMixer6, 0);
AudioConnection          patchCord177(filter6, 1, filterMixer6, 1);
AudioConnection          patchCord178(filter6, 2, filterMixer6, 2);
AudioConnection          patchCord179(filter12, 0, filterMixer12, 0);
AudioConnection          patchCord180(filter12, 1, filterMixer12, 1);
AudioConnection          patchCord181(filter12, 2, filterMixer12, 2);
AudioConnection          patchCord182(filter10, 0, filterMixer10, 0);
AudioConnection          patchCord183(filter10, 1, filterMixer10, 1);
AudioConnection          patchCord184(filter10, 2, filterMixer10, 2);
AudioConnection          patchCord185(filter7, 0, filterMixer7, 0);
AudioConnection          patchCord186(filter7, 1, filterMixer7, 1);
AudioConnection          patchCord187(filter7, 2, filterMixer7, 2);
AudioConnection          patchCord188(filter11, 0, filterMixer11, 0);
AudioConnection          patchCord189(filter11, 1, filterMixer11, 1);
AudioConnection          patchCord190(filter11, 2, filterMixer11, 2);
AudioConnection          patchCord191(filter8, 0, filterMixer8, 0);
AudioConnection          patchCord192(filter8, 1, filterMixer8, 1);
AudioConnection          patchCord193(filter8, 2, filterMixer8, 2);
AudioConnection          patchCord194(filter9, 0, filterMixer9, 0);
AudioConnection          patchCord195(filter9, 1, filterMixer9, 1);
AudioConnection          patchCord196(filter9, 2, filterMixer9, 2);
AudioConnection          patchCord197(filter13, 0, filterMixer13, 0);
AudioConnection          patchCord198(filter13, 1, filterMixer13, 1);
AudioConnection          patchCord199(filter13, 2, filterMixer13, 2);
AudioConnection          patchCord200(filter14, 0, filterMixer14, 0);
AudioConnection          patchCord201(filter14, 1, filterMixer14, 1);
AudioConnection          patchCord202(filter14, 2, filterMixer14, 2);
AudioConnection          patchCord203(filter17, 0, filterMixer17, 0);
AudioConnection          patchCord204(filter17, 1, filterMixer17, 1);
AudioConnection          patchCord205(filter17, 2, filterMixer17, 2);
AudioConnection          patchCord206(filter15, 0, filterMixer15, 0);
AudioConnection          patchCord207(filter15, 1, filterMixer15, 1);
AudioConnection          patchCord208(filter15, 2, filterMixer15, 2);
AudioConnection          patchCord209(filter16, 0, filterMixer16, 0);
AudioConnection          patchCord210(filter16, 1, filterMixer16, 1);
AudioConnection          patchCord211(filter16, 2, filterMixer16, 2);
AudioConnection          patchCord212(filter18, 0, filterMixer18, 0);
AudioConnection          patchCord213(filter18, 1, filterMixer18, 1);
AudioConnection          patchCord214(filter18, 2, filterMixer18, 2);
AudioConnection          patchCord215(filter19, 0, filterMixer19, 0);
AudioConnection          patchCord216(filter19, 1, filterMixer19, 1);
AudioConnection          patchCord217(filter19, 2, filterMixer19, 2);
AudioConnection          patchCord218(filter20, 0, filterMixer20, 0);
AudioConnection          patchCord219(filter20, 1, filterMixer20, 1);
AudioConnection          patchCord220(filter20, 2, filterMixer20, 2);
AudioConnection          patchCord221(filterMixer3, 0, mixer1, 2);
AudioConnection          patchCord222(filterMixer4, 0, mixer1, 3);
AudioConnection          patchCord223(filterMixer5, 0, mixer2, 0);
AudioConnection          patchCord224(filterMixer1, 0, mixer1, 0);
AudioConnection          patchCord225(filterMixer2, 0, mixer1, 1);
AudioConnection          patchCord226(filterMixer6, 0, mixer2, 1);
AudioConnection          patchCord227(filterMixer12, 0, mixer3, 3);
AudioConnection          patchCord228(filterMixer10, 0, mixer3, 1);
AudioConnection          patchCord229(filterMixer7, 0, mixer2, 2);
AudioConnection          patchCord230(filterMixer11, 0, mixer3, 2);
AudioConnection          patchCord231(filterMixer8, 0, mixer2, 3);
AudioConnection          patchCord232(filterMixer9, 0, mixer3, 0);
AudioConnection          patchCord233(filterMixer13, 0, mixer4, 0);
AudioConnection          patchCord234(filterMixer14, 0, mixer4, 1);
AudioConnection          patchCord235(filterMixer17, 0, mixer6, 0);
AudioConnection          patchCord236(filterMixer15, 0, mixer4, 2);
AudioConnection          patchCord237(filterMixer16, 0, mixer4, 3);
AudioConnection          patchCord238(filterMixer18, 0, mixer6, 1);
AudioConnection          patchCord239(filterMixer19, 0, mixer6, 2);
AudioConnection          patchCord240(filterMixer20, 0, mixer6, 3);
AudioConnection          patchCord241(mixer1, 0, mixer5, 0);
AudioConnection          patchCord242(mixer2, 0, mixer5, 1);
AudioConnection          patchCord243(mixer3, 0, mixer5, 2);
AudioConnection          patchCord244(mixer6, 0, mixerMaster, 1);
AudioConnection          patchCord245(mixer4, 0, mixer5, 3);
AudioConnection          patchCord246(mixer5, 0, mixerMaster, 0);
AudioConnection          patchCord247(mixerMaster, 0, i2s1, 0);
AudioConnection          patchCord248(mixerMaster, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2166,616
// GUItool: end automatically generated code










//testing stuff
byte waveformCarrier = WAVEFORM_SQUARE;
byte waveformMod = WAVEFORM_SQUARE;
float frequencyMulCarrier = 1;
float frequencyMulMod = 1;
bool changeMod = false;

#define VOICE_COUNT 16
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
  sgtl5000_1.inputSelect(AUDIO_INPUT_MIC);
  sgtl5000_1.micGain(0); //does not affect noise it seems
  sgtl5000_1.inputLevel(0); //does not affect noise it seems
  //sgtl5000_1.enhanceBassEnable(); //Not sure if this does anything. Might only work for input->output routing e.g. mic->headphones

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

/*
  //Filter
  filter1.frequency(220);
  filter1.resonance(5);
  mixer7.gain(0, 0.6);
  mixer7.gain(1, 0.3);
  mixer7.gain(2, 0.1);
  mixer7.gain(3, 0);
  */

  //Setup filter envelope source
  dc1.amplitude(1);

  //Create program bank 1
  for(int i=0; i<PROGRAMS_PER_BANK; ++i){
    programBank1[i] = Program();
  }
  
  //Setup channel programs
  Program *firstProgram = &programBank1[0];
  for(int i=0; i<CHANNEL_COUNT; ++i){
    channelProgram[i] = firstProgram;
  }


  programBank1[0].SetWaveform(0, WAVEFORM_SINE);
  programBank1[0].SetFreqMul(0, 0.5);
  float _volumeDAHDSR0_[6] = {0, 2500, 0, 1, 1, 120};
  programBank1[0].SetVolumeDAHDSR(0, _volumeDAHDSR0_);
  programBank1[0].SetFreqAdd(0, 0);
  programBank1[0].SetOperatorVolume(0,0.1);
  programBank1[0].SetWaveform(1, WAVEFORM_SQUARE);
  programBank1[0].SetFreqMul(1, 1.0);
  float _volumeDAHDSR1_[6] = {0, 10, 0, 50, 1, 120};
  programBank1[0].SetVolumeDAHDSR(1, _volumeDAHDSR1_);
  programBank1[0].SetFreqAdd(1, 0);
  programBank1[0].SetOperatorVolume(1,0.5);

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

  //
  programBank1[18].SetWaveform(0, WAVEFORM_TRIANGLE);
  programBank1[18].SetFreqMul(0, 1.0);
  float _volumeDAHDSR34[6] = {0, 100, 0, 50, 0.3, 70};
  programBank1[18].SetVolumeDAHDSR(0, _volumeDAHDSR34);
  programBank1[18].SetFreqAdd(0, 1);
  programBank1[18].SetOperatorVolume(0,0.1);
  float _waveshape34[17] = {-0.5, -1,-1,-1,-1,-1,-1, -0.5, 0, 0.5,1,1,1,1,1,1, 0.5};// {-1, -1, -1, -1, -1,-0.75, -0.5, -0.25, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  //programBank1[18].SetWaveshape(0, _waveshape34); 
  programBank1[18].SetWaveform(1, WAVEFORM_SINE);
  programBank1[18].SetFreqMul(1, 1.0);
  float _volumeDAHDSR35[6] = {0, 10, 0, 10, 1, 100};
  programBank1[18].SetVolumeDAHDSR(1, _volumeDAHDSR35);
  programBank1[18].SetFreqAdd(1, 0);
  programBank1[18].SetOperatorVolume(1,1);
  float _waveshape35[17] = {-0.5,-1,-1,-1,-1,-1,-0.75,-0.5, 0, 0.5,0.75,1,1,1,1,1,0.5};
  //{-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //pow2
  // {-1, -1, -1, -1, -1, -1,-1, -1, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //guitary
  // {-1, -0.765625, -0.5625, -0.390625, -0.25, -0.140625, -0.0625, -0.015625, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1}; //pow2
  programBank1[18].SetWaveshape(1, _waveshape35); 


  //programBank1[19].SetWaveform(1, WAVEFORM_SAWTOOTH);
  //programBank1[19].SetOperatorVolume(1,1);

  //noisy bass thingy
  programBank1[19].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[19].SetFreqMul(0, 0.5);
  float _volumeDAHDSR36[6] = {0, 100, 0, 100, 0.5, 10};
  programBank1[19].SetVolumeDAHDSR(0, _volumeDAHDSR36);
  programBank1[19].SetFreqAdd(0, 0.1);
  programBank1[19].SetOperatorVolume(0,1);
  programBank1[19].SetWaveform(1, WAVEFORM_SQUARE);
  programBank1[19].SetFreqMul(1, 1);
  float _volumeDAHDSR37[6] = {0, 10, 0, 50, 1, 50};
  programBank1[19].SetVolumeDAHDSR(1, _volumeDAHDSR37);
  programBank1[19].SetFreqAdd(1, 0);
  programBank1[19].SetOperatorVolume(1,1);
  programBank1[19].SetFilterCutoff(120);
  programBank1[19].SetFilterResonance(5);
  programBank1[19].SetFilterOctaveControl(6);
  programBank1[19].SetFilterBandpassVolume(0);
  programBank1[19].SetFilterHighpassVolume(0);
  float _filterDAHDSR36[6] = {50, 1500, 0, 0, 1, 70};
  programBank1[19].SetFilterDAHDSR(_filterDAHDSR36);

  programBank1[20].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[20].SetFreqMul(0, 0.5);
  float _volumeDAHDSR38[6] = {0, 100, 0, 100, 0.5, 10};
  programBank1[20].SetVolumeDAHDSR(0, _volumeDAHDSR38);
  programBank1[20].SetFreqAdd(0, 0.1);
  programBank1[20].SetOperatorVolume(0,1);
  programBank1[20].SetWaveform(1, WAVEFORM_SQUARE);
  programBank1[20].SetFreqMul(1, 1);
  float _volumeDAHDSR39[6] = {0, 10, 0, 50, 1, 50};
  programBank1[20].SetVolumeDAHDSR(1, _volumeDAHDSR39);
  programBank1[20].SetFreqAdd(1, 0);
  programBank1[20].SetOperatorVolume(1,1);
  programBank1[20].SetFilterCutoff(130);
  programBank1[20].SetFilterResonance(1);
  programBank1[20].SetFilterOctaveControl(3);
  programBank1[20].SetFilterBandpassVolume(0.2);
  programBank1[20].SetFilterHighpassVolume(0.1);
  float _filterDAHDSR38[6] = {50, 1500, 0, 0, 1, 70};
  programBank1[20].SetFilterDAHDSR(_filterDAHDSR38);


  programBank1[21].SetWaveform(0, WAVEFORM_SQUARE);
  programBank1[21].SetFreqMul(0, 0.5);
  float _volumeDAHDSR40[6] = {0, 8, 0, 100, 0.3, 70};
  programBank1[21].SetVolumeDAHDSR(0, _volumeDAHDSR40);
  programBank1[21].SetFreqAdd(0, 1);
  programBank1[21].SetOperatorVolume(0,0.25);
  float _waveshape40[17] = {-1, -1, -1, -1, -1, -0.75, -0.5, -0.25, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[21].SetWaveshape(0, _waveshape40); 
  programBank1[21].SetWaveform(1, WAVEFORM_SINE);
  programBank1[21].SetFreqMul(1, 1.0);
  float _volumeDAHDSR41[6] = {0, 30, 0, 100, 1, 100};
  programBank1[21].SetVolumeDAHDSR(1, _volumeDAHDSR41);
  programBank1[21].SetFreqAdd(1, 0);
  programBank1[21].SetOperatorVolume(1,0.9);
  float _waveshape41[17] = {-1, -1, -1, -1, -1, -1,-1, -1, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[21].SetWaveshape(1, _waveshape41);
  programBank1[21].SetFilterCutoff(90);
  programBank1[21].SetFilterResonance(3);
  programBank1[21].SetFilterOctaveControl(3);
  programBank1[21].SetFilterBandpassVolume(0.2);
  programBank1[21].SetFilterHighpassVolume(0.1);
  float _filterDAHDSR40[6] = {0, 0, 150, 2500, 0, 70};
  programBank1[21].SetFilterDAHDSR(_filterDAHDSR40);

  programBank1[22].SetWaveform(0, WAVEFORM_SAWTOOTH_REVERSE);
  programBank1[22].SetFreqMul(0, 0.5);
  float _volumeDAHDSR42[6] = {0, 30, 0, 100, 0.5, 70};
  programBank1[22].SetVolumeDAHDSR(0, _volumeDAHDSR42);
  programBank1[22].SetFreqAdd(0, 0.05);
  programBank1[22].SetOperatorVolume(0,0.3);
  float _waveshape42[17] = {-1, 0, -1, 0, -1, 0,-1, 0, 0, 0.015625, 0.0625, 0.140625, 0.25, 0.390625, 0.5625, 0.765625, 1};
  programBank1[22].SetWaveshape(0, _waveshape42); 
  programBank1[22].SetWaveform(1, WAVEFORM_SINE);
  programBank1[22].SetFreqMul(1, 2.0);
  float _volumeDAHDSR43[6] = {0, 10, 0, 100, 1, 100};
  programBank1[22].SetVolumeDAHDSR(1, _volumeDAHDSR43);
  programBank1[22].SetFreqAdd(1, 0);
  programBank1[22].SetOperatorVolume(1,1);
  programBank1[22].SetFilterCutoff(100);
  programBank1[22].SetFilterResonance(5);
  programBank1[22].SetFilterOctaveControl(1.5);
  programBank1[22].SetFilterBandpassVolume(0.1);
  programBank1[22].SetFilterHighpassVolume(0.0);
  float _filterDAHDSR42[6] = {0, 250, 150, 1000, 0.1, 70};
  programBank1[22].SetFilterDAHDSR(_filterDAHDSR42);
  

  //Setup voices
  voice[0] = Voice(&modulator1, &modulatorWaveshape1, &modulatorEnvelope1, &carrier1, &carrierWaveshape1, &carrierEnvelope1, &filter1, &filterEnvelope1, &filterMixer1, firstProgram);
  voice[1] = Voice(&modulator2, &modulatorWaveshape2, &modulatorEnvelope2, &carrier2, &carrierWaveshape2, &carrierEnvelope2, &filter2, &filterEnvelope2, &filterMixer2, firstProgram);
  voice[2] = Voice(&modulator3, &modulatorWaveshape3, &modulatorEnvelope3, &carrier3, &carrierWaveshape3, &carrierEnvelope3, &filter3, &filterEnvelope3, &filterMixer3, firstProgram);
  voice[3] = Voice(&modulator4, &modulatorWaveshape4, &modulatorEnvelope4, &carrier4, &carrierWaveshape4, &carrierEnvelope4, &filter4, &filterEnvelope4, &filterMixer4, firstProgram);
  voice[4] = Voice(&modulator5, &modulatorWaveshape5, &modulatorEnvelope5, &carrier5, &carrierWaveshape5, &carrierEnvelope5, &filter5, &filterEnvelope5, &filterMixer5, firstProgram);
  voice[5] = Voice(&modulator6, &modulatorWaveshape6, &modulatorEnvelope6, &carrier6, &carrierWaveshape6, &carrierEnvelope6, &filter6, &filterEnvelope6, &filterMixer6, firstProgram);
  voice[6] = Voice(&modulator7, &modulatorWaveshape7, &modulatorEnvelope7, &carrier7, &carrierWaveshape7, &carrierEnvelope7, &filter7, &filterEnvelope7, &filterMixer7, firstProgram);
  voice[7] = Voice(&modulator8, &modulatorWaveshape8, &modulatorEnvelope8, &carrier8, &carrierWaveshape8, &carrierEnvelope8, &filter8, &filterEnvelope8, &filterMixer8, firstProgram);
  voice[8] = Voice(&modulator9, &modulatorWaveshape9, &modulatorEnvelope9, &carrier9, &carrierWaveshape9, &carrierEnvelope9, &filter9, &filterEnvelope9, &filterMixer9, firstProgram);
  voice[9] = Voice(&modulator10, &modulatorWaveshape10, &modulatorEnvelope10, &carrier10, &carrierWaveshape10, &carrierEnvelope10, &filter10, &filterEnvelope10, &filterMixer10, firstProgram);
  voice[10] = Voice(&modulator11, &modulatorWaveshape11, &modulatorEnvelope11, &carrier11, &carrierWaveshape11, &carrierEnvelope11, &filter11, &filterEnvelope11, &filterMixer11, firstProgram);
  voice[11] = Voice(&modulator12, &modulatorWaveshape12, &modulatorEnvelope12, &carrier12, &carrierWaveshape12, &carrierEnvelope12, &filter12, &filterEnvelope12, &filterMixer12, firstProgram);
  voice[12] = Voice(&modulator13, &modulatorWaveshape13, &modulatorEnvelope13, &carrier13, &carrierWaveshape13, &carrierEnvelope13, &filter13, &filterEnvelope13, &filterMixer13, firstProgram);
  voice[13] = Voice(&modulator14, &modulatorWaveshape14, &modulatorEnvelope14, &carrier14, &carrierWaveshape14, &carrierEnvelope14, &filter14, &filterEnvelope14, &filterMixer14, firstProgram);
  voice[14] = Voice(&modulator15, &modulatorWaveshape15, &modulatorEnvelope15, &carrier15, &carrierWaveshape15, &carrierEnvelope15, &filter15, &filterEnvelope15, &filterMixer15, firstProgram);
  voice[15] = Voice(&modulator16, &modulatorWaveshape16, &modulatorEnvelope16, &carrier16, &carrierWaveshape16, &carrierEnvelope16, &filter16, &filterEnvelope16, &filterMixer16, firstProgram);
  //voice[16] = Voice(&modulator17, &modulatorWaveshape17, &modulatorEnvelope17, &carrier17, &carrierWaveshape17, &carrierEnvelope17, &filter17, &filterEnvelope17, &filterMixer17, firstProgram);
  //voice[17] = Voice(&modulator18, &modulatorWaveshape18, &modulatorEnvelope18, &carrier18, &carrierWaveshape18, &carrierEnvelope18, &filter18, &filterEnvelope18, &filterMixer18, firstProgram);
  //voice[18] = Voice(&modulator19, &modulatorWaveshape19, &modulatorEnvelope18, &carrier19, &carrierWaveshape19, &carrierEnvelope19, &filter19, &filterEnvelope19, &filterMixer19, firstProgram);
  //voice[19] = Voice(&modulator20, &modulatorWaveshape20, &modulatorEnvelope20, &carrier20, &carrierWaveshape20, &carrierEnvelope20, &filter20, &filterEnvelope20, &filterMixer20, firstProgram);

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


float filterFreq = 10;
float lastmillis = 0;

void loop() {
  usbMIDI.read();

  //Print cpu and memory useage on request
  if(Serial.available()){
  /*
    //Parse incoming int and set it as filter freq
    float i = Serial.parseFloat();
    filter1.frequency(i);
*/
    
    //Print cpu & memory debug to serial out
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

/*
  filterFreq += 0.1 * (millis()-lastmillis);
  lastmillis = millis();
  if(filterFreq >= 5000){
    filterFreq = 10;
  }
  filter1.frequency(filterFreq);
  */
  
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
    for(int i=0; i<VOICE_COUNT; ++i){
      if(voice[i].IsPlaying() == false){
        voice[i].SetProgram(channelProgram[channel]);
        voice[i].NoteOn(channel, pitch, velocity/127.0);
        return;
      }
    }

    //Otherwise simply use the next voice in stack
    //Note: This results in pops/clicks as the voice might still be in the release phase
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

