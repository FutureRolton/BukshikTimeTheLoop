#include "allHeaders.hpp"
//#include "Settings.hpp"
#include "State.hpp"
#include "Menu.hpp"

using namespace sf;
using namespace std;
//using nlohmann::json;

int main() {

  // from unix
  setlocale(LC_ALL, "ru-RU");

  // from windows
  setlocale(LC_ALL, "Russian");

  //Settings settings;

  //json params = settings.getJson();
  // Size
  //  0 index is width
  //  1 index is height
  RenderWindow *window = new RenderWindow( VideoMode( 800, 600 ), "BukshikGame", Style::Close );

  //settings.init( params, window );

  State state;
  state.window = window;

  state.setWidth( 800 );
  state.setHeight( 600 );

  State::Menu menu;

  menu.open();

  // sleep in 10 seconds
  // portable windows and posix
  boost::this_thread::sleep( boost::posix_time::seconds(10) );

  menu.close();

  return 0;
}
