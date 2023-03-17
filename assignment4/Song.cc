#include <iostream>
#include <string>
#include "Song.h"
using namespace std;


Song::Song(const string& artist, const string&  title, const string& category, const string& content){
  this->title = title;
  this->artist = artist;
  this->content = content;
  this->category = category;

}


const string& Song::getTitle() const { return title;}
const string& Song::getArtist() const { return artist;}
const string& Song::getCategory() const { return category;}

bool Song::matches(const string& artist, const string& title)const{
  if(this->artist.compare(artist) == 0 && this->title.compare(title) == 0){
    return true;
  }

  return false;
}

void Song::print(ostream& os) const {os<<"--Artist: "<< artist << " Song: "<<title <<" Category: "<<category<<endl; }
void Song::play(ostream& os)const {os<< "--Artist: "<< artist << " Song: "<<title <<" Category: "<<category<< " Content: "<< content<<endl; }

ostream& operator<<(ostream& os, const Song& s){
  s.print(os);
  return os;
}
