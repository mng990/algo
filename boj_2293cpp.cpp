#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>

const int INF = 10e7;
const int MAX = 10001;

using namespace std;

int N, K;
int DP[MAX] = { 0, };
vector<int> coins;

void input() {
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	DP[0] = 1;
	sort(coins.begin(), coins.end());
	return ;
}

void bottomUp() {
	for (int i = 0; i < N; i++) {
		for (int cost = coins[i]; cost <= K; cost++) {
			DP[cost] += DP[cost - coins[i]];
		}
	}

	return ;
}


void output() {
	cout << DP[K];
	
	return ;
}

void run() {
	input();
	bottomUp();
	output();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}