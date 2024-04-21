#include <bits/stdc++.h>

using namespace std;

int N, M, ans = 0;
vector<vector<int>> Map;
vector<vector<int>> moveTo = {
	{1, 0}, {0, 1},
	{-1,0}, {0,-1}
};
int visited[101][101];

void input(){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		vector<int> mrow;
		for(int j=0; j<M; j++){
			int land;
			cin >> land;
			mrow.push_back(land);
		}
		Map.push_back(mrow);
	}
}

bool rangeCheck(int y, int x){
	return 0 <= y && y < N && 0 <= x && x< M;
}

int DFS(int startY, int startX, int size){
	int now = Map.at(startY).at(startX);
	if(Map.at(startY).at(startX) == 0 || visited[startY][startX]) return size;

	visited[startY][startX] = 1;
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = startY + moveTo.at(i).at(0);
		int nextX = startX + moveTo.at(i).at(1);
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(visited[nextY][nextX]) continue;
		if(Map.at(startY).at(startX) == 0) continue;
		
		size = DFS(nextY, nextX, size+1);
	}
	
	return size;	
}

void dfs1(int here){
	visited[here] = 1;
	for(int there: adj[here]){
		if(visited[there]) continue;
		dfs1(there);
	}
	return;
} // 호출 전 방문 체크 

void dfs2(int here){
	if(visited[here]) return;
	visited[here] = 1;	
	for(int there: adj[here]){
		dfs2(there);
	}
} // 무작정 호출 후 방문 체크 

void surf(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			int nowSize = DFS(i, j, 0);
			if(nowSize > 0) ans++;
		}
	}
}

void output(){
	cout << ans;
}

void run(){
	input();
	surf();
	output();
}

int main(){
	run();	
	return 0;
}
