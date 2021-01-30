#include "CelestialBody.hpp"
int main(int argc, char* argv[]) {
  double T(stod(argv[1])), ts(stod(argv[2])), simt=0;
  cout<<"Simulation time: "<<T<<"\n";
  cout<<"Time Step: "<<ts<<"\n\n";
  int p;
  double r;
  cin>>p;
  cin>>r;
  cout<<"Num of planets: "<<p<<"\n";
  cout<<"Radius: "<<r<<"\n\n";
  vector<CelestialBody> vec;
  for(int i=0; i<p; i++) {
    CelestialBody* tmp=new CelestialBody();
    cin>>*tmp;
    tmp->radii(r);
    tmp->position();
    vec.push_back(*tmp);
    cout << *tmp;
  }
  RenderWindow window(VideoMode(1000, 1000), "The Solar System");
  window.setFramerateLimit(60);
  Image i;
  i.loadFromFile("starfield.jpg");
  Text t;
  t.setCharacterSize(14);
  Music m;
  m.openFromFile("2001.wav");
  m.play();
  Texture texture;
  texture.loadFromImage(i);
  Sprite s;
  s.setTexture(texture);
  vector<CelestialBody>::iterator it, x, y;
  while(window.isOpen()) {
    Event event;
    while(window.pollEvent(event)) {
      if (event.type==Event::Closed) {window.close();}
    }
    window.clear();
    window.draw(s);
    t.setString("Elapsed time: "+to_string(simt));
    window.draw(t);
    x=vec.begin();
    double fx, fy;
    for(int a=0; a<p; a++) {
      y=vec.begin();
      fx=0;
      fy=0;
      for(int b=0; b<p; b++) {
        if(a != b) {
          fx+=forx(*x, *y);
          fy+=fory(*x, *y);
        }
        y++;
      }
      x->set_forces(fx, fy);
      x++;
    }
    for(it=vec.begin(); it != vec.end(); it++) {
      window.draw(*it);
      cout<<*it<<endl;
      it->step(ts);
      it->position();
    }
    window.display();
    simt+=ts;
    if(simt==T) {break;}
  }
  cout<<"\n\n\n";
  for(it=vec.begin(); it != vec.end(); it++) {cout<<*it<<endl;}
  return 0;
}
