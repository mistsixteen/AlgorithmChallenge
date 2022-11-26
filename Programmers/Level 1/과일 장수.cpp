//Programmers Level 1. 과일 장수
//https://school.programmers.co.kr/learn/courses/30/lessons/135808
//Mist16, 2022-11-27

#include <iostream>
#include <vector>
using namespace std;

//k = max Score
//m = apple Per box
int solution(int k, int m, vector<int> score) {
	int answer = 0;
	int boxScores[10] = { 0, };
	int currentBox = 0;

	for (auto i : score)
	{
		boxScores[i]++;
	}

	for (int i = k; i > 0; i--) {
		currentBox += boxScores[i];
		if (currentBox >= m) {
			answer += (int)(currentBox / m) * i * m;
			currentBox %= m;
		}
	}
	return answer;
}
int main()
{
	vector<int> score = { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 };

	cout << solution(4, 3, score);
	return 0;
}

