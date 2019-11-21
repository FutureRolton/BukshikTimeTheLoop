#ifndef GAME_H
#define GAME_H

#include "allHeaders.hpp"

using namespace std;
using namespace sf;

class Game {
  public:
    class Menu;
    class Game;

    Game();
    virtual ~Game();

    void setWidth( int width );
    void setHeight( int height );

    static RenderWindow *window;
  protected:
    static int heightWindow;
    static int widthWindow;
    static int widthMenu;
  private:
};

#endif // GAME_H
