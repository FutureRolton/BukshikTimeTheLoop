#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Game {
  public:
    void menu(RenderWindow &window, int heightMenu, string backgroundPath = "empty") {
      Font font;
      font.loadFromFile( "fonts/AmaticSC-Regular.ttf" );
      Text text("", font, SIZE_FONT);

      text.setFillColor(Color::White);
      text.setStyle(Text::Bold);

      Text start = text,
        settings = text,
        exit = text;

      RectangleShape backgroundMenu(Vector2f( WIDTH_BACKGROUND_MENU, heightMenu ));
      backgroundMenu.setFillColor( Color::Red );
      backgroundMenu.setPosition( -1 * WIDTH_BACKGROUND_MENU, 0 );
      start.setString( L"Начать" );
      start.setPosition( -1 * WIDTH_BACKGROUND_MENU, 15 );

      settings.setString( L"Настройки" );
      settings.setPosition( -1 * WIDTH_BACKGROUND_MENU, SIZE_FONT + 15 );

      exit.setString( L"Выйти" );
      exit.setPosition( -1 * WIDTH_BACKGROUND_MENU, heightMenu - SIZE_FONT - 15);

      Clock clock;
      while(window.isOpen()) {
        if(clock.getElapsedTime().asSeconds() > 1) {
          if(backgroundMenu.getPosition().x <= 0) {
            backgroundMenu.move( 0.3, 0 );
          }
          if(start.getPosition().x <= 10) {
            start.move( 0.3, 0 );
            settings.move( 0.3, 0 );
            exit.move( 0.3, 0 );
          }
        }
        Event event;
        while(window.pollEvent(event)) {
          if(event.type == Event::Closed) {
            window.close();
          }
          if(IntRect( 0, 15, WIDTH_BACKGROUND_MENU, SIZE_FONT ).contains(Mouse::getPosition(window))) {
            start.setFillColor(Color::Blue);
          } else {
            start.setFillColor(Color::White);
          }
          if(IntRect( 0, SIZE_FONT + 15, WIDTH_BACKGROUND_MENU, SIZE_FONT ).contains(Mouse::getPosition(window))) {
            settings.setFillColor(Color::Blue);
          } else {
            settings.setFillColor(Color::White);
          }
          // Exit
          if(IntRect( 0, heightMenu - SIZE_FONT - 15, WIDTH_BACKGROUND_MENU, SIZE_FONT ).contains(Mouse::getPosition(window))) {
            exit.setFillColor(Color::Blue);
          } else {
            exit.setFillColor(Color::White);
          }
          if(event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == Mouse::Left) {
              // exit button
              if(IntRect( 0, heightMenu - SIZE_FONT - 15, WIDTH_BACKGROUND_MENU, SIZE_FONT ).contains(Mouse::getPosition(window))) {
                window.close();
              // settings button
              } else if(IntRect( 0, SIZE_FONT + 15, WIDTH_BACKGROUND_MENU, SIZE_FONT ).contains(Mouse::getPosition(window))) {
                //this.settings();
              // start button
              } else if(IntRect( 0, 15, WIDTH_BACKGROUND_MENU, SIZE_FONT ).contains(Mouse::getPosition(window))) {
                //this.start();
              }
            }
          }
        }
        window.draw( backgroundMenu );
        window.draw( start );
        window.draw( settings );
        window.draw( exit );
        window.display();
      }
    }

    // Draw window in window settings game
    void settings() {
    }
    // start actually game
    void start(int level) {

    }
  protected:
  private:
    const int WIDTH_BACKGROUND_MENU = 200;
    const int SIZE_FONT = 45;
};
