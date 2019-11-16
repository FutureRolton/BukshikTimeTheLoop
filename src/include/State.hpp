#ifndef STATE_H
#define STATE_H

#include "allHeaders.hpp"

using namespace std;
using namespace sf;

class State {
  public:
    class Menu;
    class Game;

    State();
    virtual ~State();

    void setWidth( int width );
    void setHeight( int height );

    static RenderWindow *window;
  protected:
    static int heightWindow;
    static int widthWindow;
    static int widthMenu;
  private:
};

RenderWindow *State::window;
int State::heightWindow;
int State::widthWindow;
int State::widthMenu;

#endif
