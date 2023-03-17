#ifndef C_CRITERIA_H
#define C_CRITERIA_H

#include <iostream>
#include <string>
#include "Song.h"
#include "Criteria.h"
using namespace std;

class C_Criteria: virtual public Criteria{

public:
  C_Criteria(string category);
  virtual bool matches(const Song&) const;

  virtual void print(ostream& os) const;
private:
  string category;
};

#endif
