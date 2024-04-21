#include<bits/stdc++.h>

using namespace std;

// W = 1, N = 10, E = 100, S = 1000, 

int N, M, vst = 1, maxRoom = 0, extend = 0;


int dir[4] = {1, 2, 4, 8};
int Map[54][54] = {0,};
int visited[54][54] = {0,};
vector<int> space;

vector<pair<int,int>> moveTo = {
	{0,-1}, {-1,0},
	{0, 1}, {1, 0}
};


bool rangeCheck(int y, int x){
	return 0<=y && y<M && 0<=x && x<N;
}

void input(){
	cin >> N >> M;
	
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			cin >> Map[i][j];
}

int DFS(int y, int x){
	int cnt = 1;
		
	for(int i=0; i<4; i++){
		int blockCheck = Map[y][x] | dir[i];
		if(blockCheck == Map[y][x]) continue;
		
		int nextY = y+moveTo[i].first;
		int nextX = x+moveTo[i].second;
		
		if(visited[nextY][nextX]) continue;
		visited[nextY][nextX] = space.size()+1;
		
		
		cnt += DFS(nextY, nextX);
	}
	
	return cnt;
}

void printVisited(){
	for(int i=0; i<M; i++){
		for(int j=0;j<N;j++){
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

void getAns(){
	
	extend = maxRoom;
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			int nowVst, nextVst;
			
			if(i < M - 1){
				nowVst  = visited[i][j]-1;
				nextVst = visited[i+1][j]-1;
			}
			else if(j < N-1){
				nowVst  = visited[i][j]-1;
				nextVst = visited[i][j+1]-1;
			}
			
			
			 
			if(nowVst != nextVst){
				extend = max(extend, space[nowVst]+space[nextVst]);	
			}
		}
	}
}

void output(){
	cout << space.size() << '\n';
	cout << maxRoom << '\n';
	cout << extend << '\n';
}

void printRoom(){
	for(auto room: space){
		cout << room << " ";
	}
	cout << "\n";
}

void travel(){
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j]) continue;
			
			visited[i][j] = space.size()+1;
			
			int room = DFS(i,j);
			space.push_back(room);
			maxRoom = max(room, maxRoom);
		 }
	}
}

int main(){
	input();
	travel();
	getAns();
	output();
	
	return 0;
}
