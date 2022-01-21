//Backjoon Problem No.16566
//Mist16, 2022-01-21
//시간제한 초과로 실패, 추후 재도전 예정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class cardDeck
{
private:
	vector<int> cardSet;

public:

	void setSize(int num)
	{
		cardSet.reserve(num);
	}
	void insertCard(int num)
	{
		cardSet.push_back(num);
	}


	void sortCards()
	{
		sort(cardSet.begin(), cardSet.end());
	}
	void deleteCard(vector<int>::iterator iter)
	{
		cardSet.erase(iter);
	}

	vector<int>::iterator getMinCard()
	{
		auto iter = cardSet.begin();
		return iter;
	}

	vector<int>::iterator getMaxCard()
	{
		auto iter = cardSet.end();
		iter--;
		return iter;
	}

	int popCard(int target)
	{
		vector<int>::iterator popOutCard;
		int outCardNum;
		if (target >= *getMaxCard() || target <= *getMinCard()) //losing hand
		{
			popOutCard = getMinCard();
			outCardNum = *popOutCard;
			deleteCard(popOutCard);
			return outCardNum;
		}
		else
		{
			popOutCard = findCard(target);
			outCardNum = *popOutCard;
			deleteCard(popOutCard);
			return outCardNum;
		}
	}

	vector<int>::iterator findCard(int target)
	{
		auto start = cardSet.begin();
		auto end = cardSet.end() - 1;
		int size = cardSet.size();

		while (1)
		{
			auto middle = start + (size / 2);
			if (size == 1)
			{
				return start;
			}
			size = size - (size / 2);

			if (*middle == target)
			{
				return middle + 1;
			}
			else if (*middle < target)
			{
				start = middle;
				continue;
			}
			else
			{
				end = middle;
				continue;
			}
		}
	}

};

int N, M, K;
cardDeck myDeck;

int main()
{
	int cardNum = 0;

	//입출력 속도 관리용
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	//reserve 함수를 사용하여, 미리 vector의 공간을 확보해둔다
	myDeck.setSize(M);

	for (int i = 0; i < M; i++)
	{
		cin >> cardNum;
		myDeck.insertCard(cardNum + 1);
	}
	myDeck.sortCards();

	for (int i = 0; i < K; i++)
	{
		cin >> cardNum;
		cout << myDeck.popCard(cardNum) << "\n";
	}
}