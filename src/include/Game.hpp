#ifndef GAME_H
#define GAME_H

#include "allHeaders.hpp"

using namespace std;
using namespace sf;

class Game {
  public:
    class Menu;
    class Block;

    Game();
    virtual ~Game();

    void setWindow( RenderWindow *w );

  protected:
    static unsigned int WIDTH_WINDOW;
    static unsigned int HEIGHT_WINDOW;
    static RenderWindow *window;
  private:
    void initSizeWindow();
};

#endif // GAME_H
