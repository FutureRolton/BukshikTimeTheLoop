#include "allHeaders.hpp"
#include "Settings.hpp"
#include "State.hpp"
#include "Menu.hpp"

using namespace sf;
using nlohmann::json;

int main() {

  // from unix
  setlocale(LC_ALL, "ru-RU");

  // from windows
  setlocale(LC_ALL, "Russian");

  Settings settings;

  json params = settings.getJson();
  // Size
  //  0 index is width
  //  1 index is height
  RenderWindow *window = new RenderWindow( VideoMode( params["size"][0], params["size"][1] ), "BukshikGame", Style::Close );

  //settings.init( params, window );

  State state;
  state.window = window;

  state.setWidth( params["size"][0] );
  state.setHeight( params["size"][1] );

  State::Menu menu;

  menu.open();

  return 0;
}
