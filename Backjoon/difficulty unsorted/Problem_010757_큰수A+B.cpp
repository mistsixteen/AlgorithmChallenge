//Backjoon Problem No.10757
//https://www.acmicpc.net/problem/10757
//Mist16, 2022-03-27

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	string inputA, inputB;
	int idx = 0;
	int size = 0;

	short a[10010] = { 0, };
	short b[10010] = { 0, };
	list<char> result;

	cin >> inputA >> inputB;
	idx = 10010 - inputA.size();

	for (char c : inputA)
	{
		a[idx++] = (int)(c - '0');
	}

	idx = 10010 - inputB.size();

	for (char c : inputB)
	{
		b[idx++] = (int)(c - '0');
	}
	short next = 0;
	for (int i = 10009; i >= 0; i--)
	{
		short temp = a[i] + b[i] + next;
		next = temp / 10;
		char tempc = (temp % 10) + '0';
		result.push_front(tempc);
	}
	bool flag = false;
	for (char c : result)
	{
		if (flag == false && c != '0')
			flag = true;
		if(flag)
			cout << c;
	}
	
	return 0;
}