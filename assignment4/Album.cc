#include <iostream>
#include <string>

#include "Album.h"
#include "defs.h"

Album::Album(const string& artist, const string& albumTitle){
  this->artist = artist;
  this->title = albumTitle;
  //this->songs  = new Array<Songs*>[MAX_ARRAY];
}

Album::~Album(){
  for(int i = 0; i < songs.getSize(); i++){
    delete songs[i];
  }
}

bool Album::matches(const string& a, const string& t) const{

  if(this->artist.compare(a) == 0 && this->title.compare(t) == 0){
    return true;
  }

  return false;
}

bool Album::lessThan(const Album& alb) const{

  if(alb.artist.compare(artist) < 0){
    return true;
  }
  else if(alb.artist.compare(artist) == 0){
    if(alb.title.compare(title) < 0){
      return true;
    }
  }

  return false;
}

bool Album::addSong(Song*s){

  //cout<<songs->getSize()<<endl;
  // if(songs->getSize() == MAX_ARRAY){
  //   return false;
  // }
  //cout<<"hello"<<endl;
  songs += s;
  return true;
}

bool Album::getSong(const string& songTitle, Song** s) const{
  for(int i = 0; i < songs.getSize(); i++){
    if(songs[i]->getTitle().compare(songTitle) == 0){
      *s = songs[i];
      return true;
    }
  }

  *s = NULL;
  return false;
}

bool Album::getSong(int index, Song**s) const{
  if(index < 0 || index > songs.getSize()){
    *s = NULL;
    return false;
  }
  *s = songs[index];
  return true;
}
bool Album::removeSong(const string& songTitle, Song** s){
  for(int i = 0; i < songs.getSize(); i++){
    if(songs[i]->getTitle().compare(songTitle) == 0){
      *s = songs[i];
      songs-= songs[i];
      //delete songs[i];
      return true;
    }
  }

  *s = NULL;
  return false;
}

bool Album::removeSong(int index, Song** s){
  if (index < 0 || index >= songs.getSize()) {
    *s = NULL;
    return false;
	}
  *s = songs[index];
  songs-= songs[index];
  //delete songs[index];
  return true;
}

int Album::getSize()const{
  return songs.getSize();
}

Song* Album::operator[](int index) const{
	if (index < 0 || index >= songs.getSize()) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return songs[index];
}

void Album::print(ostream& os) const{
  os<< "Album Artist: "<< artist << " Album Title: "<< title << endl <<" Songs:"<<endl;
  for(int i = 0; i < songs.getSize(); i++){
    os<<*songs[i]<<endl;
  }


}

void Album::printShort(ostream& os) const{
  os<< "Album Artist: "<< artist << " Album Title: "<< title << endl;
}

ostream& operator<<(ostream& out, const Album& a)
{
  a.printShort(out);
  return out;
}
