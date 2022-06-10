#include<Board.hpp>

map<char, Texture> MoveOptions;

Board::Board()
{
    MoveOptions['M'].loadFromFile("Resources/Images/Mate.png");
    MoveOptions['D'].loadFromFile("Resources/Images/Defence.png");
    MoveOptions['L'].loadFromFile("Resources/Images/Crosshair.png");
    Window = new RenderWindow(VideoMode(1000, 825), "Chess", Style::Titlebar | Style::Close);
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
void Board::MakeMove(int i, int j, int k, int l, bool Special = false)
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
    if(!Special) return;
    if (Piece[1]=='W')
    {
        if (Piece[0]=='P')
            White_Pieces.Pawns[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='R')
            White_Pieces.Rooks[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='N')
            White_Pieces.Knights[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='B')
            White_Pieces.Bishops[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='Q')
            White_Pieces.Queens[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='K')
            White_Pieces.Kings[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
    }
    else
    {
        if (Piece[0]=='P')
            Black_Pieces.Pawns[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='R')
            Black_Pieces.Rooks[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='N')
            Black_Pieces.Knights[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='B')
            Black_Pieces.Bishops[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='Q')
            Black_Pieces.Queens[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
        else if (Piece[0]=='K')
            Black_Pieces.Kings[(int)Piece[2]-48].sprite.setPosition(l*100+28, k*100+3);
    }
}
void Board::Undo_Latest_Move(bool Special = false)
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
    if(!Special)
        return;
    if (Piece[1]=='W')
    {
        if (Piece[0]=='P')
            White_Pieces.Pawns[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='R')
            White_Pieces.Rooks[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='N')
            White_Pieces.Knights[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='B')
            White_Pieces.Bishops[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='Q')
            White_Pieces.Queens[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='K')
            White_Pieces.Kings[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
    }
    else
    {
        if (Piece[0]=='P')
            Black_Pieces.Pawns[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='R')
            Black_Pieces.Rooks[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='N')
            Black_Pieces.Knights[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='B')
            Black_Pieces.Bishops[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='Q')
            Black_Pieces.Queens[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
        else if (Piece[0]=='K')
            Black_Pieces.Kings[(int)Piece[2]-48].sprite.setPosition(j*100+28, i*100+3);
    }
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
bool Board::Predict(bool colour, bool mode, bool turn, const int &num)
{
    if ((mode && is_Checkmate(!colour)) || (!mode && is_Checkmate(colour)))
        return true;
    if (num == 4 || (num == 3 && mode))
        return false;
    else
    {
        if (turn)
        {
            for (int i=0; i<White_Pieces.Pawns.size(); i++)
            {
                Pawn<Board> &pawn = White_Pieces.Pawns[i];
                vector<vector<int>> temp = pawn.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(pawn.Position[0], pawn.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<White_Pieces.Rooks.size(); i++)
            {
                Rook<Board> &rook = White_Pieces.Rooks[i];
                vector<vector<int>> temp = rook.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(rook.Position[0], rook.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<White_Pieces.Bishops.size(); i++)
            {
                Bishop<Board> &bishop = White_Pieces.Bishops[i];
                vector<vector<int>> temp = bishop.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(bishop.Position[0], bishop.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<White_Pieces.Knights.size(); i++)
            {
                Knight<Board> &knight = White_Pieces.Knights[i];
                vector<vector<int>> temp = knight.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(knight.Position[0], knight.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<White_Pieces.Queens.size(); i++)
            {
                Queen<Board> &queen = White_Pieces.Queens[i];
                vector<vector<int>> temp = queen.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(queen.Position[0], queen.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<White_Pieces.Kings.size(); i++)
            {
                King<Board> &king = White_Pieces.Kings[i];
                vector<vector<int>> temp = king.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(king.Position[0], king.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            if ((mode && turn == !colour) || (!mode && turn == colour))
                return true;
            return false;
        }
        else
        {
            for (int i=0; i<Black_Pieces.Pawns.size(); i++)
            {
                Pawn<Board> &pawn = Black_Pieces.Pawns[i];
                vector<vector<int>> temp = pawn.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(pawn.Position[0], pawn.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<Black_Pieces.Rooks.size(); i++)
            {
                Rook<Board> &rook = Black_Pieces.Rooks[i];
                vector<vector<int>> temp = rook.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(rook.Position[0], rook.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<Black_Pieces.Bishops.size(); i++)
            {
                Bishop<Board> &bishop = Black_Pieces.Bishops[i];
                vector<vector<int>> temp = bishop.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(bishop.Position[0], bishop.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<Black_Pieces.Knights.size(); i++)
            {
                Knight<Board> &knight = Black_Pieces.Knights[i];
                vector<vector<int>> temp = knight.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(knight.Position[0], knight.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<Black_Pieces.Queens.size(); i++)
            {
                Queen<Board> &queen = Black_Pieces.Queens[i];
                vector<vector<int>> temp = queen.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(queen.Position[0], queen.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            for (int i=0; i<Black_Pieces.Kings.size(); i++)
            {
                King<Board> &king = Black_Pieces.Kings[i];
                vector<vector<int>> temp = king.ListMoves(*this);
                for (int j=0; j<temp.size(); j++)
                {
                    MakeMove(king.Position[0], king.Position[1], temp[j][0], temp[j][1]);
                    if (!Predict(colour, mode, !turn, num+1))
                    {
                        Undo_Latest_Move();
                        if ((mode && turn == !colour) || (!mode && turn == colour))
                            return false;
                    }
                    else if ((mode && turn == colour) || (!mode && turn == !colour))
                    {
                        Undo_Latest_Move();
                        return true;
                    }
                    else Undo_Latest_Move();
                }
            }
            if ((mode && turn == !colour) || (!mode && turn == colour))
                return true;
            return false;
        }
    }
    return true;
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
void Board::SetupBoard()
{
    font.loadFromFile("Resources/Chilanka-Regular.otf");
    text.setFont(font);
    text.setPosition(850,30);
    text.setFillColor(Color::Black);
    text.setString("White's Turn");
    text.setCharacterSize(23);
    for(int i=0; i<8; i++)
    {
        string temp = " ";
        Coordinates[i].setFont(font);
        if(i==7) Coordinates[i].setPosition(Vector2f(10,730));
        else Coordinates[i].setPosition(Vector2f(2,30+100*i));
        Coordinates[i].setFillColor(Color::Black);
        temp[0] = '8'-i;
        Coordinates[i].setString(temp);
        Coordinates[8+i].setFont(font);
        Coordinates[8+i].setPosition(Vector2f(65+100*i,793));
        Coordinates[8+i].setFillColor(Color::Black);
        temp[0] = 'A'+i;
        Coordinates[8+i].setString(temp);
    }
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            
            GraphicsGrid[i][j].cell.setSize(Vector2f(100, 100));
            if((i+j)%2)
            {
                GraphicsGrid[i][j].cell.setFillColor(Color(81,42,42));
                GraphicsGrid[i][j].cell.setPosition(Vector2f(j*100+25, i*100));
            }
            else
            {
                GraphicsGrid[i][j].cell.setFillColor(Color(124,76,62));
                GraphicsGrid[i][j].cell.setPosition(Vector2f(j*100+25, i*100));
            }
        }
    ResetAll.setSize(Vector2f(155,50));
    ResetAll.setFillColor(Color(54,54,54));
    ResetAll.setPosition(835, 100);
    ResetAll.setOutlineThickness(1);
    ResetAll.setOutlineColor(Color::Black);
    ResetWord.setFont(font);
    ResetWord.setFillColor(Color::Black);
    ResetWord.setPosition(Vector2f(845, 113));
    ResetWord.setString("RESET MOVES");
    ResetWord.setCharacterSize(20);
    Check.setSize(Vector2f(100,100));
}
void Board::drawboard()
{
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            Window->draw(GraphicsGrid[i][j].cell);
            if(Grid[i][j]!="--")
            {
                string &temp = Grid[i][j];
                if(temp[0]=='P')
                {
                    if(temp[1]=='W')
                        Window->draw(White_Pieces.Pawns[Grid[i][j][2]-'0'].sprite);
                    else
                        Window->draw(Black_Pieces.Pawns[Grid[i][j][2]-'0'].sprite);
                }
                if(temp[0]=='K')
                {
                    if(temp[1]=='W')
                        Window->draw(White_Pieces.Kings[Grid[i][j][2]-'0'].sprite);
                    else
                        Window->draw(Black_Pieces.Kings[Grid[i][j][2]-'0'].sprite);
                }
                if(temp[0]=='R')
                {
                    if(temp[1]=='W')
                        Window->draw(White_Pieces.Rooks[Grid[i][j][2]-'0'].sprite);
                    else
                        Window->draw(Black_Pieces.Rooks[Grid[i][j][2]-'0'].sprite);
                }
                if(temp[0]=='B')
                {
                    if(temp[1]=='W')
                        Window->draw(White_Pieces.Bishops[Grid[i][j][2]-'0'].sprite);
                    else
                        Window->draw(Black_Pieces.Bishops[Grid[i][j][2]-'0'].sprite);
                }
                if(temp[0]=='N')
                {
                    if(temp[1]=='W')
                        Window->draw(White_Pieces.Knights[Grid[i][j][2]-'0'].sprite);
                    else
                        Window->draw(Black_Pieces.Knights[Grid[i][j][2]-'0'].sprite);
                }
                if(temp[0]=='Q')
                {
                    if(temp[1]=='W')
                        Window->draw(White_Pieces.Queens[Grid[i][j][2]-'0'].sprite);
                    else
                        Window->draw(Black_Pieces.Queens[Grid[i][j][2]-'0'].sprite);
                }
            }
        }
    if(is_in_Check(true))
    {
        if(is_Checkmate(true)) Check.setFillColor(Color(0,0,255));
        else Check.setFillColor(Color(255,0,0));
        int i = White_Pieces.Kings[0].Position[0], j = White_Pieces.Kings[0].Position[1];
        Check.setPosition(Vector2f(j*100+25, i*100));
        Window->draw(Check);
        Window->draw(White_Pieces.Kings[0].sprite);
    }
    if(is_in_Check(false))
    {
        if(is_Checkmate(false)) Check.setFillColor(Color(0,0,255));
        else Check.setFillColor(Color(255,0,0));
        int i = Black_Pieces.Kings[0].Position[0], j = Black_Pieces.Kings[0].Position[1];
        Check.setPosition(Vector2f(j*100+25, i*100));
        Window->draw(Check);
        Window->draw(Black_Pieces.Kings[0].sprite);
    }
    if(Turn) text.setString("White's Turn");
    else text.setString("Black's Turn");
    Window->draw(text);
    for(int i=0; i<16; i++)
    {
        Window->draw(Coordinates[i]);
    }
    Window->draw(ResetAll);
    Window->draw(ResetWord);
    for(int i=0; i<MoveChoices.size(); i++)
        Window->draw(MoveChoices[i]);
}
void Board::RunGraphics()
{
    SetupBoard();
    Window->display();
    while(Window->isOpen())
    {
        Event event;
        while(Window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                Window->close();
            if (Mouse::isButtonPressed(Mouse::Left))
                MouseClick(Mouse::getPosition(*Window));
            else if(Mouse::isButtonPressed(Mouse::Right))
                if(!Moves.empty())
                {
                    Undo_Latest_Move(true);
                    Turn = !Turn;
                }
        }
        Window->clear(Color(89,89,89));
        drawboard();
        Window->display();
    }
}
void Board::MouseClick(const Vector2i& position)
{
    if(position.x>=835 && position.x<=990 && position.y>=100 && position.y<=150)
    {
        while(!Moves.empty())
            Undo_Latest_Move(true);
        Turn = true;
    }
    else if(position.x>=25 && position.x<=825 && position.y>=0 && position.y<=800)
    {
        int x = position.y/100, y = (position.x-25)/100;
        for(int i=0; i<SelectedMoves.size(); i++)
        {
            if(SelectedMoves[i][0]==x && SelectedMoves[i][1]==y)
            {
                MakeMove(Selectedx, Selectedy, x, y, true);
                Turn = !Turn;
                SelectedMoves.clear();
                MoveChoices.clear();
                return;
            }
        }
        SelectedMoves.clear();
        MoveChoices.clear();
        if(Grid[x][y]=="--" || !((Turn && Grid[x][y][1]=='W')||(!Turn && Grid[x][y][1]=='B')))
            return;
        string temp = Grid[x][y];
        if(temp[0]=='P')
        {
            if(temp[1]=='W')
            {
                vector<vector<int>> temp_ = White_Pieces.Pawns[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = White_Pieces.Pawns[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = White_Pieces.Pawns[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
            else
            {
                vector<vector<int>> temp_ = Black_Pieces.Pawns[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = Black_Pieces.Pawns[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = Black_Pieces.Pawns[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
        }
        if(temp[0]=='K')
        {
            if(temp[1]=='W')
            {
                vector<vector<int>> temp_ = White_Pieces.Kings[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = White_Pieces.Kings[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = White_Pieces.Kings[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
            else
            {
                vector<vector<int>> temp_ = Black_Pieces.Kings[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = Black_Pieces.Kings[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = Black_Pieces.Kings[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
        }
        if(temp[0]=='R')
        {
            if(temp[1]=='W')
            {
                vector<vector<int>> temp_ = White_Pieces.Rooks[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = White_Pieces.Rooks[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = White_Pieces.Rooks[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
            else
            {
                vector<vector<int>> temp_ = Black_Pieces.Rooks[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = Black_Pieces.Rooks[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = Black_Pieces.Rooks[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
        }
        if(temp[0]=='B')
        {
            if(temp[1]=='W')
            {
                vector<vector<int>> temp_ = White_Pieces.Bishops[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = White_Pieces.Bishops[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = White_Pieces.Bishops[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
            else
            {
                vector<vector<int>> temp_ = Black_Pieces.Bishops[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = Black_Pieces.Bishops[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = Black_Pieces.Bishops[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
        }
        if(temp[0]=='N')
        {
            if(temp[1]=='W')
            {
                vector<vector<int>> temp_ = White_Pieces.Knights[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = White_Pieces.Knights[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = White_Pieces.Knights[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
            else
            {
                vector<vector<int>> temp_ = Black_Pieces.Knights[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = Black_Pieces.Knights[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = Black_Pieces.Knights[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
        }
        if(temp[0]=='Q')
        {
            if(temp[1]=='W')
            {
                vector<vector<int>> temp_ = White_Pieces.Queens[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = White_Pieces.Queens[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = White_Pieces.Queens[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
            else
            {
                vector<vector<int>> temp_ = Black_Pieces.Queens[temp[2]-'0'].ListMoves(*this);
                for(int i=0; i<temp_.size(); i++)
                    SelectedMoves.push_back({temp_[i][0], temp_[i][1]});
                for(int i=0; i<SelectedMoves.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['L']);
                    MoveChoices[MoveChoices.size()-1].setPosition(SelectedMoves[i][1]*100+28, SelectedMoves[i][0]*100+3);
                }
                auto Mate = Black_Pieces.Queens[temp[2]-'0'].ListMateMoves(*this);
                for(int i=0; i<Mate.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['M']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Mate[i][1]*100+28, Mate[i][0]*100+3);
                }
                auto Defence = Black_Pieces.Queens[temp[2]-'0'].ListDefenceMoves(*this);
                for(int i=0; i<Defence.size(); i++)
                {
                    MoveChoices.push_back(Sprite());
                    MoveChoices[MoveChoices.size()-1].setTexture(MoveOptions['D']);
                    MoveChoices[MoveChoices.size()-1].setPosition(Defence[i][1]*100+28, Defence[i][0]*100+3);
                }
                Mate.clear();
                Defence.clear();
            }
        }
        Selectedx=x;
        Selectedy=y;
        return;
    }
    SelectedMoves.clear();
    MoveChoices.clear();
    return;
}