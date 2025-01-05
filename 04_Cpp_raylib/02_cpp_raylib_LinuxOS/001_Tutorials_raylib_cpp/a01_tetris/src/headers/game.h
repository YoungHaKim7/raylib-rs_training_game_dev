#pragma once

#include "../blocks.cpp"
#include "grid.h"
#include <vector>

class Game {
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    void MoveBlockUp();
    Grid grid;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};
