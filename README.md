# FireToneGen
A simple monophonic tone generator written for the Arduino framework.

# Disclaimer
### **There are MAJOR bugs for now. I've uploaded it just for the sake of preservation.**
**This is not supposed to be used with existing code. The point of this project is to have a dedicated seperate "processor" for tone generation, as inefficient as that may be.**  
   
You need one ATmega328p (as the tone generator) and another processor (that has **hardware I2C** support, which acts like the controller), to be able to generate tones.

# How it works

The main tone generator is a simple NCO. It's a simple "modulo M" counter (where M is how many counts it does before resetting. Or something like that :) )
The result of the accumulator has the lower 24-bits masked off and the top 8-bits are used for the wavetable output.
