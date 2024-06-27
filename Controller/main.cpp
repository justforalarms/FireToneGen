#include <Arduino.h>
#include <Wire.h>
#include <FireToneGen.h>
FireToneGen osc_x;


void setup(void){

    Wire.begin();
    Wire.setClock(20000);
    delay(10);
    osc_x.setMute(0);
}
uint32_t Exponent(uint32_t num, uint32_t maxval){
  //int output = log(num+1)/log(300000)*Bval;
  //float R = (1000 * log10(2))/(log10(255));
  uint32_t output = pow(2, (num / (((1000) * log10(2))/(log10(255)))));
  return output;
}
void loop(void){

    osc_x.setFrequency(800);
    delay(250);
    osc_x.setFrequency(1000);
    delay(250);


}




