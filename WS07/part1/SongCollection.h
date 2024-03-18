#pragma once
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H

#include <string>
#include <iostream>
#include <vector>

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
        std::vector<Song> songs;

    public:
		SongCollection(const std::string& filename);
		void display(std::ostream& out) const;
    };

	std::string trim(std::string str);
}
#endif // !SENECA_SONGCOLLECTION_H
