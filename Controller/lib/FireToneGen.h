#ifndef FIRETONEGEN_H_INCLUDED
#define FIRETONEGEN_H_INCLUDED



#endif // FIRETONEGEN_H_INCLUDED
#include <Arduino.h>
#include <Wire.h>
class FireToneGen
{

private:
    uint8_t outbuf[4];
    uint8_t addrRegister;
    uint8_t dataByte1;
    uint8_t dataByte2;
    void sendBytes(byte addrreg, uint8_t byte1, uint8_t byte2);
public:
    void setFrequency(uint16_t hz);
    void setWaveform(uint8_t waveform);
    void setMute(bool isMuted);

};
