#include<iostream>
#include<string.h>

#define MAX 1000001
#define INF 10e9

using namespace std;

int N, ret;
int DP[static_cast<int>(MAX)];

void input() {
	cin >> N;
	memset(DP, -1, sizeof(DP));
	return ;
}

void makeDP() {	
	DP[1] = 0;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;

		if (i%2 == 0) {
			DP[i] = min(DP[i], DP[i/2]+1);
		}
		if (i%3 == 0) {
			DP[i] = min(DP[i], DP[i/3]+1);
		}
	}

	return ;
}


void output() {
	int ret = DP[N];

	cout << ret << "\n";
	
	int prev = -1;

	for (int i = N; i >= 1; i--) {
		if (DP[i] == ret && prev == -1) {
			cout << i << " ";
			ret--;
			prev = i;
		}
		else if(DP[i] == ret && ((i == prev/3 && prev % 3 == 0) || (i == prev/2 && prev % 2 == 0) || i == prev-1)) {
			cout << i << " ";
			ret--;
			prev = i;
		}
	}

	return ;
}

void run() {
	input();
	makeDP();
	output();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}