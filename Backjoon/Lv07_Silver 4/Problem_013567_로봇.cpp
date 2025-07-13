//Backjoon Problem No.13567
//https://www.acmicpc.net/problem/13567
//Mist16, 2025-07-13

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int posX = 0;
int posY = 0;

int M = 0;

int Dir = 0; //0 : E, 1 : S 2 : W 3 : N // TURN 0 +1

int Move(int pos)
{
    switch (Dir)
    {
    case 0:
        posX += pos;
        break;
    case 1:
        posY += pos;
        break;
    case 2:
        posX -= pos;
        break;
    case 3:
        posY -= pos;
        break;
    }

    if (posX < 0 || posX > M || posY < 0 || posY > M)
    {
        return -1;
    }

    return 0;
}


void Turn(bool isLeft)
{
    if (isLeft)
    {
        Dir++;
    }
    else
    {
        Dir--;
    }

    if (Dir < 0)
    {
        Dir = 3;
    }

    if (Dir > 3)
    {
        Dir = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> M >> n;

    for (int i = 0; i < n; i++)
    {
        string inputS;
        int inputI;

        cin >> inputS >> inputI;

        if (inputS == "MOVE")
        {
            int result = Move(inputI);

            if (result == -1)
            {
                cout << "-1";
                return 0;
            }
        }
        else if (inputS == "TURN")
        {
            if (inputI == 0)
            {
                Turn(true);
            }
            else
            {
                Turn(false);
            }
        }
    }

    cout << posX << " " << posY;

    return 0;
}