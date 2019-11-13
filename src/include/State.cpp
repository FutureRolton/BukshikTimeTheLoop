#include "allHeaders.hpp"
#include "State.hpp"

using namespace std;
using namespace sf;

State::State() {
  // 800px value on default
  heightWindow = 800;
  // 600px value on default
  widthWindow = 600;
  // Width menu
  widthMenu = widthWindow / 2;
}
State::~State() {
  cout << "del State" << endl;
}

void State::setWidth( int width ) {
  widthWindow = width;
  widthMenu = width / 2;
}
void State::setHeight( int height ) {
  heightWindow = height;
}
