#include<bits/stdc++.h>

using namespace std;

int T, W, ret = 0;
int plum[1001] = { 0, };
int DP[1001][31] = {0,};

void input() {
	cin >> T >> W;
	for (int i = 1; i <= T; i++) {
		cin >> plum[i];
	}
}

void makeDP() {
	for (int t = 1; t <= T; t++) {
		for (int w = 0; w <= W; w++) {
			if (DP[t][w] == 0) {
				if (w > 0) DP[t][w] = max(DP[t - 1][w], DP[t][w - 1]);
				else       DP[t][w] = DP[t - 1][w];
			}

			if ((w % 2) + 1== plum[t]) {
				DP[t][w] = max(DP[t][w], DP[t - 1][w] + 1);
			}
			else if(w+1 <= W){
				DP[t][w + 1] = max(DP[t][w+1], DP[t-1][w] + 1);
			}
		}
	}

	for (int w = 0; w <= W; w++) {
		ret = max(ret, DP[T][w]);
	}
}

void output() {
	cout << ret;
}

void run() {
	input();
	makeDP();
	output();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	run();
	return 0;
}