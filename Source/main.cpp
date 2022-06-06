#include<iostream>
#include<Board.hpp>
using namespace std;

void sort(vector<string> &vec)
{
    for (int i=1; i<vec.size(); i++)
    {
        string temp = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > temp)
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = temp;
    }
}

int main()
{
    char turn, mode;
    cin >> turn >> mode;
    Board board;
    vector<string> Emergency_Moves;
    if (turn == 'W')
    {
        for (int i=0; i<board.White_Pieces.Pawns.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.White_Pieces.Pawns[i].ListMateMoves(board);
            else
                temp = board.White_Pieces.Pawns[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.White_Pieces.Pawns[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.White_Pieces.Kings.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.White_Pieces.Kings[i].ListMateMoves(board);
            else
                temp = board.White_Pieces.Kings[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.White_Pieces.Kings[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.White_Pieces.Knights.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.White_Pieces.Knights[i].ListMateMoves(board);
            else
                temp = board.White_Pieces.Knights[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.White_Pieces.Knights[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.White_Pieces.Rooks.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.White_Pieces.Rooks[i].ListMateMoves(board);
            else
                temp = board.White_Pieces.Rooks[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.White_Pieces.Rooks[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.White_Pieces.Bishops.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.White_Pieces.Bishops[i].ListMateMoves(board);
            else
                temp = board.White_Pieces.Bishops[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.White_Pieces.Bishops[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.White_Pieces.Queens.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.White_Pieces.Queens[i].ListMateMoves(board);
            else
                temp = board.White_Pieces.Queens[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.White_Pieces.Queens[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
    }
    else
    {
        for (int i=0; i<board.Black_Pieces.Pawns.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.Black_Pieces.Pawns[i].ListMateMoves(board);
            else
                temp = board.Black_Pieces.Pawns[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.Black_Pieces.Pawns[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.Black_Pieces.Kings.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.Black_Pieces.Kings[i].ListMateMoves(board);
            else
                temp = board.Black_Pieces.Kings[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.Black_Pieces.Kings[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.Black_Pieces.Knights.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.Black_Pieces.Knights[i].ListMateMoves(board);
            else
                temp = board.Black_Pieces.Knights[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.Black_Pieces.Knights[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.Black_Pieces.Rooks.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.Black_Pieces.Rooks[i].ListMateMoves(board);
            else
                temp = board.Black_Pieces.Rooks[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.Black_Pieces.Rooks[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.Black_Pieces.Bishops.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.Black_Pieces.Bishops[i].ListMateMoves(board);
            else
                temp = board.Black_Pieces.Bishops[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.Black_Pieces.Bishops[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
        for (int i=0; i<board.Black_Pieces.Queens.size(); i++)
        {
            vector<string> temp;
            if(mode == 'M')
                temp = board.Black_Pieces.Queens[i].ListMateMoves(board);
            else
                temp = board.Black_Pieces.Queens[i].ListDefenceMoves(board);
            vector<vector<int>> temp_ = board.Black_Pieces.Queens[i].ListMoves(board);
            if(!temp.empty())
            {
                if(temp.size() == temp_.size())
                    Emergency_Moves.push_back(temp[0].substr(0,4));
                else
                    for(int j=0; j<temp.size(); j++)
                        Emergency_Moves.push_back(temp[j]);
            }
        }
    }
    if (Emergency_Moves.size()!=0)
    {
        sort(Emergency_Moves);
        for (int i=0; i<Emergency_Moves.size(); i++)
            cout << Emergency_Moves[i] << '\n';
    }
    else cout << "No Answer!";
    return 0;
}