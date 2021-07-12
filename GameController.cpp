#include "GameController.h"

void GameController::moveCursorToPosition(int col, int row) {
    printf(mFORMAT, mHEX, col, row);
}

void GameController::clear() {
    system(mCLEAR);
}

void GameController::loop() {
    clear();
    mWorld.print();
    setBeginningCursorPosition();
    while (true) {
        char c;
        std::cin >> c;
        if (c == 'q') {
            clear();
            break;
        }
    }
}

void GameController::setBeginningCursorPosition() {
    moveCursorToPosition(mOuterBoundsOfWorldSpace + 1, 1);
}
