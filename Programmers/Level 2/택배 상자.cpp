//Programmers Level 2. 택배 상자
//https://school.programmers.co.kr/learn/courses/30/lessons/131704
//Mist16, 2022-11-27

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	stack<int> sideBelt;

	for (int i = 1; i <= order.size(); i++) {
		if (i == order[answer]) {
			answer++;

			while (true) {
				if (!sideBelt.empty() && sideBelt.top() == order[answer]) {
					answer++;
					sideBelt.pop();
				}
				else
					break;
			}
		}
		else
			sideBelt.push(i);
	}

	while (true) {
		if (!sideBelt.empty() && sideBelt.top() == order[answer]) {
			answer++;
			sideBelt.pop();
		}
		else
			break;
	}
	return answer;
}

int main()
{
	vector<int> score = {5, 4, 3, 2, 1};

	cout << solution(score);
	return 0;
}

