#include "WorldSpace.h"

std::vector<std::vector<char>> WorldSpace::space() {
    return mSpace;
}

void WorldSpace::modify(char sprite, std::size_t col, std::size_t row) {
    // Check if [col]/[row] is outside the bounds of the vector.
    if (col > mSpace.size() || row > mSpace[0].size()) {
        throw std::out_of_range("Attempted access of index outside of the vector range.");
    }

    if (mSpace[col][row] == sprite) return;
    mSpace[col][row] = sprite;
}

void WorldSpace::print() {
    for (std::size_t iCol = 0; iCol < mSpace.size(); ++iCol) {
        for (std::size_t iRow = 0; iRow < mSpace[iCol].size(); ++iRow) {
            std::cout << " " << mSpace[iCol][iRow] << " ";
        }
        std::cout << "\n";
    }
}
