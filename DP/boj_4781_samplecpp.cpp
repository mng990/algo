#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>

const int MAX = 10004;

using namespace std;

int N, frontK, rearK;
int DP[MAX];

void run() {

	while(true){
		scanf("%d %d.%d", &N, &frontK, &rearK);

		if (N == 0) break;

		int budget = frontK*100 + rearK;

		memset(DP, 0, sizeof(DP));

		for (int i = 0; i < N; i++) {
			int cal, frontPrice, rearPrice, price;
			scanf("%d %d.%d", &cal, &frontPrice, &rearPrice);

			price = frontPrice*100 + rearPrice;

			for (int p = price; p <= budget; p++) {
				DP[p] = max(DP[p], DP[p - price] + cal);
			}
		}

		printf("%d\n", DP[budget]);
	}

	return ;
}



int main() {
	run();
	return 0;
}