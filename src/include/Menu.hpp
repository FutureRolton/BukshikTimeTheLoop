#ifndef MENU_H
#define MENU_H

#include "allHeaders.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

class Game::Menu {
  public:
    Menu();
    virtual ~Menu();

    void animationOpen();
    void open();
    void animationClose();

    void setTopButton    ( const vector<string> arr );
    void setBottomButton ( const vector<string> arr );

  protected:
  private:
    void initVarible();

    const int SIZE_FONT         = 40;
    const int INDENT_TEXT       = 15;
    const float ANIMATION_SPEED = 0.4;

    vector<string> textTopButton    = { "S" };
    vector<string> textBottomButton = { "E" };

    unsigned int countButton       = textTopButton.size() + textBottomButton.size();
    unsigned int countTopButton    = textTopButton.size();
    unsigned int countBottomButton = textBottomButton.size();

    std::vector<sf::Text> text;
    RectangleShape bgMenu;
};

#endif
