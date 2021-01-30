#include "CelestialBody.hpp"
CelestialBody::CelestialBody() {return;}
CelestialBody::CelestialBody(double px, double py, double vx, double vy, double m, double r, string image) {
  this->px=px;
  this->py=py;
  this->vx=vx;
  this->vy=vy;
  this->m=m;
  filename=image;
  (this->image).loadFromFile(image);
  texture.loadFromImage(this->image);
  sprite.setTexture(texture);
  sprite.setPosition(Vector2f(this->px, this->py));
}
void CelestialBody::radii(float r) {
  this->r=r;
}
void CelestialBody::set_forces(double x, double y) {
  fx=x;
  fy=y;
}
double forx(CelestialBody &b1, CelestialBody &b2) {
  double R2=pow(b2.px-b1.px, 2)+pow(b2.py-b1.py, 2);
  double force=(g*b1.m*b2.m)/R2;
  return force*(b2.px-b1.px)/sqrt(R2);
}
double fory(CelestialBody &b1, CelestialBody &b2) {
  double R2=pow(b2.px-b1.px, 2)+pow(b2.py-b1.py, 2);
  double force=(g*b1.m*b2.m)/R2;
  return force*(b2.py-b1.py)/sqrt(R2);
}
void CelestialBody::step(double t) {
  ax=fx/m;
  ay=fy/m;
  vx=vx+(ax*t);
  vy=vy+(ay*t);
  px=px+(vx*t);
  py=py+(vy*t);
}
void CelestialBody::position() {
  sprite.setPosition(Vector2f(((py/r)*(1000/2))+(1000/2), ((px/r)*(1000/2))+(1000/2)));
}
void CelestialBody::draw(RenderTarget& target, RenderStates states) const {
  target.draw(sprite);
}
istream& operator>>(istream &i, CelestialBody &b) {
  i>>b.px>>b.py;
  i>>b.vx>>b.vy;
  i>>b.m>>b.filename;
  b.image.loadFromFile(b.filename);
  b.texture.loadFromImage(b.image);
  b.sprite.setTexture(b.texture);
  b.sprite.setPosition(Vector2f(b.px, b.py));
  b.fx=0;
  b.fy=0;
  b.ax=0;
  b.ay=0;
  return i;
}
ostream& operator<<(ostream &o, CelestialBody &b) {
  o<<"Filename: "<<b.filename<<endl;
  o<<"Acceleration (x): "<<b.ax<<endl;
  o<<"Acceleration (y): "<<b.ay<<endl;
  o<<"Force (x): "<<b.fx<<endl;
  o<<"Force (y): "<<b.fy<<endl;
  o<<"Pos (x): "<<b.px<<endl;
  o<<"Pos (y): "<<b.py<<endl;
  o<<"Vel (x): "<<b.vx<<endl;
  o<<"Vel (y): "<<b.vy<<endl;
  o<<"Mass: "<<b.m<<endl;
  o<<"Radius: "<<b.r<<"\n\n";
  return o;
}
