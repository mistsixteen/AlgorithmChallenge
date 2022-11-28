//Programmers Level 2. 혼자 놀기의 달인
//https://school.programmers.co.kr/learn/courses/30/lessons/131130
//Mist16, 2022-11-28

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> cards) {
	int answer = 0;
	int firstBox = 0, secondBox = 0;

	for (int idx = 0; idx < cards.size(); idx++)
	{
		if (cards[idx] == 0)
			continue;
		int nextTarget = idx;
		int boxSize = 0;

		while (cards[nextTarget] != 0) {
			int temp = cards[nextTarget] - 1;
			cards[nextTarget] = 0;
			nextTarget = temp;
			boxSize++;
		}
		if (boxSize > firstBox) {
			secondBox = firstBox;
			firstBox = boxSize;
		}
		else if (boxSize > secondBox) {
			secondBox = boxSize;
		}
	}
	answer = firstBox * secondBox;
	return answer;
}

int main()
{
	vector<int> score = { 8, 6, 3, 7, 2, 5, 1, 4 };

	cout << solution(score);
	return 0;
}

