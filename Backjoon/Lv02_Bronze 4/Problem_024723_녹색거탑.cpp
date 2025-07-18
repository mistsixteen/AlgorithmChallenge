//Backjoon Problem No.24723
//https://www.acmicpc.net/problem/24723
//Mist16, 2025-07-17

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, r = 1;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        r *= 2;
    }

    cout << r;


    return 0;
}