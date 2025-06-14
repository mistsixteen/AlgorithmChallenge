#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getRealPos(int N, int currentPos, int q)
{
	return (currentPos + q) % N;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int* arr = new int[1000000]();

	int N, Q;
	int currentPos = 0;
	cin >> N >> Q;

	for (int i = 0; i < Q; i++)
	{
		int qType;
		int pos, x, rPos;
		cin >> qType;
		switch (qType)
		{
		case 1:
			cin >> pos >> x;
			rPos = getRealPos(N, currentPos, pos-1);
			arr[rPos] = x;
			break;
		case 2:
			cin >> pos;
			rPos = getRealPos(N, currentPos, pos-1);
			if (arr[rPos] == 0)
			{
				cout << rPos + 1 << endl;
			}
			else
			{
				cout << arr[rPos] << endl;
			}
			break;
		case 3:
			cin >> pos;
			currentPos = getRealPos(N, currentPos, pos);
			break;
		}
	}

	return 0;
}