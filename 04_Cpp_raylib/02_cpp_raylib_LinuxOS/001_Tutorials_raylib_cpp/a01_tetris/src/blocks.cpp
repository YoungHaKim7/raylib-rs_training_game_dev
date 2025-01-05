#include "headers/block.h"
#include "headers/position.h"

class LBlock : public Block {
public:
    // clang-format off
    LBlock() {
        id = 1;
        cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
        cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
        Move(0,3);
    }
    // clang-format on
};

class JBlock : public Block {
public:
    // clang-format off
    JBlock() {
        id = 2;
        cells[0] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};
        cells[3] = {Position(0,1), Position(1,1), Position(2,0), Position(2,1)};
        Move(0,3);
    }
    // clang-format on
};

class IBlock : public Block {
public:
    // clang-format off
    IBlock() {
        id = 3;
        cells[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
        cells[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
        cells[2] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
        cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
        Move(0,3);
    }
    // clang-format on
};

class OBlock : public Block {
public:
    // clang-format off
    OBlock() {
        id = 4;
        cells[0] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        cells[1] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        cells[2] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        cells[3] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        Move(0,3);
    }
    // clang-format on
};

class SBlock : public Block {
public:
    // clang-format off
    SBlock() {
        id = 5;
        cells[0] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
        cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
        cells[2] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
        cells[3] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
        Move(0,3);
    }
// clang-format on
};


class TBlock : public Block
{
public:
    // clang-format off
    TBlock()
    {
        id = 6;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0,3);
    }
// clang-format on
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        Move(0,3);
    }
};
