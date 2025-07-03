//Backjoon Problem No.30143
//https://www.acmicpc.net/problem/30143
//Mist16, 2025-07-02

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;

    cin >> testCase;

    for (int t = 0; t < testCase; t++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        int total = 0;

        for (int i = 0; i < a; i++)
        {
            total += b;
            b += c;
        }

        cout << total << endl;
    }

    return 0;
}