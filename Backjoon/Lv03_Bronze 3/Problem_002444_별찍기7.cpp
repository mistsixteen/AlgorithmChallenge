//Backjoon Problem No.2444
//https://www.acmicpc.net/problem/2444
//Mist16, 2025-07-02

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i*2-1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}