# FireToneGen
A simple monophonic tone generator written for the Arduino framework.

# Disclaimer
### **There are MAJOR bugs for now. I've uploaded it just for the sake of preservation.**
**This is not supposed to be used with existing code. The point of this project is to have a dedicated seperate "processor" for tone generation, as inefficient as that may be.**  
   
You need one ATmega328p (as the tone generator) and another processor (that has **hardware I2C** support, which acts like the controller), to be able to generate tones.


