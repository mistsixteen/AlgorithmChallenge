//Backjoon Problem No.15236
//https://www.acmicpc.net/problem/15236
//Mist16, 2025-07-04

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int result = 0;

    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            result += (i+j);
        }
    }

    cout << result;

    return 0;
}