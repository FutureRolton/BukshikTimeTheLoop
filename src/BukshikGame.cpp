#include "allHeaders.hpp"
#include "Game.hpp"
#include "Menu.hpp"

using namespace sf;
using namespace std;
//using nlohmann::json;

int main() {

  // from unix
  setlocale(LC_ALL, "ru-RU");

  //Settings settings;

  //json params = settings.getJson();
  // Size
  //  0 index is width
  //  1 index is height
  RenderWindow *window = new RenderWindow( VideoMode( 800, 600 ), "BukshikGame", Style::Close );

  //settings.init( params, window );

  Game game;
  game.setWindow( window );

  Game::Menu menu;

  menu.animationOpen();

  // sleep in 10 seconds
  // portable windows and posix
  boost::this_thread::sleep( boost::posix_time::seconds(10) );

  menu.animationClose();

  return 0;
}
