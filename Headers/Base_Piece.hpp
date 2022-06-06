#pragma once

class BasePiece
{
public:
    int Position[2];
    bool colour;
    BasePiece(char col, const int& x, const int& y) : Position{x,y}
    {
        if (col == 'B')
            colour = false;
        else colour = true;
    }
};