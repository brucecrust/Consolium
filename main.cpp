#include "World.h"
#include "GameController.h"

// TODO: Create a GameController class to store goToXY and clear methods
// TODO: Implement methods to move the cursor directly below the map when inputting commands
// TODO: Implement methods to move the cursor to a location.

int main() {
    std::vector<std::vector<char>> space {
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'}
    };

    auto world = World::Space(space);
    auto game = GameController(world);
    game.loop();
    return 0;
}
