#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include "settings.hpp"
#include "game.hpp"

using namespace sf;
using nlohmann::json;

int main() {
  setlocale(LC_ALL, "ru-RU");
  Settings settings;
  Game game;
  json params = settings.getJson();
  RenderWindow window(VideoMode(params["size"][0], params["size"][1]), "BukshikGame", Style::Close);

  //settings.init( params, window );

  game.startMenu( window, params["size"][1]);

  /*while(window.isOpen()) {
    Event event;

    while(window.pollEvent(event)) {
      if(event.type == Event::Closed) {
        window.close();
      }
    }

    window.clear();
    //window.draw();
    window.display();
  }*/
  return 0;
}
