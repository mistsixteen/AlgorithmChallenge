//Backjoon Problem No.25828
//https://www.acmicpc.net/problem/25828
//Mist16, 2025-06-25

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    int resultA = a * b;
    int resultB = a + (b * c);

    if (resultA == resultB)
    {
        cout << 0;
    }
    else if (resultA > resultB)
    {
        cout << 2;
    }
    else
    {
        cout << 1;
    }

    return 0;
}