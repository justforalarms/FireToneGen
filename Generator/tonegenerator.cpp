#include <Arduino.h>
#include "waveforms.h"
#include <Wire.h>
// ignore, i like to use these for NCO implementations
typedef uint32_t reg32;
typedef uint16_t reg16;
typedef uint8_t reg8;
volatile bool outputMute = 1;
volatile bool flag = 0;
volatile byte dataIn[4];
volatile char i_x = 0;
volatile bool flag_out = 0;
class ToneGenerator
{
	public:
		volatile reg32 phaseAccumulator;
		volatile reg32 frequencyRegister = 0;
		volatile reg8 waveformSelector;
		volatile reg8 waveformBuffer;
		volatile reg8 outputBuffer;

};
ToneGenerator tonegen;
void resetAll(){
    tonegen.frequencyRegister = 0;
    tonegen.phaseAccumulator = 0;
    outputMute = 1;
}
void setFrequency(uint16_t hz1){
    tonegen.frequencyRegister = pow(2,32)*hz1/16000;
}
void setWaveform(uint8_t waveform){
    tonegen.waveformSelector = waveform;
}
void setMute(){
    outputMute = 1;
}
void setUnMute(){
    outputMute = 0;
}
void receiveEvent(int howMany)
{
    for(byte i = 0; i <= howMany; i++)
    {
        dataIn[i] = Wire.read();

    }
    flag = 1;
    digitalWrite(13, !digitalRead(13));

}




void setup(void){

    Wire.begin(0x02); // start I2C bus with address #2
    Wire.setClock(100000);
    Wire.onReceive(receiveEvent);
    pinMode(13, OUTPUT);
    tonegen.waveformSelector = 1; // 0 - Square, 1 - 25% Pulse, 2 - Triangle, 3 - Sine, 4 - Sawtooth
    pinMode(9, OUTPUT);
	// timer interrupt setup function, configures timer2 for 8KHz interrupts, assuming your ATmega328p is running at 16MHz.
	// includes timer1 config for ~32KHz 8-bit PWM for audio.
	cli();

    TCCR1A = (1 << COM1A1) | (1 << WGM10);
    OCR1A = 0;
    TCCR1B = (1 << CS10) | (1 << WGM12);
	TCCR2A = 0;
	TCCR2B = 0;
	TCNT2 = 0;
	OCR2A = 124;
	TCCR2A |= (1 << WGM21);
	TCCR2B |= (0 << CS22) | (1 << CS21) | (0 << CS20);
	TIMSK2 |= (1 << OCIE2A);

	sei();

}
ISR(TIMER2_COMPA_vect)
{
    sei();
    flag_out = 1;
    tonegen.phaseAccumulator += tonegen.frequencyRegister;
    tonegen.waveformBuffer = (reg8)(tonegen.phaseAccumulator >> 8);
}
void loop(void) {
    if (flag_out){
        switch (tonegen.waveformSelector) {
        case 0:
            tonegen.outputBuffer = wave0_lut[tonegen.waveformBuffer];
            break;
        case 1:
            tonegen.outputBuffer = wave1_lut[tonegen.waveformBuffer];
            break;
        case 2:
            tonegen.outputBuffer = wave2_lut[tonegen.waveformBuffer];
            break;
        case 3:
            tonegen.outputBuffer = wave3_lut[tonegen.waveformBuffer];
            break;
        case 4:
            tonegen.outputBuffer = tonegen.waveformBuffer;
            break;
        default:
            tonegen.outputBuffer = tonegen.waveformBuffer;

    }
    if (!outputMute){

        OCR1A = tonegen.outputBuffer;
    } else {
        OCR1A = tonegen.outputBuffer;
    }
        flag_out = 0;
    }

    //tonegen.frequencyRegister = (800) * (2^32 / 24096);
    //delay(250);
    //tonegen.frequencyRegister = (1000) * (2^32 / 24096);
    //delay(250);
    if(flag){

        switch (dataIn[0]){
        case 28:
            resetAll();
            break;
        case 29:
            setMute();
            break;
        case 30:
            setUnMute();
            break;
        case 31:
            setWaveform(dataIn[1]);
            break;
        case 32:
            setFrequency(((dataIn[2] << 8)| dataIn[1]));
            break;

    }
       //Wire.end();
       flag = 0;
       //Wire.begin(0x02);
    }

}

