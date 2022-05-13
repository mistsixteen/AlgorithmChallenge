//Backjoon Problem No.16170
//https://www.acmicpc.net/problem/16170
//Mist16, 2022-05-13

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
	time_t curTime = time(0);

	tm* ptm = localtime(&curTime);
	cout << 1900 + ptm->tm_year << "\n";
	cout.width(2);
	cout.fill('0');
	cout << 1 + ptm->tm_mon << "\n";
	cout.width(2);
	cout.fill('0');
	cout << ptm->tm_mday;
	return 0;
}