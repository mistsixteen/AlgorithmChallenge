#include <iostream>
#include <algorithm>

using namespace std;

long arr[200100];
int result = -1;
int n;

void runCase(int idx, int score)
{
    if (idx == n - 1)
    {
        if (result == -1 || result > score)
        {
            result = score;
        }

        return;
    }

    if (arr[idx] * 2 >= arr[n - 1])
    {
        score++;

        if (result == -1 || result > score)
        {
            result = score;
        }

        return;
    }

    int nextIdx = -1;

    for (int i = idx + 1; i < n; i++)
    {
        if (arr[idx] * 2 >= arr[i])
        {
            nextIdx = i;
        }
        else
        {
            break;
        }
    }

    if (nextIdx != -1)
    {
        runCase(nextIdx, score + 1);
    }
}

void run()
{
    cin >> n;
    result = -1;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> arr[i];
    }

    sort(&arr[1], &arr[1] + (n - 2));

    runCase(0, 1);
    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int C;

    cin >> C;

    for (int i = 0; i < C; i++)
    {
        run();
    }

    return 0;
}