#include <iomanip>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;
using nlohmann::json;

class Settings {
  public:
    json getJsonSettings(bool force = false) {
      if(force || CURRET_SETTINGS.is_null()) {
        ifstream file( FILE_SETTINGS );
        if(file.is_open()) {
          if(file.peek() == ifstream::traits_type::eof()) {
            // empty file
            // write empty file
            ofstream emptyFile( FILE_SETTINGS );
            emptyFile << setw(2) << DEFAULT_SETTINGS << endl;
            CURRET_SETTINGS = DEFAULT_SETTINGS;
            return DEFAULT_SETTINGS;
          } else {
            json jn;
            // read a JSON file
            file >> jn;
            file.close();
            CURRET_SETTINGS = jn;
            return jn;
          }
        } else {
          file.close();
          // create file
          ofstream file { FILE_SETTINGS };
          file << setw(2) << DEFAULT_SETTINGS << endl;
          CURRET_SETTINGS = DEFAULT_SETTINGS;
          return DEFAULT_SETTINGS;
        }
      } else {
        return CURRET_SETTINGS;
      }
    }
    bool setJsonSettings(json jn, bool force = false) {
      if(force || CURRET_SETTINGS.is_null()) {
        // write prettified JSON to another file
        ofstream file( FILE_SETTINGS );
        if(file.is_open()) {
          file << setw(2) << jn << endl;
          file.close();
          return true;
        } else {
          file.close();
          return false;
        }
      } else {
        return CURRET_SETTINGS;
      }
    }
    json reloadCurretSettings() {
      ifstream file( FILE_SETTINGS );
      json jn;
      if(file.is_open()) {
        file >> jn;
        file.close();
        CURRET_SETTINGS = jn;
        return jn;
      } else {
        return CURRET_SETTINGS;
      }
    }
  protected:
    const string FILE_SETTINGS = "settings.json";

    // default value json
    // array size
    //    0 index is x
    //    1 index is y
    const json DEFAULT_SETTINGS = R"(
      {
        "size": [800, 600],
        "volume": 60
      }
    )"_json;
    json CURRET_SETTINGS;
  private:
};
