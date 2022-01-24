//Backjoon Problem No.15650
//https://www.acmicpc.net/problem/15650
//Mist16, 2022-01-24
#include <iostream>
#include <list>

using namespace std;

int N, M;

void check(int left, int idx, list<int> li)
{
	if (left == 0)
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
	li.push_back(idx);
	check(left - 1, idx + 1, li);
	li.pop_back();
	check(left, idx + 1, li);

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

	check(N, 1, a);

	return 0;
}