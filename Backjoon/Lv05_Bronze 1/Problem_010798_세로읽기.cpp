//Backjoon Problem No.10798
//https://www.acmicpc.net/problem/10798
//Mist16, 2025-07-04

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a[5];


    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[j].size() > i)
            {
                cout << a[j][i];
            }
        }
    }

    return 0;
}