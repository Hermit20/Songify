#ifndef SONGIFY_H
#define SONGIFY_H

#include <iostream>
#include <string>

#include "MediaFactory.h"
#include "Array.h"
using namespace std;

class Songify {

	public:
		//constructors
		Songify();

		//destructor
		~Songify();

		//add and remove Songs and Albums
		bool addAlbum(const string& artist, const string& albumTitle);
		bool addSong(const string& Artist, const string& title, const string& albumTitle);
		// bool addSong(const Song& song);
		bool removeSong(const string& artist, const string& songTitle , const string& albumTitle);
		bool removeAlbum(const string& artist, const string& albumTitle);

		bool getAlbum(int index, Album** a);
		const Array<Album*>& getAlbums();
		bool getPlaylist(const string& artist,const string& category, Array<Song*> &playlist);



	private:
		Array<Album*> albums;
		MediaFactory* mf;

};
#endif
