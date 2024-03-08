#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> land;
vector<pair<int,int>> treasure;

vector<vector<int>> moveTo = {
	{0,1}, {0,-1},
	{1,0}, {-1,0}
};

char Map[54][54];
int visited[54][54]= {0,};

int row, col, maxDist = 0;

bool rangeCheck(int y, int x){
	return 0<=y && y<row && 0<=x && x<col;
}

void input(){
	cin >> row >> col;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin >> Map[i][j];
			
			if(Map[i][j] == 'L'){
				land.push_back(make_pair(i, j));
			}
		}
	}
}

void printVisited(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col;j++){
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int updateMaxDist(pair<int,int> now){
	int ret = INT_MIN;
	
	memset(visited, 0, sizeof(visited));
	queue<pair<int,int>> quePath;
	quePath.push(now);
	visited[now.first][now.second] = 1;
	
	
	while(!quePath.empty()){
		pair<int,int> now = quePath.front();
		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = now.first + moveTo.at(i).at(0);
			int nextX = now.second + moveTo.at(i).at(1);
			
			if(!rangeCheck(nextY, nextX)) continue;
			if(Map[nextY][nextX] == 'W') continue;
			if(visited[nextY][nextX] > 0) continue;
			
			visited[nextY][nextX] = visited[now.first][now.second] + 1;
			maxDist = max(maxDist, visited[nextY][nextX]-1);
			quePath.push(make_pair(nextY, nextX));
		}
		
		quePath.pop();
		//visited[now.first][now.second] = 0;
	}
	
	return ret;
}

void output(){
	cout << maxDist;
}

void getMaxDist(){
	for(int i=0; i<land.size(); i++){
		pair<int,int> now = land.at(i);
		updateMaxDist(now);
	}
}

void run(){
	input();
	getMaxDist();
	output();
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
