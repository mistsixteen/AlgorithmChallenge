//Backjoon Problem No.33221
//https://www.acmicpc.net/problem/33221
//Mist16, 2025-07-25

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, p;
    int score = 0;
    int time = 0;

    cin >> t >> p;

    string str;

    for (int i = 0; i < p; i++)
    {
        cin >> str;

        if (str == "X")
        {
            continue;
        }

        score++;
        time += stoi(str);
    }
    int result = 0;

    for (int j = 1; j < t; j++)
    {
        int tScore = 0;
        int tTIme = 0;

        for (int i = 0; i < p; i++)
        {
            cin >> str;

            if (str == "X")
            {
                continue;
            }

            tScore++;
            tTIme += stoi(str);
        }
        if (tScore > score)
        {
            result++;
        }
        else if (tScore == score && tTIme <= time)
        {
            result++;
        }
    }

    cout << result;

    return 0;
}