#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int answer = 0;
    int a, b;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        if (a < b)
        {
            answer++;
        }

    }

    cout << answer;

    return 0;
}