#include<bits/stdc++.h>

using namespace std;

int N;
typedef long long ll;
ll DP[62][31];

// N = 1 
// 1 -> W (DP[0][1] = 1)
// remain: (1H, 0W) 
// 2 -> WH (DP[1][0] = 1)

// N = 2 (DP[0][2]) 
// 1 -> W
// remain: (1H, 1W) 
// 2 -> WH || WW (DP[1][1] = 2)
// remain: (0H, 1W) || (2H, 0W) -> (DP[0][1] || DP[2][0])
// 3 -> WHW || WWH
// remain: (1H, 0W) || (1H, 0W) -> (DP[1][0] || DP[1][0])
// 4 -> WHWH || WWHH => 2°³ 


// DP[0][2] -> DP[1][1] -> DP[2][0] || DP[0][1]

ll dfs(int h, int w) {
	if (h < 0 || w < 0) return 0;
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