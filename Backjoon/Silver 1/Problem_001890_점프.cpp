//Backjoon Problem No.1890
//https://www.acmicpc.net/problem/1890
//Mist16, 2022-12-26

#include <iostream>
using namespace std;


int arr[100][100] = { 0, };
unsigned long long result[100][100];
int n = 0;

unsigned long long run(int x, int y)
{

    if (x == n - 1 && y == n - 1)
        return 1;
    if (result[x][y] != -1)
        return result[x][y];

    result[x][y] = run(x + arr[x][y], y) + run(x, y + arr[x][y]);

    return result[x][y];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                result[i][j] = 0;
            else
                result[i][j] = -1;
        }

    result[n - 1][n - 1] = 1;

    cout << run(0, 0) << endl;
}
