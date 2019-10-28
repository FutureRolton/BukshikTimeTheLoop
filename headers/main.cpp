#include <limits.h>
#include <unistd.h>
#include <boost/algorithm/string.hpp>
#include "params.hpp"

using namespace std;

char getCurretDir() {
  char cwd[PATH_MAX];
  char *path = getcwd(cwd, sizeof(cwd));
  char pathArr[PATH_MAX];

  boost::split(pathArr, path, boost::is_any_of("/"));

  int size = pathArr.size();

  bool check = false;

  string out[PATH_MAX];

  for(int i = 0; i < size; i++) {
    if(pathArr[i] == "BukshikGame") {
      break;
    } else {
      out = "/" + pathArr[i];
    }
  }

  return out;
}
