#include<bits/stdc++.h>

using namespace std;

int T, W, ret = 0;
int plum[1001] = { 0, };
int DP[1001][31] = {0,};

int DP_TD[1001][2][31];

void input() {
	cin >> T >> W;
	for (int i = 0; i < T; i++) {
		cin >> plum[i];
	}

	memset(DP_TD, -1, sizeof(DP_TD));
}

int dfs(int idx, int tree, int cnt) {
	if (cnt < 0) return -1e9;
	if (idx == T) return 0;
	int& ret = DP_TD[idx][tree][cnt];
	if(~ret) return ret;
	return ret = max(dfs(idx+1, tree^1, cnt-1), dfs(idx+1, tree, cnt)) + (tree == plum[idx]-1);
}

void makeDP() {
	for (int t = 1; t <= T; t++) {
		for (int w = 0; w <= W; w++) {
			if (DP[t][w] == 0) {
				if (w > 0) DP[t][w] = max(DP[t - 1][w], DP[t][w - 1]);
				else       DP[t][w] = DP[t - 1][w];
			}

			if ((w % 2) + 1== plum[t-1]) {
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

void BottomUp() {
	input();
	makeDP();
	output();
}

void TopDown() {
	input();
	cout << max(dfs(0,1,W-1), dfs(0,0,W));
}

void printDPTD() {
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k <= W; k++) {
				cout << DP[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	TopDown();
	//printDPTD();
	return 0;
}