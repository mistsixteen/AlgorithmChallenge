//Backjoon Problem No.1202
//Mist16, 2022-01-21

#include <iostream>
#include <list>
#include <set>
using namespace std;

struct Jewel
{
	int weight;
	int price;
	Jewel(int wei, int pri) : weight(wei), price(pri) {}

	//정렬시 price 기준으로 소트되도록 설정
	bool operator<(const Jewel s) const
	{
		return this->price > s.price;
	}
};

list<Jewel> jewels;
multiset<int> Bags;

int N, K;

int main()
{
	int tempWeight, tempValue;
	long long int totalPrice = 0;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> tempWeight >> tempValue;
		jewels.push_back(Jewel(tempWeight, tempValue));
	}
	for (int i = 0; i < K; i++)
	{
		cin >> tempWeight;
		Bags.insert(tempWeight);
	}
	jewels.sort();

	//가장 비싼 보석부터, 들어갈 수 있는 가장 작은 가방을 사용
	for (auto iter1 = jewels.begin(); iter1 != jewels.end(); iter1++)
	{
		auto iter2 = Bags.lower_bound(iter1->weight);
		if (iter2 != Bags.end())
		{
			totalPrice += iter1->price;
			Bags.erase(iter2);
			//모든 가방을 사용할경우 종료
			if (Bags.size() == 0)
			{
				cout << totalPrice;
				return 0;
			}
		}
	}
	cout << totalPrice;
	return 0;
}