#include "World.h"
#include "Engine.h"

int main() {
    std::vector<std::vector<char>> space {
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'}
    };

    auto world = World::Space(space);
    auto game = Engine::GameController(world);
    game.loop();
    return 0;
}
