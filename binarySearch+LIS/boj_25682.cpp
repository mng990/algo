#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char board[2001][2001] = {0,};
int pSum[2001][2001] = {0,};

void input(){
	cin >> N >> M >> K;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> board[i][j];
		}
	}
}

int chess(char color){
	int value, tmp, result = 100000000;
	
	memset(pSum, 0, sizeof(pSum));
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(!((i+j)%2)) value = board[i][j] != color;  
			else value = board[i][j] == color; 
						
			pSum[i+1][j+1] = pSum[i][j+1] + pSum[i+1][j] - pSum[i][j] + value;		
		}	
	}
		
	for(int i=0; i<=N-K; i++){
		for(int j=0; j<=M - K; j++){
			tmp = pSum[i+K][j+K] - pSum[i][j+K] - pSum[i+K][j] + pSum[i][j];
			result = (tmp < result) ? tmp : result;
		}
	}
	
	return result;
}

void run(){
	input();
	cout << min(chess('B'), chess('W')) << "\n";
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	run();
	return 0;
}
