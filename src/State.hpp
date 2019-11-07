#ifndef STATE_H
#define STATE_H

#include "allHeaders.hpp"

using namespace std;
using namespace sf;

class State {
  public:
    class Menu;
    class Game;

    State() {
      // 800px value on default
      heightWindow = 800;
      // 600px value on default
      widthWindow = 600;
      // Width menu
      widthMenu = widthWindow / 2;
    }
    virtual ~State() {
    }

    void setWidth( int width ) {
      widthWindow = width;
      widthMenu = width / 2;
    }

    void setHeight( int height ) {
      heightWindow = height;
    }

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
