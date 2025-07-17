//Backjoon Problem No.27433
//https://www.acmicpc.net/problem/27433
//Mist16, 2025-07-17

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long F(long long n)
{
    if (n == 0)
        return 1;
    else
        return F(n - 1) * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long n;

    cin >> n;

    cout << F(n);

    return 0;
}