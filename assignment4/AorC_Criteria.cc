#include <iostream>
#include <string>

#include "AorC_Criteria.h"

using namespace std;

AorC_Criteria::AorC_Criteria(string artist, string category): A_Criteria(artist),C_Criteria(category){

}

bool AorC_Criteria::matches(const Song& s) const{
  if(C_Criteria::matches(s) || A_Criteria::matches(s)){
    return true;
  }

  return false;
}

void AorC_Criteria::print(ostream& os) const { C_Criteria::print(os); A_Criteria::print(os); }
