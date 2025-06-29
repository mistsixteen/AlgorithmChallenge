//Backjoon Problem No.10811
//https://www.acmicpc.net/problem/1081
//Mist16, 2025-06-30

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[101] = { 0 };
    int arr2[101] = { 0 };

    int n, m;

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        int c = b - a;

        for (int j = 0; j <= c; j++)
        {
            arr2[j] = arr[a + j];
        }

        for (int j = 0; j <= c; j++)
        {
            arr[b-j] = arr2[j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}