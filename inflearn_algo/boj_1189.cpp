#include<bits/stdc++.h>

using namespace std;

char Map[9][9];
int visited[9][9] = {0,};
int R, C, K, ret = 0;

pair<int,int> block;

vector<pair<int,int>> moveTo = {
	{0, 1}, { 1,0},
	{0,-1}, {-1,0}
};

void input(){
	cin >> R >> C >> K;
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> Map[i][j];
		}
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<R && 0<=x && x<C; 
}

bool homeCheck(int y, int x){
	return y == 0 && x == C-1;
}

void printVisited(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void DFS(int nowY, int nowX){
	for(int i=0; i<moveTo.size(); i++){
		int nextY = nowY + moveTo.at(i).first;
		int nextX = nowX + moveTo.at(i).second;
		
		if(!rangeCheck(nextY,nextX)) continue;
		if(Map[nextY][nextX] == 'T') continue;
		if(visited[nextY][nextX]) continue;
		
		visited[nextY][nextX] = visited[nowY][nowX]+1;
		if(homeCheck(nextY,nextX) && visited[nextY][nextX] == K) ret++;
		DFS(nextY, nextX);
		visited[nextY][nextX] = 0;	
	}
	
	return;
}

int main(){
	input();
	visited[R-1][0] = 1;
	DFS(R-1,0);
	cout << ret;
	return 0;
}
