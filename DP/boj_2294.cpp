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
	
	fill(DP, DP+MAX, INF);
	sort(coins.begin(), coins.end());
	
	DP[0] = 0;
	
	return ;
}

void bottomUp() {
	for (int cost = coins[0]; cost <= K; cost++) {	
		for (int i = 0; i < N; i++) {
			if (cost < coins[i]) break;
			if (DP[cost - coins[i]] == INF) continue;

			DP[cost] = min(DP[cost-coins[i]] + 1, DP[cost]);
		}
	}

	return ;
}


void output() {
	if (DP[K] == INF) cout << -1;
	else			cout << DP[K];
	
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