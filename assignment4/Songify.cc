// #include "Song.h"
#include "defs.h"
// #include "SongArray.h"
#include "Album.h"
// #include "AlbumArray.h"
#include "Songify.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Songify::Songify(){

  //albums = new Array<Album*>[MAX_ARRAY];
  mf = new MediaFactory();

}

Songify::~Songify(){
  for(int i = 0; i < albums.getSize(); i++){
    delete albums[i];
  }
  delete mf;
}


bool Songify::addAlbum(const string& artist, const string& albumTitle){
  Album* alb;
  if(mf->createAlbum(albumTitle,artist,&alb)){
    albums += alb;
    return true;
  }
  //delete alb;
  alb = NULL;
  return false;
}


bool Songify::removeAlbum(const string& artist, const string& albumTitle){
  Album* alb;
  if(mf->createAlbum(albumTitle,artist,&alb)){
    albums -= alb;
    delete alb;
    return true;
  }
  return false;
}

bool Songify::addSong(const string& Artist, const string& title, const string& albumTitle){


  for(int i = 0; i < albums.getSize(); i++){
    if(albums[i]->matches(Artist,albumTitle)){
      Song* s1;
      if(mf->createSong(Artist,title,&s1)){
        albums[i]->addSong(s1);
        return true;
      }
    }
  }



  //s1 = NULL;
  cout<<"Error Could not add song"<<endl;
  return false;
}

bool Songify::removeSong(const string& artist, const string& songTitle , const string& albumTitle){

    for(int i = 0; i < albums.getSize(); i++){
      if(albums[i]->getTitle().compare(albumTitle) == 0 && albums[i]->getArtist().compare(artist)){
        Song* s;
        albums[i]->removeSong(songTitle,&s);
        delete s;
        return true;
      }
    }


    cout<<"Error Counld not remove song"<<endl;
    return false;
}

bool Songify::getAlbum(int index, Album** a){
  if (index < 0 || index >= albums.getSize()) {
    *a = NULL;
    return false;
	}
  *a = albums[index];
  return true;
}

const Array<Album*>& Songify::getAlbums(){
  return albums;
}

bool Songify::getPlaylist(const string& artist,const string& category, Array<Song*> &playlist){
  Criteria* c;
  if(mf->createCriteria(artist,category,&c)){
  for(int i = 0; i < albums.getSize(); i++){
    //cout<<"Artist: "<<albums[i]->getArtist()<<endl;
    for(int j = 0; j < albums[i]->getSize(); j++){
      //cout<<((*albums[i])[j])->getTitle()<<" "<<((*albums[i])[j])->getCategory()<<endl;
      if(c->matches(*((*albums[i])[j]))){
        Song* s;
        albums[i]->getSong(j,&s);
        playlist += s;
      }

    }
    cout<<endl;

  }
  delete c;
  return true;
}

// *playlist = NULL;
return false;
}
