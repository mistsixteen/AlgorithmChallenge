//Backjoon Problem No.2960
//https://www.acmicpc.net/problem/2960
//Mist16, 2022-04-26

#include <iostream>
using namespace std;

int run(int N, int K)
{
	int numArray[1001] = { 0, };
	int idx = 2;
	while (idx <= N)
	{
		if (numArray[idx] == 0)
		{
			for (int i = idx; i <= N; i += idx)
			{
				if (numArray[i] == 0)
				{
					numArray[i] = 1;
					K--;
					if (K == 0)
						return i;
				}
			}
		}
		idx++;
	}

}

int main()
{
	int N, K;
	cin >> N >> K;
	cout << run(N, K);

	return 0;
}