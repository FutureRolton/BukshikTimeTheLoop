#ifndef MENU_H
#define MENU_H

#include "allHeaders.hpp"
#include "State.hpp"

using namespace std;
using namespace sf;

class State::Menu {
  public:
    Menu() {
      initVarible();
    }
    virtual ~Menu() {
    }

    void open() {
      start.setPosition(    -1 * (int)( SIZE_FONT * start.getString().getSize()     ), SIZE_FONT );
      settings.setPosition( -1 * (int)( SIZE_FONT * settings.getString().getSize()  ), SIZE_FONT * 2 + INDENT_TEXT );
      exit.setPosition(     -1 * (int)( SIZE_FONT * exit.getString().getSize()      ), heightWindow - SIZE_FONT - INDENT_TEXT );
      bgMenu.setPosition(   -1 * (int)( widthMenu ),     0 );

      Event event;
      Clock clock;

      while( window->isOpen() ) {
        while( window->pollEvent( event ) ) {
          if( event.type == Event::Closed ) {
            window->close();
          } else if( Mouse::isButtonPressed( Mouse::Left ) ) {
            // Click event
            // Click start
            if(        IntRect( 0, SIZE_FONT                            , widthMenu, SIZE_FONT ).contains( Mouse::getPosition( *window ) ) ) {
              //State::Game game;
            } else if( IntRect( 0, SIZE_FONT + INDENT_TEXT              , widthMenu, SIZE_FONT ).contains( Mouse::getPosition( *window ) ) ) {
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
            bgMenu.move( 0.6, 0 );
          }
          if( start.getPosition().x < SIZE_FONT ) {
            start.move( 0.5, 0 );
          }
          if( settings.getPosition().x < SIZE_FONT ) {
            settings.move( 0.4, 0 );
          }
          if( exit.getPosition().x < SIZE_FONT ) {
            exit.move( 0.2, 0 );
          }
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
  protected:
  private:
    void initVarible() {
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
    }

    const int SIZE_FONT = 40;
    const int INDENT_TEXT = 15;
    Font font;

    Text start;
    Text settings;
    Text exit;
    RectangleShape bgMenu;
};
#endif
