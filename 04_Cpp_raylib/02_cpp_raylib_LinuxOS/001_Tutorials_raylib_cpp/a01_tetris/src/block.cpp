#include <raylib.h>
#include <vector>

#include "headers/block.h"
#include "headers/color.h"
#include "headers/position.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
}

void Block::Draw()
{
    std::vector<Position> tiles = cells[rotationState];
    for (Position item : tiles) {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize - 1,
            cellSize - 1, cellSize - 1, colors[id]);
    }
}
