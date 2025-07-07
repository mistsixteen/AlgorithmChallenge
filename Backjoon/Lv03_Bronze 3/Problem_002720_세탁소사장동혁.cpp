//Backjoon Problem No.2720
//https://www.acmicpc.net/problem/2720
//Mist16, 2025-07-07

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int m;
        int c;
        cin >> m;

        c = m / 25;
        cout << c << " ";
        m -= (c * 25);

        c = m / 10;
        cout << c << " ";
        m -= (c * 10);

        c = m / 5;
        cout << c << " ";
        m -= (c * 5);
        cout << m << endl;
    }

    return 0;
}