//Backjoon Problem No.26004
//https://www.acmicpc.net/problem/26004
//Mist16, 2025-07-11

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
    string s;
    cin >> n;
    cin >> s;

    int arr[5] = { 0, 0, 0, 0, 0 };

    for (char c : s)
    {
        switch (c)
        {
            case 'H':
                arr[0]++;
                break;
            case 'I':
                arr[1]++;
                break;
            case 'A':
                arr[2]++;
                break;
            case 'R':
                arr[3]++;
                break;
            case 'C':
                arr[4]++;
                break;
        }
    }

    int min = 99999999;

    for (int i = 0; i < 5; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    cout << min;

    return 0;
}