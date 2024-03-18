#pragma once
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H

#include <string>
#include <iostream>
#include <vector>
#include <list>

namespace seneca {
	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price{ 0 };
		int m_releaseYear{ 0 };
		int m_length{ 0 };
	};

	std::string formatLength(int seconds);

	std::ostream& operator<<(std::ostream& out, const Song& theSong);

	class SongCollection {
	private:
		std::vector<Song> songs;

	public:
		SongCollection(const std::string& filename);

		friend std::ostream& operator<<(std::ostream& out, const Song& theSong);

		void display(std::ostream& out) const;

		void sort(const std::string& field);

		void cleanAlbum();

		bool inCollection(const std::string& artist) const;

		std::list<Song> getSongsForArtist(const std::string& artist) const;

	};

	std::string trim(const std::string str);
}
#endif // !SENECA_SONGCOLLECTION_H
