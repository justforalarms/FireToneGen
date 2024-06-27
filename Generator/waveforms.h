const uint8_t wave0_lut[256] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255 };


const uint8_t wave1_lut[256] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255 };

const uint8_t wave2_lut[256] = {
  0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22, 24,
 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50,
 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76,
 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98,100,102,
104,106,108,110,112,114,116,118,120,122,124,126,128,
130,132,134,136,138,140,142,144,146,148,150,152,154,
156,158,160,162,164,166,168,170,172,174,176,178,180,
182,184,186,188,190,192,194,196,198,200,202,204,206,
208,210,212,214,216,218,220,222,224,226,228,230,232,
234,236,238,240,242,244,246,248,250,252,254,254,252,
250,248,246,244,242,240,238,236,234,232,230,228,226,
224,222,220,218,216,214,212,210,208,206,204,202,200,
198,196,194,192,190,188,186,184,182,180,178,176,174,
172,170,168,166,164,162,160,158,156,154,152,150,148,
146,144,142,140,138,136,134,132,130,128,126,124,122,
120,118,116,114,112,110,108,106,104,102,100, 98, 96,
 94, 92, 90, 88, 86, 84, 82, 80, 78, 76, 74, 72, 70,
 68, 66, 64, 62, 60, 58, 56, 54, 52, 50, 48, 46, 44,
 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18,
 16, 14, 12, 10,  8,  6,  4,  2,  0 };


const uint8_t wave3_lut[256] = {
127,130,133,136,139,143,146,149,152,155,158,161,164,
167,170,173,176,178,181,184,187,190,192,195,198,200,
203,205,208,210,212,215,217,219,221,223,225,227,229,
231,233,234,236,238,239,240,242,243,244,245,247,248,
249,249,250,251,252,252,253,253,253,254,254,254,254,
254,254,254,253,253,253,252,252,251,250,249,249,248,
247,245,244,243,242,240,239,238,236,234,233,231,229,
227,225,223,221,219,217,215,212,210,208,205,203,200,
198,195,192,190,187,184,181,178,176,173,170,167,164,
161,158,155,152,149,146,143,139,136,133,130,127,124,
121,118,115,111,108,105,102, 99, 96, 93, 90, 87, 84,
 81, 78, 76, 73, 70, 67, 64, 62, 59, 56, 54, 51, 49,
 46, 44, 42, 39, 37, 35, 33, 31, 29, 27, 25, 23, 21,
 20, 18, 16, 15, 14, 12, 11, 10,  9,  7,  6,  5,  5,
  4,  3,  2,  2,  1,  1,  1,  0,  0,  0,  0,  0,  0,
  0,  1,  1,  1,  2,  2,  3,  4,  5,  5,  6,  7,  9,
 10, 11, 12, 14, 15, 16, 18, 20, 21, 23, 25, 27, 29,
 31, 33, 35, 37, 39, 42, 44, 46, 49, 51, 54, 56, 59,
 62, 64, 67, 70, 73, 76, 78, 81, 84, 87, 90, 93, 96,
 99,102,105,108,111,115,118,121,124 };