#include <bits/stdc++.h>

using namespace std;

int T, N, M, K;
vector<int> result;
vector<vector<int>> farm;
vector<vector<int>> moveTo = {
	{ 1, 0}, {0,  1},
	{-1, 0}, {0, -1}
};
int visited[54][54];


void init(int row, int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			visited[i][j] = 0;
			farm[i][j] = 0;
		}
	}
	return;
}

bool rangeCheck(int y, int x, int row, int col){
	return 0<=y && y<row && 0<=x && x<col;
}

int earthworm(int nowY, int nowX, int row, int col){
	queue<vector<int>> ewPath;
	
	int cnt = 0;
	
	if(!farm[nowY][nowX] || visited[nowY][nowX]) return cnt;
	
	visited[nowY][nowX] = 1;
	cnt += farm[nowY][nowX];
	
	ewPath.push(vector<int>({nowY, nowX}));

	
	while(!ewPath.empty()){
		vector<int> now = ewPath.front();
		int nowY = now.at(0), nowX = now.at(1);
		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = nowY + moveTo.at(i).at(0);
			int nextX = nowX + moveTo.at(i).at(1);
			
			if(!rangeCheck(nextY, nowX, row, col)) continue;
			if(visited[nextY][nextX]) continue;
			if(!farm[nextY][nextX]) continue;
			
			ewPath.push(vector<int>({nextY, nextX}));
			visited[nextY][nextX] = true;
			cnt += farm[nextY][nextX];
		}
		ewPath.pop();
	}
	
	return cnt;
}



int farming(int row, int col){
	int rst = 0;	
		
	for(int i=0; i<farm.size(); i++){
		for(int j=0; j<farm[i].size(); j++){
			if(!farm[i][j] && visited[i][j]) continue;
				
			if(earthworm(i, j, row, col)) rst++;
			}
	}
	return rst;
}

void run(){
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> M >> N >> K;
		int row = N, col = M;
		
		farm = vector<vector<int>>(row, vector<int>(col));
		
		init(row, col);

		for(int i=0; i<K; i++){
			int y, x;
			cin >> x >> y;
			farm[y][x] = 1;			
		}
		
		cout << farming(row, col) << endl;
		
		farm.clear();
	}
	
	return; 
}


int main(){
	run();
	return 0;
}
