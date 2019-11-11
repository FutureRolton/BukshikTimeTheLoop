#ifndef SETTINGS_H
#define SETTINGS_H

#include "allHeaders.hpp"

using namespace std;
using namespace sf;
using nlohmann::json;

class Settings {
  public:
    Settings() {
    }
    ~Settings() {
    }
    void initWindow( json params, RenderWindow &window ) {
      if( !params.is_null() ) {
        window.setFramerateLimit( params["fps"] );
        window.setVerticalSyncEnabled( params["sync"] );
        window.setPosition( Vector2i( 0, 0 ) );
        window.setSize( Vector2u( params["size"][0], params["size"][1] ) );
      }
    }
    json getJson(bool force = false) {
      if(force || currentSettings.is_null()) {
        ifstream file( FILE_SETTINGS );
        if(file.is_open()) {
          if(file.peek() == ifstream::traits_type::eof()) {
            // empty file
            // write empty file
            ofstream emptyFile( FILE_SETTINGS );
            emptyFile << setw(2) << DEFAULT_SETTINGS << endl;
            currentSettings = DEFAULT_SETTINGS;
            return DEFAULT_SETTINGS;
          } else {
            json jn;
            // read a JSON file
            file >> jn;
            file.close();
            currentSettings = jn;
            return jn;
          }
        } else {
          file.close();
          // create file
          ofstream file { FILE_SETTINGS };
          file << setw(2) << DEFAULT_SETTINGS << endl;
          currentSettings = DEFAULT_SETTINGS;
          return DEFAULT_SETTINGS;
        }
      } else {
        return currentSettings;
      }
    }
    bool setJson(json jn, bool force = false) {
      if(force || currentSettings.is_null()) {
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
        return currentSettings;
      }
    }
    json reloadCurret() {
      ifstream file( FILE_SETTINGS );
      json jn;
      if(file.is_open()) {
        file >> jn;
        file.close();
        currentSettings = jn;
        return jn;
      } else {
        return currentSettings;
      }
    }
    void writeSettings() {
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
        "volume": 60,
        "fps": 120,
        "sync": true
      }
    )"_json;
    json currentSettings;
  private:
};

#endif
