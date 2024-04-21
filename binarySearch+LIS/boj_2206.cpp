#include <bits/stdc++.h>

using namespace std;

int N, M, ret = INT_MAX;
int Map[1004][1004] = {0,};
int visited[1004][1004][2] = {0,};
int dist[1004][1004] = {0,};

vector<pair<int,int>> moveTo = {
	{0, 1}, { 1,0},
	{0,-1}, {-1,0}
};


typedef struct dot{
	int y;
	int x;
	int wall;
	
	int operator[](int idx){
		return *(&y + idx);
	}
}spot;


void input(){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		string row;
		cin >> row;
		
		for(int j=0; j<row.size(); j++){
			Map[i][j] = row[j]-'0';
		}
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<M;
}

bool goal(int y, int x){
	return y == N-1 && x == M-1;
}

void printVisited(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


int BFS(){
	queue<spot> path;
	
	int startY = 0, startX = 0;
	visited[startY][startX][0] = 1;
	visited[startY][startX][1] = 1;
	dist[startY][startX] = 1;
	
	if(goal(startY, startX)){
		return dist[startY][startX];
	}
	
	path.push({startY, startX, 0});
		
	while(!path.empty()){
		spot now = path.front();
		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = now[0]  + moveTo[i].first;
			int nextX = now[1] + moveTo[i].second;
			int wall = now[2];
			
			if(!rangeCheck(nextY,nextX)) continue;
			if(Map[nextY][nextX] == 1 && wall == 0 && !visited[nextY][nextX][wall+1]){
				visited[nextY][nextX][wall+1] = true;
				dist[nextY][nextX] = dist[now[0]][now[1]] + 1;
				path.push({nextY,nextX, wall+1});
			}
			if(Map[nextY][nextX] == 0 && !visited[nextY][nextX][wall]){
				visited[nextY][nextX][wall] = true;
				dist[nextY][nextX] = dist[now[0]][now[1]] + 1;
				path.push({nextY,nextX, wall});
			}
			
			if(goal(nextY, nextX)){
				return dist[nextY][nextX];
			}
						
		}
		
		
		path.pop();
	}
	
	return -1;
}

void output(){
	if(ret == INT_MAX) ret = -1;
	
	cout << ret;
}




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	input();
	cout << BFS();
	
	return 0;
}
