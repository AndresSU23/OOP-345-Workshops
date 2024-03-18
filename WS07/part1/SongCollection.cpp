#include "SongCollection.h"

#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>

std::ostream& seneca::operator<<(std::ostream& out, const Song& theSong) {
    out << "| " << std::setw(20) << std::left << theSong.m_title << " | "
        << std::setw(15) << std::left << theSong.m_artist << " | "
        << std::setw(20) << std::left << theSong.m_album << " | "
        << std::setw(6) << std::right << (theSong.m_releaseYear ? std::to_string(theSong.m_releaseYear) : "") << " | "
        << formatLength(theSong.m_length) << " |"
        << std::fixed << std::setprecision(2) << std::setw(5) << std::right << theSong.m_price << " |";
    return out;
}

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
    // Use std::for_each with lambda to read lines and populate songs vector
    std::for_each(std::istreambuf_iterator<char>{file}, std::istreambuf_iterator<char>{}, [&](char ch) {
        if (ch != '\n') {
            line += ch;
        }
        else {
            Song song;
            song.m_title = trim(line.substr(0, 25));
            song.m_artist = trim(line.substr(25, 25));
            song.m_album = trim(line.substr(50, 25));
            std::string tempYear = trim(line.substr(75, 5));
            song.m_releaseYear = (tempYear.empty() ? 0 : std::stoi(tempYear));
            song.m_length = std::stoi(trim(line.substr(80, 5)));
            song.m_price = std::stod(trim(line.substr(85, 5)));
            songs.push_back(song);
            line.clear();
        }
        });

    file.close();

}
void seneca::SongCollection::display(std::ostream& out) const {
    std::for_each(songs.begin(), songs.end(), [&out](const Song& song) {
        out << song << "\n";
        });
}

std::string seneca::trim(std::string str) {
    str.erase(str.begin(), std::find_if_not(str.begin(), str.end(), ::isspace));
    str.erase(std::find_if_not(str.rbegin(), str.rend(), ::isspace).base(), str.end());
    return str;
}



