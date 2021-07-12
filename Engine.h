#ifndef CONSOLIUM_ENGINE_H
#define CONSOLIUM_ENGINE_H

#include "World.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace Engine {

    class Position {
    public:
        Position(int x, int y) {
           mX = x;
           mY = y;
        }

        void setXY(int x, int y);

        int mX, mY;
    };

    class GameController {
    public:
        GameController(World::Space world) : mWorld(world) {
            mOuterBoundsOfWorldSpace = mWorld.mBoundaries.mCol;
        }

        void moveCursorToPosition(int col, int row);

        void clear();

        void loop();

        void setBeginningCursorPosition();

        void mainUserInput();

        void handleLastEnteredWord();

        void spaceUserInput();

        void handleLastEnteredLetter();

    private:
        const char *mFORMAT = "%c[%d;%df";
        const char *mCLEAR = "clear";
        const int mHEX = 0x1B;

        int mOuterBoundsOfWorldSpace;
        std::string lastEnteredWord;
        char lastEnteredLetter;
        World::Space mWorld;
        Position mCurrentMousePosition = Position(0, 0);
    };
}

#endif
