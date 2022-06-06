#pragma once
#include<Base_Piece.hpp>
#include<vector>
using namespace std;

template <typename Board>
class Pawn : virtual public BasePiece
{
    public:
        Pawn(char col, const int& x, const int& y) : BasePiece(col, x, y) {}
        vector<vector<int>> ListMoves(Board &board);
};

template <typename Board>
vector<vector<int>> Pawn<Board>::ListMoves(Board &board)
{
    vector<vector<int>> ans;
    if (Position[0]==-1)
        return ans;
    if (colour)
    {
        if ((Position[0]>=1) && (Position[1]>=1) && (board.Grid[Position[0]-1][Position[1]-1][1]=='B'))
        {
            board.MakeMove(Position[0],Position[1],Position[0]-1,Position[1]-1);
            if(!board.is_in_Check(true))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
        }
        if ((Position[0]>=1) && (board.Grid[Position[0]-1][Position[1]]=="--"))
        {
            board.MakeMove(Position[0],Position[1],Position[0]-1,Position[1]);
            if(!board.is_in_Check(true))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
            if (Position[0]==6 && board.Grid[Position[0]-2][Position[1]]=="--")
            {
                board.MakeMove(Position[0],Position[1],Position[0]-2,Position[1]);
                if(!board.is_in_Check(true))
                    ans.push_back({Position[0], Position[1]});
                board.Undo_Latest_Move();
            }
        }
        if ((Position[0]>=1) && (Position[1]<=6) && (board.Grid[Position[0]-1][Position[1]+1][1]=='B'))
        {
            board.MakeMove(Position[0],Position[1],Position[0]-1,Position[1]+1);
            if(!board.is_in_Check(true))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
        }
    }
    else
    {
        if (Position[0]<=6 && Position[1]>=1 && board.Grid[Position[0]+1][Position[1]-1][1]=='W')
        {
            board.MakeMove(Position[0],Position[1],Position[0]+1,Position[1]-1);
            if(!board.is_in_Check(false))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
        }
        if (Position[0]<=6 && board.Grid[Position[0]+1][Position[1]]=="--")
        {
            board.MakeMove(Position[0],Position[1],Position[0]+1,Position[1]);
            if(!board.is_in_Check(false))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
            if (Position[0]==1 && board.Grid[Position[0]+2][Position[1]]=="--")
            {
                board.MakeMove(Position[0],Position[1],Position[0]+2,Position[1]);
                if(!board.is_in_Check(false))
                    ans.push_back({Position[0], Position[1]});
                board.Undo_Latest_Move();
            }
        }
        if (Position[0]<=6 && Position[1]<=6 && board.Grid[Position[0]+1][Position[1]+1][1]=='W')
        {
            board.MakeMove(Position[0],Position[1],Position[0]+1,Position[1]+1);
            if(!board.is_in_Check(false))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
        }
    }
    return ans;
}