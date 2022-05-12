//Backjoon Problem No.17103
//https://www.acmicpc.net/problem/17103
//Mist16, 2022-05-02

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char arr[16] = { 0, };
int isV[16] = { 0, };
int L = 0;
int C = 0;

void run(vector<int> vect, int idx, int v)
{
	if(vect.size() == L)
	{
		if (v >= 1 && L - v >= 2)
		{
			for (char c : vect)
				cout << c;
			cout << "\n";
		}
		return;
	}
	if (idx >= C)
		return;

	vect.push_back(arr[idx]);
	if (isV[idx] == 1)
		run(vect, idx + 1, v + 1);
	else
		run(vect, idx + 1, v);
	vect.pop_back();
	run(vect, idx + 1, v);

}

int main()
{
	vector<int> blankVector;
	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort(&arr[0], &arr[C]);

	for (int i = 0; i < C; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
		{
			isV[i] = 1;
		}
	}
	run(blankVector, 0, 0);
	return 0;
}