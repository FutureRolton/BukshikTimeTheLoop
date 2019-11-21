#ifndef MENU_H
#define MENU_H

#include "allHeaders.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

class State::Menu {
  public:
    Menu();
    virtual ~Menu();

    void open();
    void close();
  protected:
  private:
    void initVarible();

    const int SIZE_FONT = 40;
    const int INDENT_TEXT = 15;
    const float ANIMATION_SPEED = 0.4;

    Font font;

    Text start;
    Text settings;
    Text exit;
    RectangleShape bgMenu;

    // Position outside the window
    int endPositionStart;
    int endPositionSettings;
    int endPositionExit;
    int endPositionBgMenu;

};

#endif
