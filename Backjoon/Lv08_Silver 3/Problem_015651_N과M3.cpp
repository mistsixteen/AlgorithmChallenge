//Backjoon Problem No.15651
//https://www.acmicpc.net/problem/15651
//Mist16, 2022-02-27

#include <iostream>
#include <list>

using namespace std;

int N, M;

void check(list<int> li)
{
	if (li.size() == N)
	{
		for (auto Iter : li)
		{
			cout << Iter << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= M; i++)
	{

		li.push_back(i);
		check(li);
		li.pop_back();
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
	cin >> M >> N;

	check(a);

	return 0;
}