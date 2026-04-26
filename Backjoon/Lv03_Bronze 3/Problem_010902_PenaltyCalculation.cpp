//Backjoon Problem No.10902
//https://www.acmicpc.net/problem/10902
//Mist16, 2025-07-23

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int maxS = 0;
    int t = 0;
    int f = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int inputT, inputS;
        cin >> inputT >> inputS;
        if (maxS < inputS)
        {
            t = inputT;
            maxS = inputS;
            f = i;
        }
    }

    if (maxS == 0)
    {
        cout << "0";
    }
    else
    {
        int p = t + (f - 1) * 20;
        cout << p;
    }

    return 0;
}