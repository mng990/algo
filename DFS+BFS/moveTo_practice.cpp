#include<bits/stdc++.h>
#define N 3

using namespace std;

vector<vector<int>> Map;

int visited[N][N] = {0,};
vector<vector<int>> moveTo = {
						{1, 0}, {-1,0}, 
						{0, 1}, {0,-1},
						}; // +dy, -dy, +dx, -dx

void input(){
	for(int i=0; i<N; i++){
		vector<int> mrow;
		for(int j=0; j<N; j++){
			int data;
			cin >> data;
			mrow.push_back(data);
		}
		
		Map.push_back(mrow);
	}
	
	return ;
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

void BFS(int startY, int startX){
	queue<pair<int, int>> walk;
	
	int startDot = Map.at(startY).at(startX);
	
	cout << startY << " " << startX << '\n';
	visited[startY][startX] = true;
	
	for(int i=0; i<moveTo.size(); i++){
			int nextY = startY + moveTo.at(i).at(0);
			int nextX = startX + moveTo.at(i).at(1);
			
			if(visited[nextY][nextX] || !rangeCheck(nextY, nextX)) continue;
			
			int nextDot = Map.at(nextY).at(nextY);
			
			if(nextDot == 0) continue;

			visited[nextY][nextX] = true;
			walk.push(pair<int,int>(nextY, nextX));
	}
			
	
	while(!walk.empty()){
		pair<int, int> now = walk.front();
		int nowY = now.first;
		int nowX = now.second;
		
		cout << nowY << " " << nowX << '\n';

		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = nowY + moveTo.at(i).at(0);
			int nextX = nowX + moveTo.at(i).at(1);
			
			if(visited[nextY][nextX] || !rangeCheck(nextY, nextX)) continue;
			
			int nextDot = Map.at(nextY).at(nextY);

			if(nextDot == 0) continue;
			
			visited[nextY][nextX] = true;
			walk.push(pair<int,int>(nextY, nextX));
		}
		
		walk.pop();
	}
	
	
	return ;
}

void DFS(int nowY, int nowX){	
	cout << nowY << " " << nowX << '\n';
	visited[nowY][nowX] = true;
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = nowY + moveTo.at(i).at(0);
		int nextX = nowX + moveTo.at(i).at(1);
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(Map.at(nextY).at(nextY) == 0) continue;
		if(visited[nextY][nextX]) continue;
		
		DFS(nextY, nextX);
	}
	
	return;
}

int main(){
	input();
	DFS(0, 0);
	return 0;
}
