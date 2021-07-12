#ifndef CONSOLIUM_WORLD_H
#define CONSOLIUM_WORLD_H

#include <vector>
#include <stdexcept>
#include <iostream>

namespace World {

    class Boundaries {
    public:
        Boundaries(std::size_t col, std::size_t row) {
            mCol = col;
            mRow = row;
        }

        std::size_t mCol;
        std::size_t mRow;
    };

    class Space {
    public:
        // Methods:
        Space(std::vector<std::vector<char>> space) {
            mSpace = space;
            mBoundaries = Boundaries(mSpace.size(), mSpace[0].size());
        }

        std::vector<std::vector<char>> space();

        void modify(char sprite, std::size_t col, std::size_t row);

        void print();

        // Members:
        Boundaries mBoundaries = Boundaries(0, 0);

    private:
        std::vector<std::vector<char>> mSpace;
    };
}

#endif
