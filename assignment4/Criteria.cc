#include <iostream>
#include <string>
#include "Song.h"
#include "Criteria.h"
using namespace std;


ostream& operator<<(ostream& os, const Criteria& c){
  c.print(os);
  return os;
}
