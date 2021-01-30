#include "StringSound.h"
StringSound::StringSound(double frequency) {
  if(frequency<=0)
    throw std::invalid_argument("Sound frequency has to be greater than zero.");
  buffer=new RingBuffer(ceil(SAMPLING_RATE/frequency));
  size=ceil(SAMPLING_RATE/frequency);
  for (int i=0; i<size; i++) {
    buffer->enqueue((int16_t)0);
  }
}
StringSound::StringSound(std::vector<sf::Int16> init) {
  buffer=new RingBuffer(init.size());
  size=init.size();
  for (int i=0; i<size; i++) {buffer->enqueue((int16_t)init[i]);}
}
StringSound::~StringSound() {
  delete buffer;
}
void StringSound::pluck() {
  for(int i=0; i<size; i++) {buffer->dequeue();}
  for(int i=0; i<size; i++) {
    buffer->enqueue((sf::Int16)(rand()&0xffff));
  }
}
void StringSound::tic() {
  if(size<=1)
    throw std::runtime_error("Size is too small to advance simulation.");
  int16_t variable=buffer->dequeue();
  buffer->enqueue((sf::Int16)((variable+buffer->peek())/2)*ENERGY_DECAY_FACTOR);
  Time++;
}
sf::Int16 StringSound::sample() {return (sf::Int16)buffer->peek();}
int StringSound::time() {return Time;}
