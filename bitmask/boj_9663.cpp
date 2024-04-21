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
		if(visited[i] == visited[qCnt]) return false; // �������� �� queen���� ������  ��ġ���� üũ 
		if(qCnt - i == abs(visited[qCnt] - visited[i])) return false; // �밢������ ��ġ���� üũ 
	}
	return true;	
} 

void NQueen(int qCnt){
	if(qCnt == N){
		ret++;
		return;
	}
	
	for(int i=0; i<N; i++){
		visited[qCnt] = i; // qCnt = ��, visited[qCnt]  = �� 
		
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
