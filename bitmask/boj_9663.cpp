#include <bits/stdc++.h>

using namespace std;

int N, ret=0;
vector<pair<int,int>> queen;
int visited[15] = {0,};
 

void input(){
	cin >> N;
}

bool queenCheck(int qCnt){
	
	for(int i=0; i<qCnt; i++){
		if(visited[i] == visited[qCnt]) return false; // 이제까지 둔 queen들의 열에서  겹치는지 체크 
		if(qCnt - i == abs(visited[qCnt] - visited[i])) return false; // 대각선에서 겹치는지 체크 
	}
	return true;	
} 

void NQueen(int qCnt){
	if(qCnt == N){
		ret++;
		return;
	}
	
	for(int i=0; i<N; i++){
		visited[qCnt] = i; // qCnt = 행, visited[qCnt]  = 열 
		
		if(queenCheck(qCnt)){
			NQueen(qCnt+1);
		}
	}
	
	return;
}

int main(){
	input();
	NQueen(0);

	cout << ret;
	return 0;
}
