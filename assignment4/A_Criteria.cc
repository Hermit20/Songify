#include <iostream>
#include <string>


#include "A_Criteria.h"

using namespace std;

A_Criteria::A_Criteria(string artist){
  this->artist = artist;
}

bool A_Criteria::matches(const Song& s) const{
  if(this->artist.compare(s.getArtist()) == 0){
    return true;
  }

  return false;
}

void A_Criteria::print(ostream& os) const { os<<"Will match if this aritst and Song::artist are the same. Artist:"<< this->artist<<endl; }
