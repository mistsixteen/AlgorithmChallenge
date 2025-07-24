//Backjoon Problem No.5086
//https://www.acmicpc.net/problem/5086
//Mist16, 2025-07-22

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            return 0;
        }

        if (a < b && b % a == 0)
        {
            cout << "factor" << endl;
        }
        else if (a > b && a % b == 0)
        {
            cout << "multiple" << endl;
        }
        else
        {
            cout << "neither" << endl;
        }
    }

    return 0;
}