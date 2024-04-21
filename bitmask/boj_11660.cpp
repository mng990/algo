#include<bits/stdc++.h>

using namespace std;

int N, M;
int Map[1025][1025];
int DP[1025][1025] = {0,};
vector<pair<int,int>> range;

void input(){
	cin >> N >> M;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> Map[j][i];
		}
	}
	
	for(int i=0; i<M; i++){
		int y1, x1;
		int y2, x2;
		
		cin >> x1 >> y1 >> x2 >> y2;
		range.push_back({y1, x1});
		range.push_back({y2, x2});
	} 
}

void makeDP(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			DP[i][j] += DP[i-1][j] + DP[i][j-1];
			DP[i][j] -= DP[i-1][j-1]; // 공통된 부분 차감		
			
			DP[i][j] += Map[i][j];
		}
	}
}

void printDP(){
	cout << '\n';
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			cout<< DP[i][j] << ' ';
		}
		
		cout << '\n';
	}
}

int getSum(pair<int,int> r1, pair<int,int> r2){
	int y1 = r1.first, x1 = r1.second;
	int y2 = r2.first, x2 = r2.second;

	return DP[y2][x2] -(DP[y1-1][x2] + DP[y2][x1-1] - DP[y1-1][x1-1]);
}

void printAns(){
	for(int i=0; i<range.size(); i+=2){
		
		cout << getSum(range[i], range[i+1]) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	input();
	makeDP();
	printAns();
	//printDP();
	return 0;
}
