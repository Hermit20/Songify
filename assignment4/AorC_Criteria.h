#ifndef AorC_CRITERIA_H
#define AorC_CRITERIA_H

#include <iostream>
#include <string>
#include "Song.h"
#include "Criteria.h"
#include "A_Criteria.h"
#include "C_Criteria.h"
using namespace std;

class AorC_Criteria: public C_Criteria, public A_Criteria{

public:
  AorC_Criteria(string artist, string category);
  bool matches(const Song&) const;

  void print(ostream& os) const;

};

#endif
