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
    Board board;
    board.RunGraphics();
    return 0;
}