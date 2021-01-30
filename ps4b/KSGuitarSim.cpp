#include "RingBuffer.hpp"
#include "StringSound.h"
using namespace std;
using namespace sf;
#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100
vector<Int16> makeSamplesFromString(StringSound gs) {
  vector<Int16> samples;
  gs.pluck();
  int duration=8;
  int i;
  for (i= 0; i<SAMPLES_PER_SEC*duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }
  return samples;
}
int main() {
  RenderWindow window(VideoMode(900, 900), "Guitar");
  Event event;
  double freq;
  string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  vector<vector<Int16>> samples(37);
  vector<SoundBuffer> buff(37);
  vector<Sound> sound(37);
  for (int i=0; i<37; i++) {
    freq=CONCERT_A*pow(2, ((i-24)/12.0));
    samples[i]=makeSamplesFromString(StringSound(freq));
    buff[i].loadFromSamples(&samples[i][0], SAMPLES_PER_SEC*8, 2, SAMPLES_PER_SEC);
    sound[i].setBuffer(buff[i]);
  }
  while(window.isOpen()) {
    while (window.pollEvent(event)) {
      if(event.type==Event::Closed) {
	window.close();
      }
        if(event.type==Event::TextEntered) {
	  char note=(char)event.text.unicode;
            for (int i=0; i<37; i++) {
              if (keys[i]==note) {
                sound[i].play();
              }
            }
        }
      }
    window.clear();
    window.display();
  }
  return 0;
}
