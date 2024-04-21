#include<bits/stdc++.h>

using namespace std;

int N, K, ret =0 ;
int DP[104][100004];
vector<pair<int,int>> item;


void input(){
	cin >> N >> K;
	
	item.push_back({0,0});
	
	for(int i=1; i<=N; i++){
		int weight, val;
		cin >> weight >> val;
		item.push_back({weight, val});
	}
}

void makeDP(){
	for(int i=1; i<=N; i++){
		int nowW = item[i].first;
		int nowV = item[i].second;
		
		for(int j=1; j <= K; j++){
			DP[i][j] = max(DP[i-1][j], DP[i][j]);
		
			if(j >= nowW){
				DP[i][j] = max(DP[i-1][j-nowW] + nowV, DP[i][j]);
			}
		}
	}
}

void printDP(){
	cout << "\n";
	for(int i=0; i<=N; i++){
		for(int j=0; j<=K; j++){
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
}

int getAns(){
	
	for(int i=1; i<=N; i++){
		ret = max(ret, DP[i][K]);
	} 
	
	return ret;
}

void output(){
	cout << ret;
}

int main(){
	input();
	makeDP();
	getAns();
	output();
	//printDP();
	return 0;
}
