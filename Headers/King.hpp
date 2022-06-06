#pragma once
#include<Base_Piece.hpp>
#include<vector>
using namespace std;

template <typename Board>
class King : virtual public BasePiece
{
    public:
        King(char col, const int& x, const int& y) : BasePiece(col, x, y) {}
        vector<vector<int>> ListMoves(Board &board);
};

template <typename Board>
vector<vector<int>> King<Board>::ListMoves(Board &board)
{
    vector<vector<int>> ans;
    for (int i=-1; i<2; i++)
        for (int j=-1; j<2; j++)
            if((i!=0 || j!=0) && Position[0]>=i && Position[0]<=7+i && Position[1]>=j && Position[1]<=7+j && (board.Grid[Position[0]-i][Position[1]-j]=="--" || (board.Grid[Position[0]-i][Position[1]-j][1]=='B' && colour) || (board.Grid[Position[0]-i][Position[1]-j][1]=='W' && !colour)))
            {
                board.MakeMove(Position[0],Position[1],Position[0]-i,Position[1]-j);
                if ((!colour && !board.is_in_Check(false)) || (colour && !board.is_in_Check(true)))
                    ans.push_back({Position[0], Position[1]});
                board.Undo_Latest_Move();
            }
    return ans;
}