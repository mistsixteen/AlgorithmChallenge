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
        cout << a + b << endl;
    }

    return 0;
}