#include <SFML/Graphics.hpp>
#include <filesystem>
#include <nlohmann/json.hpp>
#include "settings.hpp"

using namespace sf;
using nlohmann::json;

int main() {
  Settings settings;
  json params = settings.getJsonSettings();
  RenderWindow window(VideoMode(params["size"][0], params["size"][1]), "BukshikGame");
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
