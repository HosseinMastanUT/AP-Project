#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

static map<string, Texture> Piece_Textures;
static string tempaddress = "Resources/Images/";
static string tempnames[12] = {"RW", "PW", "KW", "BW", "QW", "NW", "RB", "PB", "KB", "BB", "QB", "NB"};
static bool l = true;

class BasePiece
{
public:
    int Position[2];
    bool colour;
    sf::Sprite sprite;
    BasePiece(char col, const int& x, const int& y) : Position{x,y}
    {
        if(l)
        {
            for(int i=0; i<12; i++)
            {
                string temp = tempaddress+tempnames[i]+".png";
                Piece_Textures[tempnames[i]].loadFromFile(temp);
            }
            l = false;
        }
        if (col == 'B')
            colour = false;
        else colour = true;
    }
};