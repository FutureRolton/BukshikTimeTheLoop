#include <string>
#include <nlohmann/json.hpp>

using namespace std;
class Player {
  public:
    bool setName(string inp) {
      name = inp;
    }
    bool setSkin(string path) {
    }
    bool setSpeed(int speed) {
    }

  protected:
    string name;
    unsigned int id;
    int item[4] = { 0 };
  private:
}
