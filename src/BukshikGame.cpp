#include <SFML/Graphics.hpp>
#include <filesystem>

using namespace sf;

int main() {
  RenderWindow window(VideoMode(800, 600), "BukshikGame");
  Image heroimage;
  heroimage.loadFromFile("sprites/object/user1.png");

  Texture herotexture;
  herotexture.loadFromImage(heroimage);

  Sprite herosprite;
  herosprite.setTexture(herotexture);
  herosprite.setPosition(10, 15);

  while(window.isOpen()) {
    Event event;

    while(window.pollEvent(event)) {
      if(event.type == Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(herosprite);
    window.display();
  }
  return 0;
}
