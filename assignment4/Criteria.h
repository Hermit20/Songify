#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include "Song.h"
using namespace std;

class Criteria{

public:
  virtual bool matches(const Song&) const = 0;
  virtual void print(ostream& os) const = 0;

  friend ostream& operator<<(ostream& os , const Criteria& c);
};

#endif
