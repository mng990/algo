#include <bits/stdc++.h>

using namespace std;

int N, K, maxTemp = INT_MIN;
int DP[100001] = {0, };

void input(){
	cin >> N >> K;
	
	for(int i=1; i<=N; i++){
		int data; 
		cin >> data;
		
		DP[i] = DP[i-1] + data;
	}
	
	return;
}

void getMaxTemp(){
	for(int i=0; i<=N-K; i++){
		maxTemp = max(maxTemp, DP[i+K] - DP[i]);
	}
	
	return;
}

void output(){
	cout << maxTemp;
	return;
}

void run(){
	input();
	getMaxTemp();
	output();
}

int main(){
	
	run();
		
	return 0;
}
