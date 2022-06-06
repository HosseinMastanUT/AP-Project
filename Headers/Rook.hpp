#pragma once
#include<Base_Piece.hpp>
#include<vector>
using namespace std;

template <typename Board>
class Rook : virtual public BasePiece
{
    public:
        Rook(char col, const int& x, const int& y) : BasePiece(col, x, y) {}
        vector<vector<int>> ListMoves(Board &board);
        vector<string> ListMateMoves(Board &board);
        vector<string> ListDefenceMoves(Board &board);
};

template <typename Board>
vector<vector<int>> Rook<Board>::ListMoves(Board &board)
{
    vector<vector<int>> ans;
    if (Position[0]==-1)
        return ans;
    for (int i=1; i<=Position[1]; i++)
    {
        if (i==1 && ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false))))
        {
            board.MakeMove(Position[0],Position[1],Position[0],Position[1]-i);
            if ((colour && board.is_in_Check(true)) || (!colour && board.is_in_Check(false)))
            {
                board.Undo_Latest_Move();
                break;
            }
            else
                board.Undo_Latest_Move();
        }
        if (board.Grid[Position[0]][Position[1]-i]!="--")
        {
            if ((board.Grid[Position[0]][Position[1]-i][1]=='B' && colour) || (board.Grid[Position[0]][Position[1]-i][1]=='W' && !colour))
            {
                board.MakeMove(Position[0],Position[1],Position[0],Position[1]-i);
                if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                    ans.push_back({Position[0], Position[1]});
                board.Undo_Latest_Move();
            }
            break;
        }
        else
        {
            board.MakeMove(Position[0],Position[1],Position[0],Position[1]-i);
            if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
        }
    }
    for (int i=1; i<=7-Position[0]; i++)
    {
        if (i==1 && ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false))))
        {
            board.MakeMove(Position[0],Position[1],Position[0]+i,Position[1]);
            if ((colour && board.is_in_Check(true)) || (!colour && board.is_in_Check(false)))
            {
                board.Undo_Latest_Move();
                break;
            }
            else
                board.Undo_Latest_Move();
        }
        if (board.Grid[Position[0]+i][Position[1]]!="--")
        {
            if ((board.Grid[Position[0]+i][Position[1]][1]=='B' && colour) || (board.Grid[Position[0]+i][Position[1]][1]=='W' && !colour))
            {
                board.MakeMove(Position[0],Position[1],Position[0]+i,Position[1]);
                if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                    ans.push_back({Position[0], Position[1]});
                board.Undo_Latest_Move();
            }
            break;
        }
        else
        {
            board.MakeMove(Position[0],Position[1],Position[0]+i,Position[1]);
            if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
        }
    }
    for (int i=1; i<=Position[0]; i++)
    {
        if (i==1 && ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false))))
        {
            board.MakeMove(Position[0],Position[1],Position[0]-i,Position[1]);
            if ((colour && board.is_in_Check(true)) || (!colour && board.is_in_Check(false)))
            {
                board.Undo_Latest_Move();
                break;
            }
            else
                board.Undo_Latest_Move();
        }
        if (board.Grid[Position[0]-i][Position[1]]!="--")
        {
            if ((board.Grid[Position[0]-i][Position[1]][1]=='B' && colour) || (board.Grid[Position[0]-i][Position[1]][1]=='W' && !colour))
            {
                board.MakeMove(Position[0],Position[1],Position[0]-i,Position[1]);
                if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                    ans.push_back({Position[0], Position[1]});
                board.Undo_Latest_Move();
            }
            break;
        }
        else
        {
            board.MakeMove(Position[0],Position[1],Position[0]-i,Position[1]);
            if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
        }
    }
    for (int i=1; i<=7-Position[1]; i++)
    {
        if (i==1 && ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false))))
        {
            board.MakeMove(Position[0],Position[1],Position[0],Position[1]+i);
            if ((colour && board.is_in_Check(true)) || (!colour && board.is_in_Check(false)))
            {
                board.Undo_Latest_Move();
                break;
            }
            else
                board.Undo_Latest_Move();
        }
        if (board.Grid[Position[0]][Position[1]+i]!="--")
        {
            if ((board.Grid[Position[0]][Position[1]+i][1]=='B' && colour) || (board.Grid[Position[0]][Position[1]+i][1]=='W' && !colour))
            {
                board.MakeMove(Position[0],Position[1],Position[0],Position[1]+i);
                if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                    ans.push_back({Position[0], Position[1]});
                board.Undo_Latest_Move();
            }
            break;
        }
        else
        {
            board.MakeMove(Position[0],Position[1],Position[0],Position[1]+i);
            if ((colour && !board.is_in_Check(true)) || (!colour && !board.is_in_Check(false)))
                ans.push_back({Position[0], Position[1]});
            board.Undo_Latest_Move();
        }
    }
    return ans;
}
template <typename Board>
vector<string> Rook<Board>::ListMateMoves(Board &board)
{
    vector<vector<int>> temp = ListMoves(board);
    vector<string> ans;
    for (int i=0; i<temp.size(); i++)
    {
        board.MakeMove(Position[0], Position[1], temp[i][0], temp[i][1]);
        if(board.Predict(colour, true, !colour, 1))
            ans.push_back(board.ConvertMove(board.Moves.front()));
        board.Undo_Latest_Move();
    }
    return ans;
}
template <typename Board>
vector<string> Rook<Board>::ListDefenceMoves(Board &board)
{
    vector<vector<int>> temp = ListMoves(board);
    vector<string> ans;
    for (int i=0; i<temp.size(); i++)
    {
        board.MakeMove(Position[0], Position[1], temp[i][0], temp[i][1]);
        if(board.Predict(colour, false, !colour, 1))
            ans.push_back(board.ConvertMove(board.Moves.front()));
        board.Undo_Latest_Move();
    }
    return ans;
}