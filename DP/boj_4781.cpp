#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>

const int MAX = 10004;

using namespace std;

int N;
float K, price;
int DP[MAX];

typedef struct candy {
	int cal;
	int price;
}CANDY;

CANDY cdy;
vector<CANDY> candyBox;

bool sortFlag(CANDY cdy1, CANDY cdy2) {
	if (cdy1.price != cdy2.price) 
		return cdy1.price < cdy2.price;
	else						  
		return cdy1.cal > cdy2.cal;
}

void bottomUp(int budget) {
	for (int price = candyBox[0].price; price <= budget; price++) {
		for (int i = 0; i < N; i++) {
			if (price < candyBox[i].price) break;
			DP[price] = max(DP[price - candyBox[i].price] + candyBox[i].cal, DP[price]);
		}
	}

	return ;
}

void run() {
	while(true){
		cin >> N >> K;
		
		if (N == 0) break;
		int budget = static_cast<int>(K*100 + 0.5);

		memset(DP, 0, sizeof(DP));
		candyBox.clear();

		for (int i = 0; i < N; i++) {
			cin >> cdy.cal >> price;
			
			cdy.price = static_cast<int>(price * 100 + 0.5);
			candyBox.push_back(cdy);
		}

		sort(candyBox.begin(), candyBox.end(), sortFlag);

		bottomUp(budget);

		cout << DP[budget] << "\n";
	}

	return ;
}


int main() {
	run();
	return 0;
}