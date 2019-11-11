#ifndef STATE_SETTINGS_H
#define STATE_SETTINGS_H

#include "allHeaders.hpp"
#include "State.hpp"

class State::Settings {
  public:
    Settings {
      initVarible();
    }
    ~Settings {

    }
    void start() {
      Event event;
      while( window->isOpen() ) {
        while( window->pollEvent( event ) ) {
          if( event.type == Event::Closed ) {
            window->close();
          } else if( Mose::isButtonPressed( Mouse::Left ) ) {
            // click

          } else {
            // hover
          }
        }
      }
    }
  protected:
  private:
    void initVarible() {
      font.loadFromFile( "fonts/AmaticSC-Bold.ttf" );

      for( int i = 0; i < lenGroup; i++ ) {
        group[i].setFont( font );
        group[i].setCharacterSize( SIZE_FONT );
        group[i].setFillColor( Color::White );
        group[i].setSize( textGroup[i] );
      }
    }
    Font font;
    const string textGroup[] = [ L"Экран", L"Звук" ];
    const int lenGroup = group.size();
    const Text group[lenGroup];
    const int SIZE_FONT = 35;
}
