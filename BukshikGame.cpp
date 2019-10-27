#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
  RenderWindow window(VideoMode(800, 600), "BukshikGame");

  int z = 0;
  while(window.isOpen()) {
    Event event;
    CircleShape shape(z);
    shape.setFillColor(Color::Red);
    z++;

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
