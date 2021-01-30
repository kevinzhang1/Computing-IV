#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;
const double g=6.67e-11;
class CelestialBody: public Drawable {
public:
  CelestialBody();
  CelestialBody(double px, double py, double vx, double vy, double m, double r, string image);
  void radii(float r);
  void position();
  friend double forx(CelestialBody &b1, CelestialBody &b2);
  friend double fory(CelestialBody &b1, CelestialBody &b2);
  void set_forces(double x, double y);
  void step(double t);
  friend istream& operator>>(istream &i, CelestialBody &b);
  friend ostream& operator<<(ostream &o, CelestialBody &b);
private:
  void virtual draw(RenderTarget& target, RenderStates states) const;
  double ax, ay, fx, fy, px, py, vx, vy, m, r;
  string filename;
  Image image;
  Sprite sprite;
  Texture texture;
};
