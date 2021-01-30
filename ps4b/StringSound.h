#ifndef STRINGSOUND_H
#define STRINGSOUND_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <math.h>
#include "RingBuffer.hpp"

const int SAMPLING_RATE = 44100;
const double ENERGY_DECAY_FACTOR = 0.996;
class StringSound {
 public:
  explicit StringSound(double frequency);
  explicit StringSound(std::vector<sf::Int16> init);
  ~StringSound();
  void pluck();
  void tic();
  sf::Int16 sample();
  int time();
 private:
  RingBuffer* buffer;
  int size, Time=0;
};
#endif
