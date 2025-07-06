//Backjoon Problem No.10988
//https://www.acmicpc.net/problem/10988
//Mist16, 2025-07-06

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string n;

    cin >> n;

    int idx1 = 0;
    int idx2 = n.size() - 1;

    while (idx1 < idx2)
    {
        if (n[idx1] != n[idx2])
        {
            cout << 0;
            return 0;
        }
        
        idx1++;
        idx2--;
    }

    cout << 1;
    return 0;
}