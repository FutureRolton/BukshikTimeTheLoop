#include "allHeaders.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

RenderWindow *Game::window;
int Game::heightWindow;
int Game::widthWindow;
int Game::widthMenu;

Game::Game() {
  // 800px value on default
  heightWindow = 800;
  // 600px value on default
  widthWindow = 600;
  // Width menu
  widthMenu = widthWindow / 2;
}
Game::~Game() {
  cout << "del Game" << endl;
}

void Game::setWidth( int width ) {
  widthWindow = width;
  widthMenu = width / 2;
}
void Game::setHeight( int height ) {
  heightWindow = height;
}
