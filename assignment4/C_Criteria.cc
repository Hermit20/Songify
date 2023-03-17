#include <iostream>
#include <string>


#include "C_Criteria.h"
using namespace std;

C_Criteria::C_Criteria(string category){
  this->category = category;
}

bool C_Criteria::matches(const Song& s) const{
  if(this->category.compare(s.getCategory()) == 0){
    return true;
  }

  return false;
}

void C_Criteria::print(ostream& os) const{ os<<"Will match if this category and Song::category are the same. Category:"<< this->category<<endl; }
