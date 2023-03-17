#ifndef A_CRITERIA_H
#define A_CRITERIA_H

#include <iostream>
#include <string>
#include "Song.h"
#include "Criteria.h"
using namespace std;

class A_Criteria: virtual public Criteria{

public:
  A_Criteria(string artist);
  virtual bool matches(const Song& s) const;

  virtual void print(ostream& os) const;
private:
  string artist;
};

#endif
