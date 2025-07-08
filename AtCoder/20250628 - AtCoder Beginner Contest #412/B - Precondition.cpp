#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b, strc;

    cin >> a >> b;

    strc = a;

    for (int  i = 1; i < a.size(); i++)
    {
        char c = a[i];

        if (c >= 'a' && c <= 'z')
        {
            continue;
        }

        bool isFound = false;
        
        c = strc[i - 1];

        for (char t : b)
        {
            if (t == c)
            {
                isFound = true;
                break;
            }
        }

        if (!isFound)
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}