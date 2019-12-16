#include "allHeaders.hpp"
#include "Menu.hpp"

using namespace std;
using namespace sf;

Game::Menu::Menu() {
  initVarible();
}
Game::Menu::~Menu() {
}

void Game::Menu::setTopButton( vector<string> arr ) {
  textTopButton.clear();
  textTopButton  = arr;
  countTopButton = arr.size();
  countButton    = arr.size() + textBottomButton.size();
}
void Game::Menu::setBottomButton( vector<string> arr ) {
  textBottomButton.clear();
  textBottomButton  = arr;
  countBottomButton = arr.size();
  countButton       = arr.size() + textTopButton.size();
}
void Game::Menu::initVarible() {

  text.clear();

  bgMenu.setPosition  ( 0, 0 );
  bgMenu.setFillColor ( Color::Red );
  bgMenu.setSize      ( Vector2f      ( HEIGHT_WINDOW, WIDTH_WINDOW / 2 ) );

  Font font;
  font.loadFromFile( "fonts/AmaticSC-Regular.ttf" );

  /*
  for(int i = 0; i < countButton; i++) {
    text[i].setFont( font );
    text[i].setCharacterSize( SIZE_FONT );
    text[i].setPosition( 0, 0 );
    text[i].setFillColor( Color::White );
    if( i > countTopButton ) {
      text[i].setString( textTopButton[i] );
    } else {
      text[i].setString( textBottomButton[i] );
    }
  }
  */

  Text t;
  t.setFont          ( font );
  t.setCharacterSize ( SIZE_FONT );
  t.setFillColor     ( Color::White );

  text.resize( countButton, t );

  for(int i = 0; i < countTopButton; i++) {
    text[i].setString( textTopButton[i] );
  }
}
void Game::Menu::animationOpen() {
  // Test not work
  // FIXME
  while( window->isOpen() ) {
    window->clear( Color::Black );
    window->draw( text[0] );
    window->display();
  }
  for(int i = 0; i < countTopButton; i++) {
    text[i].setPosition( -1 * (int)HEIGHT_WINDOW / 2, i * SIZE_FONT + INDENT_TEXT );
    while(
      window->isOpen() &&
      text[i].getPosition().x <= SIZE_FONT
    ) {
      text[i].move( ANIMATION_SPEED, 0 );
      window->draw( text[i] );
      window->display();
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
