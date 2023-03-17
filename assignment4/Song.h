#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

class Song {

	public:
		//constructors
		Song(const string& artist, const string&  title, const string& category, const string& content);

		//getters
		const string& getTitle() const;
		const string& getArtist() const;
		const string& getCategory() const;
		bool matches(const string& artist, const string& title) const;

		virtual void print(ostream& os) const;
		virtual void play(ostream& os) const;

		friend ostream& operator<<(ostream& os , const Song& s);
	private:
		string title;
		string artist;
		string content;
		string category;


};
#endif
