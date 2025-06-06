//Backjoon Problem No.1393
//https://www.acmicpc.net/problem/1393
//Mist16, 2022-12-24

#include <iostream>
using namespace std;

int n;
char arr[128][128];

int white = 0;
int blue = 0;

void run(int, int, int);
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    run(n, 0, 0);
    cout << white << endl << blue;
    return 0;
}

void run(int level, int xPos, int yPos)
{
    if (level == 1)
    {
        if (arr[xPos][yPos] == '0')
            white++;
        else
            blue++;
        return;
    }

    bool isAllBlue = true;
    bool isAllWhite = true;

    for (int i = xPos; i < xPos + level; i++)
    {
        for (int j = yPos; j < yPos + level; j++)
        {
            if (arr[i][j] == '0')
                isAllBlue = false;
            else
                isAllWhite = false;
        }
    }
    if (isAllBlue == true)
    {
        blue++;
    }
    else if (isAllWhite == true)
    {
        white++;
    }
    else //div to next level
    {
        int newLevel = level / 2;
        run(newLevel, xPos, yPos);
        run(newLevel, xPos + newLevel, yPos);
        run(newLevel, xPos, yPos + newLevel);
        run(newLevel, xPos + newLevel, yPos + newLevel);
    }
}