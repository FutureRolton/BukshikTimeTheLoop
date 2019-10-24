#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
  RenderWindow window(VideoMode(800, 600), "Bucshin Game - start");

  CircleShape MyCircle(100.f);
  MyCircle.setFillColor(Color::Blue);

  while(window.isOpen()) {
    Event event;
    while(window.pollEvent(event)) {
      if(event.type == Event::Closed) {
        window.close();
      }
    }
    window.clear();
    window.draw(MyCircle);
    window.display();
  }
  return 0;
}
