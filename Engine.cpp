#include "Engine.h"

void Engine::Position::setXY(int x, int y) {
    mX = x;
    mY = y;
}

void Engine::GameController::moveCursorToPosition(int col, int row) {
    printf(mFORMAT, mHEX, col, row);
    mCurrentMousePosition.setXY(row, col);
}

void Engine::GameController::clear() {
    system(mCLEAR);
}

void Engine::GameController::loop() {
    while (true) {
        clear();
        moveCursorToPosition(1, 1);
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

void Engine::GameController::setBeginningCursorPosition() {
    moveCursorToPosition(mOuterBoundsOfWorldSpace + 1, 1);
}

void Engine::GameController::mainUserInput() {
    system("stty echo");
    std::cin >> lastEnteredWord;
}

void Engine::GameController::handleLastEnteredWord() {
    if (lastEnteredWord == "move") {
        moveCursorToPosition(1, 1);
        spaceUserInput();
        handleLastEnteredLetter();
    }
}

void Engine::GameController::spaceUserInput() {
    system("stty -echo");
    std::cin >> lastEnteredLetter;
}

void Engine::GameController::handleLastEnteredLetter() {
    int x = mCurrentMousePosition.mX;
    int y = mCurrentMousePosition.mY;

    switch(lastEnteredLetter) {
        case 'q': break;
        case 'w': y = -1 + mCurrentMousePosition.mY; break;
        case 's': y = 1 + mCurrentMousePosition.mY; break;
        case 'a': x = -1 + mCurrentMousePosition.mX; break;
        case 'd': x = 1 + mCurrentMousePosition.mX; break;
        default: break;
    }

    // TODO: Do not update if position has not changed.
    if (y < mOuterBoundsOfWorldSpace + 1 &&
        x < mOuterBoundsOfWorldSpace + 1 &&
        y > 0 &&
        x > 0) {
        moveCursorToPosition(y, x);
    } else {
        moveCursorToPosition(mCurrentMousePosition.mY, mCurrentMousePosition.mX);
    }

    if (lastEnteredLetter != 'q') {
        spaceUserInput();
        handleLastEnteredLetter();
    }
}
