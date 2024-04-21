#include<bits/stdc++.h>

using namespace std;

int N, M;
int Map[51][51] = { 0, };
int DP[51][51] = { 0, };
int visited[51][51] = { 0, };

vector<pair<int, int>> moveTo = {
	{0, 1},{ 1,0},
	{0,-1},{-1,0}
};

bool rangeCheck(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char data;
			cin >> data;
			if (data != 'H') Map[i][j] = data - '0';
		}
	}
}

int dfs(int nowY, int nowX) {

	if (!rangeCheck(nowY, nowX) || Map[nowY][nowX] == 0) return 0;
	if (visited[nowY][nowX]) {
		cout << -1;
		exit(0);
	}

	int& ret = DP[nowY][nowX];
	if (ret) return ret;

	int offset = Map[nowY][nowX];

	visited[nowY][nowX] = 1;

	for (int i = 0; i < moveTo.size(); i++) {
		int nextY = nowY + offset * moveTo.at(i).first;
		int nextX = nowX + offset * moveTo.at(i).second;

		ret = max(ret, dfs(nextY, nextX) + 1);
	}

	visited[nowY][nowX] = 0;

	return ret;
}

void run() {
	input();
	cout << dfs(0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	run();
	return 0;
}