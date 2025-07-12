//Backjoon Problem No.15161
//https://www.acmicpc.net/problem/15161
//Mist16, 2025-07-13

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr[10][10];

void Init()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = 1;
        }
    }
}

void NextStep()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j]++;
        }
    }
}

void CutY(int t)
{
    for (int i = 0; i < 10; i++)
    {
        arr[i][t-1] = 0;
    }
}

void CutX(int t)
{
    for (int i = 0; i < 10; i++)
    {
        arr[t-1][i] = 0;
    }
}

void Print()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    Init();

    for (int i = 0; i < n; i++)
    {
        int input[6];
        cin >> input[0] >> input[1] >> input[2] >> input[3] >> input[4] >> input[5];

        CutX(input[0]);
        CutX(input[1]);
        CutX(input[2]);
        CutY(input[3]);
        CutY(input[4]);
        CutY(input[5]);

        NextStep();
    }

    Print();

    return 0;
}