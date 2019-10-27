#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
  RenderWindow window(VideoMode(800, 600), "BukshikGame");

  CircleShape shape(200.f);
  shape.setFillColor(Color::Red);

  while(window.isOpen()) {
    Event event;
    while(window.pollEvent(event)) {
      if(event.type == Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
