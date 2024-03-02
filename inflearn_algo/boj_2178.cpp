#include <bits/stdc++.h>

using namespace std;

int N, M;
int visited[104][104] = {0,};
vector<vector<int>> maze;
vector<vector<int>> moveTo = {
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};

void input(){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		vector<int> mrow;
		string data;
		cin >> data;
		
		for(int j=0; j<M; j++){	
			mrow.push_back((int)data.at(j) - '0');
		}
		maze.push_back(mrow);
	}
	return;
}

bool rangeCheck(int y, int x){
	return 0 <= y && y<N && 0<=x && x<M;
}

void BFS(){
	int nowY = 0, nowX = 0;
	queue<vector<int>> walk;

	visited[nowY][nowX] = 1;
	walk.push(vector<int>({nowY, nowX}));
	
	while(!walk.empty()){
		vector<int> now = walk.front();
		int nowY = now.at(0);
		int nowX = now.at(1);
		
		for(int i=0; i < moveTo.size(); i++){
			int nextY = nowY + moveTo.at(i).at(0);
			int nextX = nowX + moveTo.at(i).at(1);	
			
			if(rangeCheck(nextY, nextX) == false) continue;
			if(maze[nextY][nextX] == 0) continue;
			if(visited[nextY][nextX] > 0) continue;
			
			
			visited[nextY][nextX] = visited[nowY][nowX] + 1;
			walk.push(vector<int>({nextY, nextX}));
		}
		
		walk.pop();
	}
	
	return;
}

void output(){
	cout << visited[N-1][M-1] << '\n';
}

void printVisited(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void printMaze(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << maze[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
}

void run(){
	input();
	BFS();
	output();
	//printVisited();
	//printMaze();
}

int main(){
	run();
	return 0;
}
