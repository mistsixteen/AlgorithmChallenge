//Backjoon Problem No.1562
//https://www.acmicpc.net/problem/1562
//Mist16, 2022-03-08

#include <iostream>

using namespace std;

unsigned int answerBitmask = 0b1111111111;

unsigned long answerBoard[1024][101][10] = { 0, };

void initialize()
{
	for (int i = 0; i <= 9; i++)
	{
		answerBoard[answerBitmask][0][i] = 1;
	}
}


unsigned long run(int lastDigit, int idx, unsigned int cBitMask)
{
	unsigned long answer = 0;
	if (answerBoard[cBitMask][idx][lastDigit] != 0)
		return answerBoard[cBitMask][idx][lastDigit];
	if (idx == 0)
		return 0;
	//+1
	if (lastDigit < 9)
	{
		answer += run(lastDigit + 1, idx - 1, cBitMask | (1 << (lastDigit + 1)));
	}
	//-1
	if (lastDigit > 0)
	{
		answer += run(lastDigit - 1, idx - 1, cBitMask | (1 << (lastDigit - 1)));
	}	
	answer = answer % 1000000000;
	answerBoard[cBitMask][idx][lastDigit] = answer;
	return answer;
}

int main()
{
	unsigned long long tAnswer = 0;
	unsigned long answer = 0;
	int N;
	cin >> N;

	initialize();

	for (int i = 1; i <= 9; i++)
	{
		answer += run(i, N - 1, (1 << i));
		answer = answer % 1000000000;
	}
	

	cout << answer;


	return 0;
}