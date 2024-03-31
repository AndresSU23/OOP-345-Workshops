/***********************************************************************
// Workshop 9 Part 2
// Version 1.0
// Author
// Description
//	Name      : David Andres Sanchez Umbarila
//	Student ID: 140273228
//	Email     : dasanchez-umbarila@myseneca.ca
//
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <functional>
#include "TreasureMap.h"

namespace seneca {

    size_t digForTreasure(const std::string& str, char mark) {
        return std::count(str.begin(), str.end(), mark);
    }

    TreasureMap::TreasureMap(const char* filename) {
        std::ifstream fin(filename);
        if (!fin.is_open()) {
            throw std::string(filename) + " cannot be opened";
        }

        fin >> rows;
        std::string temp;
        std::getline(fin, temp); // Clear newline after reading rows
        map = new std::string[rows];

        for (size_t idx = 0; idx < rows && std::getline(fin, map[idx]); ++idx);

        colSize = map[0].length();
    }

    TreasureMap::~TreasureMap() {
        delete[] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const {
        if (!map) {
            return os << "The map is empty!" << std::endl;
        }

        for (size_t i = 0; i < rows; ++i) {
            os << map[i] << std::endl;
        }
        return os;
    }

    void TreasureMap::enscribe(const char* filename) {
        std::ofstream outFile(filename, std::ios::binary);
        if (!outFile) {
            throw std::string(filename) + " cannot be opened";
        }

        if (!map) {
            throw std::string("Treasure map is empty!");
        }

        outFile.write(reinterpret_cast<const char*>(&rows), sizeof(rows));
        outFile.write(reinterpret_cast<const char*>(&colSize), sizeof(colSize));
        for (size_t i = 0; i < rows; ++i) {
            outFile.write(map[i].c_str(), map[i].length());
        }
    }

    void TreasureMap::recall(const char* filename) {
        clear();
        std::ifstream inFile(filename, std::ios::binary);
        if (!inFile) {
            throw std::string(filename) + " cannot be opened";
        }

        inFile.read(reinterpret_cast<char*>(&rows), sizeof(rows));
        inFile.read(reinterpret_cast<char*>(&colSize), sizeof(colSize));

        delete[] map;
        map = new std::string[rows];
        std::string buffer(colSize, '\0');

        for (size_t i = 0; i < rows; ++i) {
            inFile.read(&buffer[0], colSize);
            map[i].assign(buffer);
        }
    }

    void TreasureMap::clear() {
        delete[] map;
        map = nullptr;
        rows = colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark) {
        const size_t numThreads = std::thread::hardware_concurrency();
        std::vector<std::future<size_t>> futures;
        std::vector<std::thread> threads;

        auto task = [mark](const std::string& segment) -> size_t {
            return digForTreasure(segment, mark);
            };

        size_t partitionSize = rows / numThreads;
        size_t extraRows = rows % numThreads;

        for (size_t i = 0; i < numThreads; ++i) {
            size_t startIdx = i * partitionSize + std::min(i, extraRows);
            size_t endIdx = startIdx + partitionSize + (i < extraRows ? 1 : 0);

            std::string segment;
            for (size_t j = startIdx; j < endIdx; ++j) {
                segment += map[j];
            }

            std::packaged_task<size_t()> packagedTask(std::bind(task, segment));
            futures.push_back(packagedTask.get_future());
            threads.emplace_back(std::move(packagedTask));
        }

        for (auto& t : threads) {
            if (t.joinable()) t.join();
        }

        size_t totalTreasure = 0;
        for (auto& fut : futures) {
            totalTreasure += fut.get();
        }

        return totalTreasure;
    }

}