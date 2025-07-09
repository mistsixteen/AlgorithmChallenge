//Backjoon Problem No.2501
//https://www.acmicpc.net/problem/2501
//Mist16, 2025-07-09

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
    int k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            k--;
            if (k == 0)
            {
                cout << i;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}