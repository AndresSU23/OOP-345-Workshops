#include "SongCollection.h"
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <list>
#include <numeric>

std::string seneca::formatLength(int seconds) {
    int minutes = seconds / 60;
    seconds %= 60;
    return std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
}

seneca::SongCollection::SongCollection(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        Song song;
        song.m_title = trim(line.substr(0, 25));
        song.m_artist = trim(line.substr(25, 25));
        song.m_album = trim(line.substr(50, 25));
        std::string tempYear = trim(line.substr(75, 5));
        song.m_releaseYear = (tempYear.empty() ? 0 : std::stoi(tempYear));
        song.m_length = std::stoi(trim(line.substr(80, 5)));
        song.m_price = std::stod(trim(line.substr(85, 5)));
        songs.push_back(song);
    }

    file.close();
}
std::string formatTotalLength(int seconds) {
    int hours = seconds / 3600;
    seconds %= 3600;
    int minutes = seconds / 60;
    seconds %= 60;
    return std::to_string(hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
}
void seneca::SongCollection::display(std::ostream& out) const {
    int totalPlaytime = 0;
    for (const auto& song : songs) {
        out << song << "\n";
        totalPlaytime += song.m_length;
    }
    out << "----------------------------------------------------------------------------------------\n";
    out << "| " << std::setw(77) << std::right << "Total Listening Time: " << formatTotalLength(totalPlaytime) << " |\n";
}

void seneca::SongCollection::sort(const std::string& field) {
    if (field == "title") {
        std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            return a.m_title < b.m_title;
            });
    }
    else if (field == "album") {
        std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            return a.m_album < b.m_album;
            });
    }
    else if (field == "length") {
        std::sort(songs.begin(), songs.end(), [](const seneca::Song& a, const seneca::Song& b) {
            return a.m_length < b.m_length;
            });
    }
}

void seneca::SongCollection::cleanAlbum() {
    songs.erase(std::remove_if(songs.begin(), songs.end(), [](const seneca::Song& song) {
        return song.m_album == "[None]";
        }), songs.end());
}

bool seneca::SongCollection::inCollection(const std::string& artist) const {
    return std::any_of(songs.begin(), songs.end(), [&artist](const Song& song) {
        return song.m_artist == artist;
        });
}

std::list<seneca::Song> seneca::SongCollection::getSongsForArtist(const std::string& artist) const {
    std::list<seneca::Song> artistSongs;
    std::copy_if(songs.begin(), songs.end(), std::back_inserter(artistSongs), [&artist](const Song& song) {
        return song.m_artist == artist;
        });
    return artistSongs;
}

std::string seneca::trim(std::string str) {
    str.erase(str.begin(), std::find_if_not(str.begin(), str.end(), ::isspace));
    str.erase(std::find_if_not(str.rbegin(), str.rend(), ::isspace).base(), str.end());
    return str;
}

std::ostream& seneca::operator<<(std::ostream& out, const Song& theSong) {
    out << "| " << std::setw(20) << std::left << theSong.m_title << " | "
        << std::setw(15) << std::left << theSong.m_artist << " | "
        << std::setw(20) << std::left << theSong.m_album << " | "
        << std::setw(6) << std::right << (theSong.m_releaseYear ? std::to_string(theSong.m_releaseYear) : "") << " | "
        << formatLength(theSong.m_length) << " |"
        << std::fixed << std::setprecision(2) << std::setw(5) << std::right << theSong.m_price << " |";
    return out;
}
