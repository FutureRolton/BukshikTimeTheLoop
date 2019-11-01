#include <string>
#include <nlohmann/json.hpp>

using namespace std;
class Player {
  public:
    void setName(string inpName) {
      name = inpName;
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
