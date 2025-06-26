//Backjoon Problem No.15233
//https://www.acmicpc.net/problem/15233
//Mist16, 2025-06-26

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int a, b, c;
    int scoreA = 0;
    int scoreB = 0;

    vector<string> vectorA;
    vector<string> vectorB;

    cin >> a >> b >> c;

    for (int i = 0; i < a; i++)
    {
        string temp;
        cin >> temp;
        vectorA.push_back(temp);
    }

    for (int i = 0; i < b; i++)
    {
        string temp;
        cin >> temp;
        vectorB.push_back(temp);
    }

    for (int i = 0; i < c; i++)
    {
        string temp;
        cin >> temp;

        bool found = false;

        for (string a : vectorA)
        {
            if (temp == a)
            {
                found = true;
                scoreA++;
                break;
            }
        }

        if (found)
        {
            continue;
        }

        for (string b : vectorB)
        {
            if (temp == b)
            {
                found = true;
                scoreB++;
                break;
            }
        }
    }

    if (scoreA == scoreB)
    {
        cout << "TIE";
    }
    else if (scoreA > scoreB)
    {
        cout << "A";
    }
    else
    {
        cout << "B";
    }


    return 0;
}