//Backjoon Problem No.25206
//https://www.acmicpc.net/problem/25206
//Mist16, 2025-06-30

#include <iostream>
#include <algorithm>

using namespace std;

double totalScore = 0;
double totalPoint = 0;


double stringToScore(string a)
{
    if (a == "A+")
    {
        return 4.5;
    }
    if (a == "A0")
    {
        return 4.0;
    }
    if (a == "B+")
    {
        return 3.5;
    }
    if (a == "B0")
    {
        return 3.0;
    }
    if (a == "C+")
    {
        return 2.5;
    }
    if (a == "C0")
    {
        return 2.0;
    }
    if (a == "D+")
    {
        return 1.5;
    }
    if (a == "D0")
    {
        return 1.0;
    }
    if (a == "P")
    {
        return -1.0;
    }

    return 0.0;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    double c;

    while (cin >> a >> c >> b)
    {
        double temp = stringToScore(b);
        if (temp == -1)
        {
            continue;
        }

        totalPoint += c;
        totalScore += (c * temp);

    }

    cout << (double)(totalScore / totalPoint);

    return 0;
}