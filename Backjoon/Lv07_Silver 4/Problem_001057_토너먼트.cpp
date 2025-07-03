//Backjoon Problem No.1057
//https://www.acmicpc.net/problem/1057
//Mist16, 2025-06-28

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;
    int ans = 0;
    cin >> n >> a >> b;

    while (true)
    {
        ans++;

        int nextn = n / 2;
        if(n % 2 == 1)
        {
            nextn++;
            if (a == n)
            {
                a = nextn;
            }
            else
            {
                a = (a+1) / 2;
            }
            if (b == n)
            {
                b = nextn;
            }
            else
            {
                b = (b+1) / 2;
            }
        }
        else
        {
            a = (a+1) / 2;
            b = (b+1) / 2;
        }
        n = nextn;
        if (a == b)
        {
            break;
        }
        
    }

    cout << ans;

    return 0;
}