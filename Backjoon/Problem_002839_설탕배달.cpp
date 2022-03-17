//Backjoon Problem No.2839
//https://www.acmicpc.net/problem/2839
//Mist16, 2022-03-17

#include <iostream>

using namespace std;

int main()
{
	int Kilograms;
	int totalBoxes = -1;
	int boxOf5Kilo;

	cin >> Kilograms;

	boxOf5Kilo = Kilograms / 5;

	for (int i = boxOf5Kilo; i >= 0; i--)
	{
		if ((Kilograms - i * 5) % 3 == 0)
		{
			totalBoxes = i + ((Kilograms - i * 5) / 3);
			break;
		}
	}
	cout << totalBoxes;


	return 0;
}