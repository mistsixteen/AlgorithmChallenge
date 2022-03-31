//Backjoon Problem No.11651
//https://www.acmicpc.net/problem/11651
//Mist16, 2022-04-01

#include <iostream>
#include <set>
using namespace std;

struct Coord2
{
	int x;
	int y;
};

bool Comp(Coord2 a, Coord2 b)
{
	if (a.y == b.y)
	{
		return a.x < b.x;
	}
	else
		return a.y < b.y;
}


int main()
{
	int N;
	Coord2 temp;
	set<Coord2, decltype(Comp)*> CoordSet(Comp);

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> temp.x >> temp.y;
		CoordSet.insert(temp);
	}

	for (Coord2 s : CoordSet)
	{
		cout << s.x << " " << s.y << "\n";
	}

	return 0;
}