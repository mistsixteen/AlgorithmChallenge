//Backjoon Problem No.15652
//https://www.acmicpc.net/problem/15652
//Mist16, 2022-02-04
#include <iostream>
#include <list>

using namespace std;

int N, M;

void check(int idx, list<int> li)
{
	if (li.size() == N)
	{
		for (auto Iter : li)
		{
			cout << Iter << " ";
		}
		cout << endl;
		return;
	}
	if (idx > M)
		return;
	int left = N - li.size();
	for (int i = 1; i <= left; i++)
	{
		li.push_back(idx);
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
	cin >> M >> N;

	check(1, a);

	return 0;
}