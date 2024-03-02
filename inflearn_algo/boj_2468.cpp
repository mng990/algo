#include<bits/stdc++.h>

using namespace std;

int N, maxHeight = INT_MIN, ans = 1, rainfall;
int Map[104][104];
int visited[104][104];
vector<vector<int>> moveTo = {
	{1,0}, {-1,0},
	{0,1}, {0,-1}
};

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int height;
			cin >> height;
			maxHeight = max(maxHeight, height);
			Map[i][j] = height;
		}
	}
	return;
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

void init(){
	fill(&visited[0][0], &visited[0][0] + 104*104, 0);
}

void safeZone(int y, int x){
	visited[y][x] = 1;
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = y + moveTo.at(i).at(0);
		int nextX = x + moveTo.at(i).at(1);
		
		if(!rangeCheck(nextY,nextX)) continue;
		if(visited[nextY][nextX]) continue;
		if(Map[nextY][nextX] <= rainfall) continue;
		
		safeZone(nextY, nextX);
	}
	
	return;
}

void rainDrop(){
	for(int r=1; r<maxHeight; r++){
		init();
		int cnt = 0;

		rainfall = r;
		
		for(int i =0; i<N; i++){
			for(int j=0; j<N; j++){
				if(Map[i][j] > rainfall && !visited[i][j]){
					safeZone(i,j);
					cnt++;
				}
			}
		}
		
		ans = max(ans, cnt);
	}
}



void output(){
	cout << ans << '\n';
}

void run(){
	input();
	rainDrop();
	output();
}


int main(){
	run();
	return 0;
}


