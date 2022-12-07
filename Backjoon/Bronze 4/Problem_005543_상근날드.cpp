//Backjoon Problem No.5543
//https://www.acmicpc.net/problem/5543
//Mist16, 2022-05-17

#include <iostream>

using namespace std;

int main()
{
	int burger = 2000;
	int drink = 2000;
	int temp = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		if (burger > temp)
			burger = temp;
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> temp;
		if (drink > temp)
			drink = temp;
	}

	cout << (burger + drink - 50);

	return 0;
}