//Backjoon Problem No.6030
//https://www.acmicpc.net/problem/6030
//Mist16, 2025-06-27

#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list<int> arrA;
    list<int> arrB;

    int p, q;

    cin >> p >> q;

    for (int i = 1; i <= p; i++)
    {
        if (p % i == 0)
        {
            arrA.push_back(i);
        }
    }

    for (int i = 1; i <= q; i++)
    {
        if (q % i == 0)
        {
            arrB.push_back(i);
        }
    }

    for (int i : arrA)
    {
        for (int j : arrB)
        {
            cout << i << " " << j << endl;
        }
    }

    return 0;
}