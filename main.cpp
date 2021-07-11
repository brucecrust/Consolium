#include "WorldSpace.h"

int main() {
    std::vector<std::vector<char>> space {
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'}
    };

    auto world = WorldSpace(space);
    world.modify('p', 2, 2);
    world.print();
    world.modify('e', 10, 10);
    return 0;
}
