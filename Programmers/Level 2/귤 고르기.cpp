//Programmers Level 2. 귤 고르기
//https://school.programmers.co.kr/learn/courses/30/lessons/138476
//Mist16, 2022-05-24

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	//tangerine 배열의 최소/최대값을 체크한 후, 배열 사이즈를 지정해주는 방법으로 메모리 크기 감쇠가능.
	//지금은 속도에 더 중점을 주고 싶으니 이대로 진행하자.
	int tangerineCount[100000] = { 0, };
	multiset<int> tangerineBox;

	for (auto i : tangerine)
	{
		tangerineCount[i]++;
	}

	for (auto i : tangerineCount) {
		if (i > 0) {
			tangerineBox.insert(i);
		}
	}
	for (auto i = tangerineBox.rbegin(); i != tangerineBox.rend(); i++) {
		if (*i >= k)
			return answer + 1;
		k = k - *i;
		answer++;
	}
	return answer;
}

int main()
{
	vector<int> tangerine = { 1, 3, 2, 5, 4, 5, 2, 3 };

	cout << solution(6, tangerine);
	return 0;
}

