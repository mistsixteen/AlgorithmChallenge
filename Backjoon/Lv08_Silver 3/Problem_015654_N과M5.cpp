//Backjoon Problem No.15654
//https://www.acmicpc.net/problem/15654
//Mist16, 2022-02-04
#include <iostream>
#include <list>

using namespace std;

int N, M;

int arr[9];

void check(list<int> li, unsigned int bitMask)
{
	if (li.size() == M)
	{
		for (auto Iter : li)
		{
			cout << Iter << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if ((bitMask & (1 << i)) == 0)
		{
			li.push_back(arr[i]);
			check(li, (bitMask | (1 << i)));
			li.pop_back();
		}
	}
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<int> a;

	//input n, pipemap;
	cin >> N >> M;

	int index = 0;
	int temp;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[index];
		index = index + 1;
		for (int j = 0; j < index - 1; j++)
		{
			if (arr[j] == arr[index-1])
			{
				index--;
				break;
			}
		}

	}
	N = index;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	check(a, 0);

	return 0;
}