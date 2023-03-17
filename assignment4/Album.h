#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Song.h"
using namespace std;

class Album {


	public:
		//constructors
		Album(const string& artist, const string& albumTitle);
		//Album(const Album&);

		//destructor
		~Album();

		//getters
		const string& getTitle(){return title;}
		const string& getArtist(){return artist;}

		//comparison
		bool matches(const string& artist, const string& albumTitle) const;
		bool lessThan(const Album&) const;

		//add and remove
		bool addSong(Song*);
		//bool addSong(int, Song*);
		bool getSong(const string& songTitle, Song**) const;
		bool getSong(int, Song**) const;
		bool removeSong(const string& songTitle, Song**);
		bool removeSong(int, Song**);

		void printShort(ostream& os) const;
		void print(ostream& os) const;

		int getSize() const;

		friend ostream& operator<<(ostream&, const Album&);
		//overload
		Song* operator[](int index) const;

	private:
		string title;
		string artist;
		Array<Song*> songs;

};
#endif
