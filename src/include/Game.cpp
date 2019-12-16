#include "allHeaders.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

RenderWindow *Game::window;
unsigned int Game::WIDTH_WINDOW;
unsigned int Game::HEIGHT_WINDOW;

Game::Game() {
}
Game::~Game() {
  cout << "del Game" << endl;
}

void Game::setWindow( RenderWindow *w ) {
  window = w;
  initSizeWindow();
}
void Game::initSizeWindow() {
  //Vector2u windowSize = window->getSize();
  HEIGHT_WINDOW = 800;
  WIDTH_WINDOW = 600;
}
