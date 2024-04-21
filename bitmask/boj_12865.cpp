#include <bits/stdc++.h>
#define MaxK 100004
#define MaxN 104

using namespace std;


int N, K, ret = 0;
int DP[MaxN][MaxK] = {0,};
vector<pair<int,int>> knapsack;

void input(){
	cin >> N >> K;
	knapsack.push_back({0,0});
	for(int i=0; i<N; i++){
		pair<int,int> item;
		cin >> item.first >> item.second; // 무게, 가치 
		knapsack.push_back(item);
	}
	
}


void makeDP(){
	for(int i=1; i<=N; i++){
		pair<int,int> now = knapsack[i];

		for(int j=1; j<=K; j++){
			int prevW = j - now.first;
			
			if(prevW < 0) DP[i][j] = max(DP[i-1][j], DP[i][j]);
			else DP[i][j] = max(DP[i-1][j], DP[i-1][prevW]+now.second);
		} // 선택한 물건의 수, 무게 
	}
}

void printDP(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=K; j++){
			cout << DP[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void getAns(){
	for(int i=1; i<=N; i++){
		ret = max(ret, DP[i][K]);
	}
}

int main(){
	input();
	makeDP();
	getAns();
	//printDP();
	cout << ret;
	return 0;
}
