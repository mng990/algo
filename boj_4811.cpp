#include<bits/stdc++.h>

using namespace std;

int N;
typedef long long ll;
ll DP[62][31];


ll dfs(int h, int w) {
	if (h < 0) return 0;
	if (w == 0) return 1;

	ll& ret = DP[h][w];
	if (~ret) return ret;
	return ret = dfs(h - 1, w) + dfs(h + 1, w - 1);
}

void run() {
	memset(DP, -1, sizeof(DP));
	
	while (true) {
		cin >> N;
		if (N == 0) break;
		cout << dfs(0, N) << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	run();
	return 0;
}