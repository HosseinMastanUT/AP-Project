#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<Pawn.hpp>
#include<King.hpp>
#include<Queen.hpp>
#include<Knight.hpp>
#include<Rook.hpp>
#include<Bishop.hpp>
using namespace std;

class Board
{
public:
    struct Pieces
    {
        vector<King<Board>> Kings;
        vector<Queen<Board>> Queens;
        vector<Knight<Board>> Knights;
        vector<Rook<Board>> Rooks;
        vector<Bishop<Board>> Bishops;
        vector<Pawn<Board>> Pawns;
    } White_Pieces, Black_Pieces;
    vector<string> Moves;
    string Grid[8][8];
    bool Turn = true;
    Board();
    bool is_in_Check(bool);
    void MakeMove(int, int, int, int);
    void Undo_Latest_Move();
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
};

Board::Board()
{
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
        {
            cin >> Grid[i][j];
            if(Grid[i][j][0]=='P')
            {
                if(Grid[i][j][1]=='W')
                {
                    White_Pieces.Pawns.push_back(Pawn<Board>('W', i, j));
                    Grid[i][j]+=(char)(White_Pieces.Pawns.size()+47);
                }
                else
                {
                    Black_Pieces.Pawns.push_back(Pawn<Board>('B', i, j));
                    Grid[i][j]+=(char)(Black_Pieces.Pawns.size()+47);
                }
            }
            if(Grid[i][j][0]=='K')
            {
                if(Grid[i][j][1]=='W')
                {
                    White_Pieces.Kings.push_back(King<Board>('W', i, j));
                    Grid[i][j]+=(char)(White_Pieces.Kings.size()+47);
                }
                else
                {
                    Black_Pieces.Kings.push_back(King<Board>('B', i, j));
                    Grid[i][j]+=(char)(Black_Pieces.Kings.size()+47);
                }
            }
            if(Grid[i][j][0]=='R')
            {
                if(Grid[i][j][1]=='W')
                {
                    White_Pieces.Rooks.push_back(Rook<Board>('W', i, j));
                    Grid[i][j]+=(char)(White_Pieces.Rooks.size()+47);
                }
                else
                {
                    Black_Pieces.Rooks.push_back(Rook<Board>('B', i, j));
                    Grid[i][j]+=(char)(Black_Pieces.Rooks.size()+47);
                }
            }
            if(Grid[i][j][0]=='B')
            {
                if(Grid[i][j][1]=='W')
                {
                    White_Pieces.Bishops.push_back(Bishop<Board>('W', i, j));
                    Grid[i][j]+=(char)(White_Pieces.Bishops.size()+47);
                }
                else
                {
                    Black_Pieces.Bishops.push_back(Bishop<Board>('B', i, j));
                    Grid[i][j]+=(char)(Black_Pieces.Bishops.size()+47);
                }
            }
            if(Grid[i][j][0]=='N')
            {
                if(Grid[i][j][1]=='W')
                {
                    White_Pieces.Knights.push_back(Knight<Board>('W', i, j));
                    Grid[i][j]+=(char)(White_Pieces.Knights.size()+47);
                }
                else
                {
                    Black_Pieces.Knights.push_back(Knight<Board>('B', i, j));
                    Grid[i][j]+=(char)(Black_Pieces.Knights.size()+47);
                }
            }
            if(Grid[i][j][0]=='Q')
            {
                if(Grid[i][j][1]=='W')
                {
                    White_Pieces.Queens.push_back(Queen<Board>('W', i, j));
                    Grid[i][j]+=(char)(White_Pieces.Queens.size()+47);
                }
                else
                {
                    Black_Pieces.Queens.push_back(Queen<Board>('B', i, j));
                    Grid[i][j]+=(char)(Black_Pieces.Queens.size()+47);
                }
            }
        }
}
bool Board::is_in_Check(bool col)
{
    if (col)
    {
        int x=White_Pieces.Kings[0].Position[0], y=White_Pieces.Kings[0].Position[1], list[8][2] = {{x+2, y+1}, {x+2, y-1}, {x+1, y+2}, {x+1, y-2}, {x-1, y+2}, {x-1, y-2}, {x-2, y+1}, {x-2, y-1}};
        for (int k=0; k<8; k++)
            if(list[k][0]>=0 && list[k][0]<8 && list[k][1]>=0 && list[k][1]<8 && Grid[list[k][0]][list[k][1]][0]=='N' && Grid[list[k][0]][list[k][1]][1]=='B')
                return true;
        for (int i = 1; i<=x; i++)
            if(Grid[x-i][y] != "--")
                {
                    if (Grid[x-i][y][1]=='B')
                        if(Grid[x-i][y][0]=='Q' || Grid[x-i][y][0]=='R' || (i==1 && Grid[x-i][y][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=y; i++)
            if(Grid[x][y-i] != "--")
                {
                    if (Grid[x][y-i][1]=='B')
                        if(Grid[x][y-i][0]=='Q' || Grid[x][y-i][0]=='R' || (i==1 && Grid[x][y-i][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=7-x; i++)
            if(Grid[x+i][y] != "--")
                {
                    if (Grid[x+i][y][1]=='B')
                        if(Grid[x+i][y][0]=='Q' || Grid[x+i][y][0]=='R' || (i==1 && Grid[x+i][y][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=7-y; i++)
            if(Grid[x][y+i] != "--")
                {
                    if (Grid[x][y+i][1]=='B')
                        if(Grid[x][y+i][0]=='Q' || Grid[x][y+i][0]=='R' || (i==1 && Grid[x][y+i][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=min(x,y); i++)
            if(Grid[x-i][y-i] != "--")
                {
                    if (Grid[x-i][y-i][1]=='B')
                        if(Grid[x-i][y-i][0]=='Q' || Grid[x-i][y-i][0]=='B' || (i==1 && (Grid[x-i][y-i][0]=='P' || Grid[x-i][y-i][0]=='K')))
                            return true;
                    break;
                }
        for (int i = 1; i<=min(x,7-y); i++)
            if(Grid[x-i][y+i] != "--")
                {
                    if (Grid[x-i][y+i][1]=='B')
                        if(Grid[x-i][y+i][0]=='Q' || Grid[x-i][y+i][0]=='B' || (i==1 && (Grid[x-i][y+i][0]=='P' || Grid[x-i][y+i][0]=='K')))
                            return true;
                    break;
                }
        for (int i = 1; i<=min(7-x,y); i++)
            if(Grid[x+i][y-i] != "--")
                {
                    if (Grid[x+i][y-i][1]=='B')
                        if(Grid[x+i][y-i][0]=='Q' || Grid[x+i][y-i][0]=='B' || (i==1 && Grid[x+i][y-i][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=min(7-x,7-y); i++)
            if(Grid[x+i][y+i] != "--")
                {
                    if (Grid[x+i][y+i][1]=='B')
                        if(Grid[x+i][y+i][0]=='Q' || Grid[x+i][y+i][0]=='B' || (i==1 && Grid[x+i][y+i][0]=='K'))
                            return true;
                    break;
                }
    }
    else
    {
        int x=Black_Pieces.Kings[0].Position[0], y=Black_Pieces.Kings[0].Position[1], list[8][2] = {{x+2, y+1}, {x+2, y-1}, {x+1, y+2}, {x+1, y-2}, {x-1, y+2}, {x-1, y-2}, {x-2, y+1}, {x-2, y-1}};
        for (int k=0; k<8; k++)
            if(list[k][0]>=0 && list[k][0]<8 && list[k][1]>=0 && list[k][1]<8 && Grid[list[k][0]][list[k][1]][0]=='N' && Grid[list[k][0]][list[k][1]][1]=='W')
            {
                return true;
            }
        for (int i = 1; i<=x; i++)
            if(Grid[(x)-i][y] != "--")
                {
                    if (Grid[(x)-i][y][1]=='W')
                        if(Grid[(x)-i][y][0]=='Q' || Grid[(x)-i][y][0]=='R' || (i==1 && Grid[(x)-i][y][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=y; i++)
            if(Grid[(x)][y-i] != "--")
                {
                    if (Grid[(x)][y-i][1]=='W')
                        if(Grid[(x)][y-i][0]=='Q' || Grid[(x)][y-i][0]=='R' || (i==1 && Grid[(x)][y-i][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=7-x; i++)
            if(Grid[(x)+i][y] != "--")
                {
                    if (Grid[(x)+i][y][1]=='W')
                        if(Grid[(x)+i][y][0]=='Q' || Grid[(x)+i][y][0]=='R' || (i==1 && Grid[(x)+i][y][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=7-y; i++)
            if(Grid[(x)][y+i] != "--")
                {
                    if (Grid[(x)][y+i][1]=='W')
                        if(Grid[(x)][y+i][0]=='Q' || Grid[(x)][y+i][0]=='R' || (i==1 && Grid[(x)][y+i][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=min(x,y); i++)
            if(Grid[(x)-i][y-i] != "--")
                {
                    if (Grid[(x)-i][y-i][1]=='W')
                        if(Grid[(x)-i][y-i][0]=='Q' || Grid[(x)-i][y-i][0]=='B' || (i==1 && Grid[(x)-i][y-i][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=min(x,7-y); i++)
            if(Grid[(x)-i][y+i] != "--")
                {
                    if (Grid[(x)-i][y+i][1]=='W')
                        if(Grid[(x)-i][y+i][0]=='Q' || Grid[(x)-i][y+i][0]=='B' || (i==1 && Grid[(x)-i][y+i][0]=='K'))
                            return true;
                    break;
                }
        for (int i = 1; i<=min(7-x,y); i++)
            if(Grid[(x)+i][y-i] != "--")
                {
                    if (Grid[(x)+i][y-i][1]=='W')
                        if(Grid[(x)+i][y-i][0]=='Q' || Grid[(x)+i][y-i][0]=='B' || (i==1 && (Grid[(x)+i][y-i][0]=='P' || Grid[(x)+i][y-i][0]=='K')))
                            return true;
                    break;
                }
        for (int i = 1; i<=min(7-x,7-y); i++)
            if(Grid[(x)+i][y+i] != "--")
                {
                    if (Grid[(x)+i][y+i][1]=='W')
                        if(Grid[(x)+i][y+i][0]=='Q' || Grid[(x)+i][y+i][0]=='B' || (i==1 && (Grid[(x)+i][y+i][0]=='P' || Grid[(x)+i][y+i][0]=='K')))
                            return true;
                    break;
                }
    }
    return false;
}
void Board::MakeMove(int i, int j, int k, int l)
{
    string Piece = Grid[i][j], Eliminated_Piece = Grid[k][l], move = "0000";
    move[0] = (char)(i+48); move[1] = (char)(j+48); move[2] = (char)(k+48); move[3] = (char)(l+48);
    if (Eliminated_Piece != "--")
    {
        move += 'X' + Eliminated_Piece;
        if (Eliminated_Piece[1]=='W')
        {
            if (Eliminated_Piece[0]=='P')
                White_Pieces.Pawns[(int)Eliminated_Piece[2]-48].Position[0] = -1;
            else if (Eliminated_Piece[0]=='R')
                White_Pieces.Rooks[(int)Eliminated_Piece[2]-48].Position[0] = -1;
            else if (Eliminated_Piece[0]=='N')
                White_Pieces.Knights[(int)Eliminated_Piece[2]-48].Position[0] = -1;
            else if (Eliminated_Piece[0]=='B')
                White_Pieces.Bishops[(int)Eliminated_Piece[2]-48].Position[0] = -1;
            else if (Eliminated_Piece[0]=='Q')
                White_Pieces.Queens[(int)Eliminated_Piece[2]-48].Position[0] = -1;
        }
        else
        {
            if (Eliminated_Piece[0]=='P')
                Black_Pieces.Pawns[(int)Eliminated_Piece[2]-48].Position[0] = -1;
            else if (Eliminated_Piece[0]=='R')
                Black_Pieces.Rooks[(int)Eliminated_Piece[2]-48].Position[0] = -1;
            else if (Eliminated_Piece[0]=='N')
                Black_Pieces.Knights[(int)Eliminated_Piece[2]-48].Position[0] = -1;
            else if (Eliminated_Piece[0]=='B')
                Black_Pieces.Bishops[(int)Eliminated_Piece[2]-48].Position[0] = -1;
            else if (Eliminated_Piece[0]=='Q')
                Black_Pieces.Queens[(int)Eliminated_Piece[2]-48].Position[0] = -1;
        }
    }
    if (Piece[1]=='W')
        {
            if (Piece[0]=='P')
                {White_Pieces.Pawns[(int)Piece[2]-48].Position[0] = k; White_Pieces.Pawns[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='R')
                {White_Pieces.Rooks[(int)Piece[2]-48].Position[0] = k; White_Pieces.Rooks[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='N')
                {White_Pieces.Knights[(int)Piece[2]-48].Position[0] = k; White_Pieces.Knights[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='B')
                {White_Pieces.Bishops[(int)Piece[2]-48].Position[0] = k; White_Pieces.Bishops[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='Q')
                {White_Pieces.Queens[(int)Piece[2]-48].Position[0] = k; White_Pieces.Queens[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='K')
                {White_Pieces.Kings[(int)Piece[2]-48].Position[0] = k; White_Pieces.Kings[(int)Piece[2]-48].Position[1] = l;}
        }
    else
        {
            if (Piece[0]=='P')
                {Black_Pieces.Pawns[(int)Piece[2]-48].Position[0] = k; Black_Pieces.Pawns[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='R')
                {Black_Pieces.Rooks[(int)Piece[2]-48].Position[0] = k; Black_Pieces.Rooks[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='N')
                {Black_Pieces.Knights[(int)Piece[2]-48].Position[0] = k; Black_Pieces.Knights[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='B')
                {Black_Pieces.Bishops[(int)Piece[2]-48].Position[0] = k; Black_Pieces.Bishops[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='Q')
                {Black_Pieces.Queens[(int)Piece[2]-48].Position[0] = k; Black_Pieces.Queens[(int)Piece[2]-48].Position[1] = l;}
            else if (Piece[0]=='K')
                {Black_Pieces.Kings[(int)Piece[2]-48].Position[0] = k; Black_Pieces.Kings[(int)Piece[2]-48].Position[1] = l;}
        }
    Grid[i][j] = "--";
    Grid[k][l] = Piece;
    Moves.push_back(move);
}
void Board::Undo_Latest_Move()
{
    if (Moves.size()==0)
        return;
    string &move = Moves.back();
    int i = (int)move[0] - 48, j = (int)move[1] - 48, k = (int)move[2]-48, l = (int)move[3]-48;
    string Piece = Grid[k][l];
    if (Piece[1]=='W')
        {
            if (Piece[0]=='P')
                {White_Pieces.Pawns[(int)Piece[2]-48].Position[0] = i; White_Pieces.Pawns[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='R')
                {White_Pieces.Rooks[(int)Piece[2]-48].Position[0] = i; White_Pieces.Rooks[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='N')
                {White_Pieces.Knights[(int)Piece[2]-48].Position[0] = i; White_Pieces.Knights[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='B')
                {White_Pieces.Bishops[(int)Piece[2]-48].Position[0] = i; White_Pieces.Bishops[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='Q')
                {White_Pieces.Queens[(int)Piece[2]-48].Position[0] = i; White_Pieces.Queens[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='K')
                {White_Pieces.Kings[(int)Piece[2]-48].Position[0] = i; White_Pieces.Kings[(int)Piece[2]-48].Position[1] = j;}
        }
    else
        {
            if (Piece[0]=='P')
                {Black_Pieces.Pawns[(int)Piece[2]-48].Position[0] = i; Black_Pieces.Pawns[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='R')
                {Black_Pieces.Rooks[(int)Piece[2]-48].Position[0] = i; Black_Pieces.Rooks[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='N')
                {Black_Pieces.Knights[(int)Piece[2]-48].Position[0] = i; Black_Pieces.Knights[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='B')
                {Black_Pieces.Bishops[(int)Piece[2]-48].Position[0] = i; Black_Pieces.Bishops[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='Q')
                {Black_Pieces.Queens[(int)Piece[2]-48].Position[0] = i; Black_Pieces.Queens[(int)Piece[2]-48].Position[1] = j;}
            else if (Piece[0]=='K')
                {Black_Pieces.Kings[(int)Piece[2]-48].Position[0] = i; Black_Pieces.Kings[(int)Piece[2]-48].Position[1] = j;}
        }
    Grid[i][j] = Piece;
    Grid[k][l] = "--";
    if (move[4]=='X')
    {
        string Eliminated_Piece = move.substr(5,3);
        if (Eliminated_Piece[1]=='W')
        {
            if (Eliminated_Piece[0]=='P')
                White_Pieces.Pawns[(int)Eliminated_Piece[2]-48].Position[0] = k;
            else if (Eliminated_Piece[0]=='R')
                White_Pieces.Rooks[(int)Eliminated_Piece[2]-48].Position[0] = k;
            else if (Eliminated_Piece[0]=='N')
                White_Pieces.Knights[(int)Eliminated_Piece[2]-48].Position[0] = k;
            else if (Eliminated_Piece[0]=='B')
                White_Pieces.Bishops[(int)Eliminated_Piece[2]-48].Position[0] = k;
            else if (Eliminated_Piece[0]=='Q')
                White_Pieces.Queens[(int)Eliminated_Piece[2]-48].Position[0] = k;
        }
        else
        {
            if (Eliminated_Piece[0]=='P')
                Black_Pieces.Pawns[(int)Eliminated_Piece[2]-48].Position[0] = k;
            else if (Eliminated_Piece[0]=='R')
                Black_Pieces.Rooks[(int)Eliminated_Piece[2]-48].Position[0] = k;
            else if (Eliminated_Piece[0]=='N')
                Black_Pieces.Knights[(int)Eliminated_Piece[2]-48].Position[0] = k;
            else if (Eliminated_Piece[0]=='B')
                Black_Pieces.Bishops[(int)Eliminated_Piece[2]-48].Position[0] = k;
            else if (Eliminated_Piece[0]=='Q')
                Black_Pieces.Queens[(int)Eliminated_Piece[2]-48].Position[0] = k;
        }
        Grid[k][l] = Eliminated_Piece;
    }
    Moves.pop_back();
}
bool Board::is_Checkmate(bool col)
{
    if (col)
    {
        for (int i=0; i<White_Pieces.Pawns.size(); i++)
            if(!White_Pieces.Pawns[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<White_Pieces.Rooks.size(); i++)
            if(!White_Pieces.Rooks[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<White_Pieces.Knights.size(); i++)
            if(!White_Pieces.Knights[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<White_Pieces.Kings.size(); i++)
            if(!White_Pieces.Kings[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<White_Pieces.Bishops.size(); i++)
            if(!White_Pieces.Bishops[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<White_Pieces.Queens.size(); i++)
            if(!White_Pieces.Queens[i].ListMoves(*this).empty())
                return false;
        if (is_in_Check(col))
            return true;
    }
    else
    {
        for (int i=0; i<Black_Pieces.Pawns.size(); i++)
            if(!Black_Pieces.Pawns[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<Black_Pieces.Rooks.size(); i++)
            if(!Black_Pieces.Rooks[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<Black_Pieces.Knights.size(); i++)
            if(!Black_Pieces.Knights[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<Black_Pieces.Kings.size(); i++)
            if(!Black_Pieces.Kings[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<Black_Pieces.Bishops.size(); i++)
            if(!Black_Pieces.Bishops[i].ListMoves(*this).empty())
                return false;
        for (int i=0; i<Black_Pieces.Queens.size(); i++)
            if(!Black_Pieces.Queens[i].ListMoves(*this).empty())
                return false;
        if (is_in_Check(col))
            return true;
    }
    return false;
}

string Board::ConvertMove(string &move)
{
    string ans;
    if(move.length()>2)
    {
        ans = "A0KBA0";
        ans[0] = 'a' + move[1] - '0';
        ans[1] = '8' - move[0] + '0';
        ans[2] = Grid[(int)(move[2]-'0')][(int)(move[3]-'0')][0];
        ans[3] = Grid[(int)(move[2]-'0')][(int)(move[3]-'0')][1];
        ans[4] = 'a' + move[3] - '0';
        ans[5] = '8' - move[2] + '0';
    }
    else
    {
        ans = "A0KB";
        ans[0] = 'a' + move[1] - '0';
        ans[1] = '8' - move[0] + '0';
        ans[2] = Grid[(int)(move[2]-'0')][(int)(move[3]-'0')][0];
        ans[3] = Grid[(int)(move[2]-'0')][(int)(move[3]-'0')][1];
    }
    return ans;
}
void Board::PlayChess()
{
    string Command;
    while(!is_Checkmate(true) && !is_Checkmate(false))
    {
        cin >> Command;
        if (Command=="fin")
        {
            if(Turn)
                cout << "black win";
            else cout << "white win";
            return;
        }
        if ((Command[3]=='W'&&!Turn)||(Command[3]=='B'&&Turn))
            cout << "not your turn" << '\n';
        else
        {
            int i = (int)('8'-Command[1]), j = (int)(Command[0]-'a'), k = (int)('8'-Command[5]), l = (int)(Command[4]-'a');
            if(Grid[i][j][1]=='W')
            {
                if(Grid[i][j][0]=='P')
                {
                    vector<vector<int>> temp = White_Pieces.Pawns[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (!Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }
                if(Grid[i][j][0]=='N')
                {
                    vector<vector<int>> temp = White_Pieces.Knights[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (!Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }if(Grid[i][j][0]=='R')
                {
                    vector<vector<int>> temp = White_Pieces.Rooks[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (!Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }if(Grid[i][j][0]=='B')
                {
                    vector<vector<int>> temp = White_Pieces.Bishops[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (!Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }if(Grid[i][j][0]=='Q')
                {
                    vector<vector<int>> temp = White_Pieces.Queens[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (!Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }if(Grid[i][j][0]=='K')
                {
                    vector<vector<int>> temp = White_Pieces.Kings[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (!Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }
            }
            else
            {
                if(Grid[i][j][0]=='P')
                {
                    vector<vector<int>> temp = Black_Pieces.Pawns[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }
                if(Grid[i][j][0]=='N')
                {
                    vector<vector<int>> temp = Black_Pieces.Knights[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }if(Grid[i][j][0]=='R')
                {
                    vector<vector<int>> temp = Black_Pieces.Rooks[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }if(Grid[i][j][0]=='B')
                {
                    vector<vector<int>> temp = Black_Pieces.Bishops[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }if(Grid[i][j][0]=='Q')
                {
                    vector<vector<int>> temp = Black_Pieces.Queens[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }if(Grid[i][j][0]=='K')
                {
                    vector<vector<int>> temp = Black_Pieces.Kings[(int)Grid[i][j][2]-'0'].ListMoves(*this);
                    bool valid = true;
                    for(int x=0; x<temp.size(); x++)
                        if(temp[x][0]==k && temp[x][1]==l)
                        {
                            if (Turn) cout << "not your turn";
                            else
                            {
                                MakeMove(i,j,k,l);
                                Turn=!Turn;
                                cout << "done" << '\n';
                            }
                            valid = false;
                            break;
                        }
                    if(valid) cout << "try again" << '\n';
                }
            }
        }
    }
    if(is_Checkmate(true))
        cout << "black win";
    else cout << "white win";
}