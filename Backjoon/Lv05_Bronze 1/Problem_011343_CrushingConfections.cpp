//Backjoon Problem No.11343
//https://www.acmicpc.net/problem/11343
//Mist16, 2025-07-18

#include <iostream>
#include <vector>
#include <string>

using namespace std;

char c[100][100];

void run()
{
    int x, y;
    cin >> y >> x;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x - 2; j++)
        {
            if (c[i][j] == c[i][j + 1] && c[i][j + 1] == c[i][j + 2])
            {
                cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << " " << i + 1 << " " << j + 3 << endl;
                return;
            }
        }
    }

    for (int i = 0; i < y - 2; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (c[i][j] == c[i + 1][j] && c[i + 1][j] == c[i + 2][j])
            {
                cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << " " << i + 3 << " " << j + 1 << endl;
                return;
            }
        }
    }
    cout << "no set found" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, r = 1;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        run();
    }

    return 0;
}