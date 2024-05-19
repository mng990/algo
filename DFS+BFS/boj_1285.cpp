#include<iostream>
#include<bitset>


using namespace std;

int N, ret = 0, t = 0;

int coin[20];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char side;
			cin >> side;
			if (side == 'T') {
				coin[i] |= (1 << j);
				ret++;
			}
		}
	}

}

void printCoin() {
	cout << "time: " << t << endl;
	for (int i = 0; i < N; i++) {
		cout << bitset<3>(coin[i]) << endl;
	}
	cout << endl;
}

void updateCnt() {
	int cnt = 0;
	for (int j = 0; j < N; j++) {
		int colCnt = 0;
		for (int i = 0; i < N; i++) {
			if (coin[i] & 1 << j) colCnt++;
		}
		cnt += min(colCnt, N - colCnt);
	}

	ret = min(ret, cnt);

	return;
}

void flipRow(int idx) {
	coin[idx] = ~coin[idx];
	updateCnt();
}

void flip() {

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if (i & (1 << j))	flipRow(j);
		}
	}
}

void run() {
	input();
	flip();
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	run();
	return 0;
}