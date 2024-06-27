#include <FireToneGen.h>

void FireToneGen::sendBytes(byte addrreg, uint8_t byte1, uint8_t byte2)
{
    delayMicroseconds(250);
    FireToneGen::outbuf[0] = addrreg;
    FireToneGen::outbuf[1] = byte1;
    FireToneGen::outbuf[2] = byte2;
    FireToneGen::outbuf[3] = 127;
    Wire.beginTransmission(0x02);
    Wire.write(FireToneGen::outbuf, 4);  //data bytes are queued in local buffer
    Wire.endTransmission();    // stop transmitting
}
void FireToneGen::setFrequency(uint16_t hz){
    uint16_t x = hz;
    uint8_t xlow = x & 0xff;
    uint8_t xhigh = (x >> 8);
    FireToneGen::sendBytes(32, xhigh, xlow);

}
void FireToneGen::setMute(bool isMuted){
    if(isMuted){
        FireToneGen::sendBytes(29, 0, 0);

    }else{
        FireToneGen::sendBytes(30, 0, 0);
    }
}


