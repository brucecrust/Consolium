#ifndef CONSOLIUM_GAMECONTROLLER_H
#define CONSOLIUM_GAMECONTROLLER_H

#include "World.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

class GameController {
public:
    GameController(World::Space mWorld) : mWorld(mWorld) {
        mOuterBoundsOfWorldSpace = mWorld.mBoundaries.mCol;
    }

    void moveCursorToPosition(int col, int row);
    void clear();
    void loop();
    void setBeginningCursorPosition();
    void userInput();

private:
    const char* mFORMAT     = "%c[%d;%df";
    const char* mCLEAR      = "clear";
    const int mHEX          = 0x1B;

    int mOuterBoundsOfWorldSpace;

    World::Space mWorld;
};

#endif
