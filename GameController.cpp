#include "GameController.h"

void GameController::moveCursorToPosition(int col, int row) {
    printf(mFORMAT, mHEX, col, row);
}

void GameController::clear() {
    system(mCLEAR);
}

void GameController::loop() {
    while (true) {
        clear();
        mWorld.print();
        setBeginningCursorPosition();
        mainUserInput();
        if (lastEnteredWord == "quit") {
            clear();
            break;
        } else {
            handleLastEnteredWord();
        }
    }
}

void GameController::setBeginningCursorPosition() {
    moveCursorToPosition(mOuterBoundsOfWorldSpace + 1, 1);
}

void GameController::mainUserInput() {
    std::cin >> lastEnteredWord;
}

void GameController::handleLastEnteredWord() {
    if (lastEnteredWord == "move") {
        moveCursorToPosition(1, 1);
        spaceUserInput();
        handleLastEnteredLetter();
    }
}

void GameController::spaceUserInput() {
    std::cin >> lastEnteredLetter;
}

void GameController::handleLastEnteredLetter() {
    switch(lastEnteredLetter) {
        case 'q': break;
        case 'w':
            moveCursorToPosition()
    }
}
