//Backjoon Problem No.9547
//https://www.acmicpc.net/problem/9547
//Mist16, 2025-07-13

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T = 0;

int c, v;

int input[101][101];

void run()
{
    cin >> c >> v;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> input[i][j];
        }
    }

    int arr[101] = { 0, };

    //case 1;
    for (int i = 0; i < v; i++)
    {
        arr[input[i][0]]++;
    }

    int best = -1;
    int bestC = 0;

    for (int j = 1; j <= c; j++)
    {
        if (bestC < arr[j])
        {
            best = j;
            bestC = arr[j];
        }
    }

    if (bestC > (int)v / 2)
    {
        cout << best << " 1" << endl;
        return;
    }

    int canA = best;
    arr[best] = 0;

    best = -1;
    bestC = 0;

    for (int j = 1; j <= c; j++)
    {
        if (bestC < arr[j])
        {
            best = j;
            bestC = arr[j];
        }
    }

    int canB = best;
    int scoreA = 0, scoreB = 0;
    
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (input[i][j] == canA)
            {
                scoreA++;
                break;
            }

            if (input[i][j] == canB)
            {
                scoreB++;
                break;
            }
        }
    }

    if (scoreA > scoreB)
    {
        cout << canA << " 2" << endl;
    }
    else
    {
        cout << canB << " 2" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin >> T;


    for (int i = 0; i < T; i++)
    {
        run();
    }

    return 0;
}