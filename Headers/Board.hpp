#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<Cell.hpp>
#include<Pawn.hpp>
#include<King.hpp>
#include<Queen.hpp>
#include<Knight.hpp>
#include<Rook.hpp>
#include<Bishop.hpp>
using namespace std;
using namespace sf;

class Board
{
public:
    Text Coordinates[16];
    RenderWindow *Window;
    Font font;
    Text text, ResetWord;
    RectangleShape ResetAll;
    vector<Sprite> MoveChoices;
    struct Pieces
    {
        vector<King<Board>> Kings;
        vector<Queen<Board>> Queens;
        vector<Knight<Board>> Knights;
        vector<Rook<Board>> Rooks;
        vector<Bishop<Board>> Bishops;
        vector<Pawn<Board>> Pawns;
    } White_Pieces, Black_Pieces;
    Cell GraphicsGrid[8][8];
    vector<string> Moves;
    string Grid[8][8];
    bool Turn = true;
    Board();
    void SetupBoard();
    bool is_in_Check(bool);
    void MakeMove(int, int, int, int);
    void Undo_Latest_Move(bool);
    bool is_Checkmate(bool);
    void Print()
    {
        for (int i=0; i<8; i++)
        {
            for (int j=0; j<8; j++)
                cout << Grid[i][j][0] << Grid[i][j][1] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    bool Predict(bool, bool, bool, const int&);
    string ConvertMove(string &move);
    void PlayChess();
    void drawboard();
    void RunGraphics();
    void MouseClick(const Vector2i&);
};