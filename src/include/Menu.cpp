#include "allHeaders.hpp"
#include "State.hpp"
#include "Menu.hpp"

using namespace sf;
using namespace std;

State::Menu::Menu() {
  initVarible();
}
State::Menu::~Menu() {
}

void State::Menu::initVarible() {
  font.loadFromFile( "fonts/AmaticSC-Bold.ttf" );

  start.setString( L"Начать" );
  start.setFont( font );
  start.setCharacterSize( SIZE_FONT );
  start.setFillColor( Color::White );

  settings.setString( L"Настройки" );
  settings.setFont( font );
  settings.setCharacterSize( SIZE_FONT );
  settings.setFillColor( Color::White );

  exit.setString( L"Выйти" );
  exit.setFont( font );
  exit.setCharacterSize( SIZE_FONT );
  exit.setFillColor( Color::White );

  bgMenu.setSize( Vector2f( widthMenu, heightWindow ) );
  bgMenu.setFillColor( Color::Red );

  endPositionStart    = -1 * (int)( SIZE_FONT * start.getString().getSize() );
  endPositionSettings = -1 * (int)( SIZE_FONT * settings.getString().getSize() );
  endPositionExit     = -1 * (int)( SIZE_FONT * exit.getString().getSize() );
  endPositionBgMenu   = -1 * (int)( widthMenu );
}

void State::Menu::open() {
  start.setPosition(    endPositionStart,     SIZE_FONT );
  settings.setPosition( endPositionSettings,  SIZE_FONT * 2 + INDENT_TEXT );
  exit.setPosition(     endPositionExit,  heightWindow - SIZE_FONT - INDENT_TEXT );
  bgMenu.setPosition(   endPositionBgMenu,    0 );

  Event event;
  Clock clock;

  while( window->isOpen() ) {
    while( window->pollEvent( event ) ) {
      if( event.type == Event::Closed ) {
        window->close();
      } else if( Mouse::isButtonPressed( Mouse::Left ) ) {
        // Click event
        // Click start
        if(    IntRect( 0, SIZE_FONT             , widthMenu, SIZE_FONT ).contains( Mouse::getPosition( *window ) ) ) {
          //State::Game game;
        } else if( IntRect( 0, SIZE_FONT + INDENT_TEXT       , widthMenu, SIZE_FONT ).contains( Mouse::getPosition( *window ) ) ) {
          // Click Settings
          //State::Settings settings;
        } else if( IntRect( 0, heightWindow - SIZE_FONT - INDENT_TEXT, widthMenu, SIZE_FONT ).contains( Mouse::getPosition( *window ) ) ) {
          // Click exit
          window->close();
        }
      } else {
        // Event hover mouse
        // Hover Start
        if( IntRect( 0, SIZE_FONT   , widthMenu, SIZE_FONT ).contains( Mouse::getPosition( *window ) ) ) {
          start.setFillColor( Color::Blue );
        } else {
          start.setFillColor( Color::White );
        }

        // Hover Settings
        if( IntRect( 0, SIZE_FONT * 2 + INDENT_TEXT, widthMenu, SIZE_FONT ).contains( Mouse::getPosition( *window ) ) ) {
          settings.setFillColor( Color::Blue );
        } else {
          settings.setFillColor( Color::White );
        }

        // Hover exit
        if( IntRect( 0, heightWindow - SIZE_FONT - INDENT_TEXT, widthMenu, SIZE_FONT ).contains( Mouse::getPosition( *window ) ) ) {
          exit.setFillColor( Color::Blue );
        } else {
          exit.setFillColor( Color::White );
        }
      }
    }
    if( clock.getElapsedTime().asSeconds() > 1 ) {
      // Start animation
      if( bgMenu.getPosition().x < 0 ) {
        bgMenu.move( ANIMATION_SPEED * 1.45, 0 );
      }
      if( start.getPosition().x < SIZE_FONT ) {
        start.move( ANIMATION_SPEED * 1.25, 0 );
      }
      if( settings.getPosition().x < SIZE_FONT ) {
        settings.move( ANIMATION_SPEED, 0 );
      }
      if( exit.getPosition().x < SIZE_FONT ) {
        exit.move( ANIMATION_SPEED * 0.85, 0 );
      }
    }
    if( clock.getElapsedTime().asSeconds() > 10 ) {
      break;
    }

    // for perfomance
    // window->clear()

    // z-index 0 background menu
    // Draw background
    window->draw( bgMenu );

    // z-index > 0
    // Draw text
    window->draw( start );
    window->draw( settings );
    window->draw( exit );
    window->display();
  }
}

void State::Menu::close() {
  Event event;
  while( window->isOpen() ) {
    while( window->pollEvent( event ) ) {
      if( event.type == Event::Closed ) {
        window->close();
      }
    }
    if( start.getPosition().x > endPositionStart ) {
      start.move( -1 * ANIMATION_SPEED, 0 );
    }
    if( settings.getPosition().x > endPositionSettings ) {
      settings.move( -1 * ANIMATION_SPEED, 0 );
    }
    if( exit.getPosition().x > endPositionExit ) {
      exit.move( -1 * ANIMATION_SPEED, 0 );
    }
    if( bgMenu.getPosition().x > endPositionBgMenu ) {
      // on 25% up speed
      bgMenu.move( -1 * ANIMATION_SPEED * 1.25, 0 );
    }

    window->clear();

    window->draw( bgMenu );
    window->draw( start );
    window->draw( settings );
    window->draw( exit );
    window->display();
  }
}
