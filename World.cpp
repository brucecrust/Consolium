#include "World.h"

std::vector<std::vector<char>> World::Space::Space::space() {
    return mSpace;
}

void World::Space::Space::modify(char sprite, std::size_t col, std::size_t row) {
    // Check if [col]/[row] is outside the bounds of the vector.
    if (col > mSpace.size() || row > mSpace[0].size()) {
        throw std::out_of_range("Attempted access of index outside of the vector range.");
    }

    if (mSpace[col][row] == sprite) return;
    mSpace[col][row] = sprite;
}

void World::Space::Space::print() {
    for (std::size_t iCol = 0; iCol < mBoundaries.mCol; ++iCol) {
        for (std::size_t iRow = 0; iRow < mBoundaries.mRow; ++iRow) {
            std::cout << mSpace[iCol][iRow];
        }
        std::cout << "\n";
    }
}
