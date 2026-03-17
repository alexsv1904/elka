/// @file
/// @brief
/// @example
#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 39
#define DATA_PIN 12
#define CLOCK_PIN 13
CRGB leds[NUM_LEDS];

typedef unsigned long long ull;

void setup() {

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


//functionwithcolor
byte getr(long color) {
  return ((color / 256) / 256);
}

byte getg(long color) {
  return (color / 256) % 256;
}

byte getb(long color) {
  return color % 256;
}

long getcolor(byte r, byte g, byte b) {
  long lo = r * 256;
  return ((lo + g) * 256 + b);
}







bool m = 0;
int p = -1;
void pereliv(ull mil){ while(1){
  byte r, rr, b, bb, g, gg, j = 0;
  long color;
  ull mil2;
  long a[4]{
    a[0] = 0x0000ff,
    a[1] = 0x00ff00,
    a[2] = 0xff0000,
    a[3] = 0x0000ff,
  };
  if (m) {
  } else {
    m = !m;
    mil2 = millis();
  }

  if (millis() - mil2 > mil) {
    m = 0;
    return;
  }


  p++;
  if (p > 2)
    p = 0;

  r = getr(a[p]);
  g = getg(a[p]);
  b = getb(a[p]);

  rr = getr(a[p + 1]);
  gg = getg(a[p + 1]);
  bb = getb(a[p + 1]);
  while (j <= 254) {
    if (r < rr) r++;
    else if (rr < r) r--;

    if (g < gg) g++;
    else if (gg < g) g--;

    if (b < bb) b++;
    else if (bb < b) b--;

    color = getcolor(r, g, b);

    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = color;
    }
    FastLED.show();
    delay(10);
    j++;
  }
  j = 0;
  delay(30);
}}











void black(ull a) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = 0x000000;
  }
  FastLED.show();
  delay(a);
}







 bool mmm = 0;
void rocket(ull mil){while(1) {
  ull mil2;
 
  int del = 100;
  if (mmm) {
  } else {
    mmm = !mmm;
    mil2 = millis();
  }

  if (millis() - mil2 > mil) {
    mmm = 0;
    return;
  }
  long col = (random() * 256 + random()) * 256 + random();
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = col;
    FastLED.show();
    delay(del - map(i, 0, NUM_LEDS, 0, del/2));

    leds[i] = 0x000000;
    FastLED.show();
  }
}}




ull mil2;
bool mm=0;
void starsky(ull mil){
while(1){
if (mm) {
  } else {
    mm = !mm;
    mil2 = millis();
  }

  if (millis() - mil2 > mil) {
    mm = 0;
    return;
  }



byte led1=random();
led1=map(led1, 0, 255, 0, NUM_LEDS);
long led2=getcolor(random(), random(), random());

byte r1 = getr(led2);
  byte g1 = getg(led2);
  byte b1 = getb(led2);

byte rr1=0;
byte gg1=0;
byte bb1=0;

for(int o=0;o<255;o++){

if (rr1 < r1) rr1++;
    if (gg1 < g1) gg1++;
    if (bb1 < b1) bb1++;


    
leds[led1] = getcolor(rr1, gg1, bb1);
leds[led1+1] = getcolor(rr1, gg1, bb1);
leds[led1-1] = getcolor(rr1, gg1, bb1);
FastLED.show();
    delay(10);

}




rr1=0;
gg1=0;
bb1=0;

for(int o=0;o<255;o++){

if (r1 > rr1) r1--;
    if (g1 > gg1) g1--;
    if (b1 > bb1) b1--;


    
leds[led1] = getcolor(r1, g1, b1);
leds[led1+1] = getcolor(r1, g1, b1);
leds[led1-1] = getcolor(r1, g1, b1);
FastLED.show();
    delay(1);

}}
}

void mode(byte num, ull mill){
  if(num==1)
  starsky(mill);

if(num==2)
  rocket(mill);

if(num==3)
  pereliv(mill);

black(1);
}

void loop() {
 mode(random(3),random(10000)+5000);
 //black(1);
}
