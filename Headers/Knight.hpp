#pragma once
#include<Base_Piece.hpp>
#include<vector>
using namespace std;

template <typename Board>
class Knight : virtual public BasePiece
{
    public:
        Knight(char col, const int& x, const int& y) : BasePiece(col, x, y)
        {
            string temp = "N";
            if(col=='W') temp += "W";
            else temp += "B";
            sprite.setTexture(Piece_Textures[temp]);
            sprite.setPosition(Position[1]*100+28,3+Position[0]*100);
        }
        vector<vector<int>> ListMoves(Board &board);
        vector<vector<int>> ListMateMoves(Board &board);
        vector<vector<int>> ListDefenceMoves(Board &board);
};

template <typename Board>
vector<vector<int>> Knight<Board>::ListMoves(Board &board)
{
    vector<vector<int>> ans;
    if (Position[0]==-1)
        return ans;
    int i = Position[0], j = Position[1], list[8][2] = {{i+2, j+1}, {i+2, j-1}, {i+1, j+2}, {i+1, j-2}, {i-1, j+2}, {i-1, j-2}, {i-2, j+1}, {i-2, j-1}};
    for (int k=0; k<8; k++)
        if(list[k][0]>=0 && list[k][0]<8 && list[k][1]>=0 && list[k][1]<8)
            if ((board.Grid[list[k][0]][list[k][1]]=="--") || (board.Grid[list[k][0]][list[k][1]][1]=='B' && colour) || (board.Grid[list[k][0]][list[k][1]][1]=='W' && !colour))
            {
                board.MakeMove(Position[0],Position[1],list[k][0],list[k][1]);
                if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                    ans.push_back({list[k][0], list[k][1]});
                board.Undo_Latest_Move();
            }
    return ans;
}
template <typename Board>
vector<vector<int>> Knight<Board>::ListMateMoves(Board &board)
{
    vector<vector<int>> temp = ListMoves(board);
    vector<vector<int>> ans;
    for (int i=0; i<temp.size(); i++)
    {
        board.MakeMove(Position[0], Position[1], temp[i][0], temp[i][1]);
        if(board.Predict(colour, true, !colour, 1))
            ans.push_back({temp[i][0], temp[i][1]});
        board.Undo_Latest_Move();
    }
    return ans;
}
template <typename Board>
vector<vector<int>> Knight<Board>::ListDefenceMoves(Board &board)
{
    vector<vector<int>> temp = ListMoves(board);
    vector<vector<int>> ans;
    for (int i=0; i<temp.size(); i++)
    {
        board.MakeMove(Position[0], Position[1], temp[i][0], temp[i][1]);
        if(board.Predict(colour, false, !colour, 1))
            ans.push_back({temp[i][0], temp[i][1]});
        board.Undo_Latest_Move();
    }
    return ans;
}