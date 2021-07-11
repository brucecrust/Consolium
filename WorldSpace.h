#ifndef CONSOLIUM_WORLDSPACE_H
#define CONSOLIUM_WORLDSPACE_H

#include <vector>
#include <stdexcept>
#include <iostream>

class WorldSpace {
public:
    WorldSpace(std::vector<std::vector<char>> space) { mSpace = space; }

    std::vector<std::vector<char>> space();
    void modify(char sprite, std::size_t col, std::size_t row);
    void print();

private:
    std::vector<std::vector<char>> mSpace;
};

#endif
