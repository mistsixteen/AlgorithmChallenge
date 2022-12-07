//Backjoon Problem No.15666
//https://www.acmicpc.net/problem/15666
//Mist16, 2022-02-04
#include <iostream>
#include <list>

using namespace std;

int N, M;

int arr[9];

void check(int idx, list<int> li)
{
	if (li.size() == M)
	{
		for (auto Iter : li)
		{
			cout << Iter << " ";
		}
		cout << endl;
		return;
	}
	if (idx >= N)
		return;
	int left = M - li.size();
	for (int i = 1; i <= left; i++)
	{
		li.push_back(arr[idx]);
	}
	for (int i = 1; i <= left; i++)
	{
		check(idx + 1, li);
		li.pop_back();
	}
	check(idx + 1, li);

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

	check(0, a);

	return 0;
}