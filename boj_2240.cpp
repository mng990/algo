#include<bits/stdc++.h>

using namespace std;

int T, W, ret = 0;
int plum[1001] = {0,};
int DP[31][1001] = {0,};

void input(){
	cin >> T >> W;
	for(int i=1; i<=T; i++){
		cin >> plum[i];
	}
}

void makeDP(){
	for(int i=1; i<=T; i++){
		for(int j=0; j<=W; j++){
			int now = j%2 + 1;
			
			if(now == plum[i]){
				DP[j][i] = max(DP[j][i], DP[j][i-1]+1);
			}
			else{
				DP[j][i] = max(DP[j][i], DP[j][i-1]);
				
				if(j+1 <= W){
					DP[j+1][i] = max(DP[j+1][i], DP[j][i-1] + 1);
				}
			}
		}
	}
}

void printDP(){
	for(int i=0; i<=W; i++){
		for(int j=1; j <= T; j++){
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
}

void getRet(){
	for(int i=0; i<=W; i++){
		ret = max(ret, DP[i][T]);
	}
}

void output(){
	cout << ret << "\n";
}

void run(){
	input();
	makeDP();
	getRet();
	output();
}

int main(){
	run();
	return 0;
}
