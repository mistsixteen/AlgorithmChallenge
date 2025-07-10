//Backjoon Problem No.9506
//https://www.acmicpc.net/problem/9506
//Mist16, 2025-07-09

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (true)
    {
        int n;
        cin >> n;

        vector<int> vector;
        int result = 0;

        if (n == -1)
        {
            break;
        }

        for (int i = 1; i * 2 <= n; i++)
        {
            if (n % i == 0)
            {
                vector.push_back(i);
                result += i;
            }
        }

        if (n != result)
        {
            cout << n << " is NOT perfect." << endl;;
        }
        else
        {
            cout << n << " = " << vector[0];

            for (int i = 1; i < vector.size(); i++)
            {
                cout << " + " << vector[i];
            }

            cout << endl;
        }
    }

    return 0;
}