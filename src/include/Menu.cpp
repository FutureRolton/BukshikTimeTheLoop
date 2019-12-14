#include "allHeaders.hpp"
#include "Menu.hpp"

using namespace std;
using namespace sf;

Game::Menu::Menu() {
  initVarible();
}
Game::Menu::~Menu() {
}

void Game::Menu::setTopButton( const vector<string> arr ) {
  topButton.clear();
  topButton = arr;
  countTopButton = arr.size();
  countButton = arr.size() + bottomButton.size();
}
void Game::Menu::setBottomButton( const vector<string> arr ) {
  bottomButton.clear();
  bottomButton = arr;
  countBottomButton = arr.size();
  countButton = arr.size() + topButton.size();
}
void Game::Menu::initVarible() {
  bgMenu.setPosition( 0, 0 );
  bgMenu.setFillColor( Color::Red );
  bgMenu.setSize( Vector2f( heightWindow, heightWindow/2 ) );
  text.clear();
  for(int i = 0; i < countButton; i++) {
    text[i].setFont( font );
    text[i].setCharacterSize( SIZE_FONT );
    text[i].setPosition( 0, 0 );
    text[i].setFillColor( Color::White );
    if( i > countTopButton ) {
      text[i].setString( topButton[i] );
    } else {
      text[i].setString( bottomButton[i] );
    }
  }
}
void Game::Menu::animationOpen() {
  for(int i = 0; i < countButton; i++) {
    text[i].setPosition( countButton * SIZE_FONT + INDENT_TEXT, -400 );
    while( text[i].getPosition().x <= SIZE_FONT && window->isOpen() ) {
      text[i].move( 0, ANIMATION_SPEED );
      window->draw( text[i] );
    }
  }
}
void Game::Menu::animationClose() {
  for(int i = 0; i < countButton; i++) {
    while( text[i].getPosition().x >= SIZE_FONT ) {
      text[i].move( 0, ANIMATION_SPEED );
      window->draw( text[i] );
    }
  }
}
