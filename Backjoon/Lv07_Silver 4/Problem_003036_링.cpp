//Backjoon Problem No.3036
//https://www.acmicpc.net/problem/3036
//Mist16, 2025-06-19

#include <iostream>

using namespace std;

int UclidAlg(int a, int b)
{
    while (a % b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return b;
}
int main()
{
    int N, a, b;

    cin >> N >> a;

    for (int i = 1; i < N; i++)
    {
        cin >> b;
        int Uc = UclidAlg(a, b);
        cout << a / Uc << "/" << b / Uc << endl;
    }
}