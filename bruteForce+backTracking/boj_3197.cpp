#include<bits/stdc++.h>

using namespace std;

int R,C, ret = 0;

pair<int,int> swan;

queue<pair<int,int>> swim;
queue<pair<int,int>> nextSwim;
queue<pair<int,int>> water;
queue<pair<int,int>> nextWater;
//vector<pair<int,int>> melted;

vector<pair<int,int>> moveTo = {
	{1,0}, {0,1},
	{-1,0}, {0,-1}
};


char Map[1504][1504];
int visited[1504][1504] = {0,};
int visitedSwan[1504][1504] = {0,};


bool rangeCheck(int y, int x){
	return 0<=y && y<R && 0<=x && x<C;
}

void QClear(queue<pair<int, int>>& que){
	queue<pair<int,int>> empty;
	swap(que, empty);
}

void input(){
	cin >> R >> C;
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> Map[i][j];
		
			if(Map[i][j] == '.' || Map[i][j] == 'L'){
				visited[i][j] = 1;
				water.push({i,j});
				
				if(Map[i][j] == 'L') swan = make_pair(i,j);
			}
		}
	}
	
	swim.push(swan);
	visitedSwan[swan.first][swan.second] = 1;
}

void melting(){
	pair<int,int> now;
	while(!water.empty()){
		now = water.front();
		water.pop();
		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = now.first  + moveTo.at(i).first;
			int nextX = now.second + moveTo.at(i).second;
			
			if(!rangeCheck(nextY, nextX)) continue;
			if(visited[nextY][nextX]) continue;
			
			if(Map[nextY][nextX] == 'X'){
				visited[nextY][nextX] = 1;
				nextWater.push({nextY, nextX});
				Map[nextY][nextX] = '.';
			}
		}
	}
}

bool moveSwan(){
	pair<int,int> now;
	while(!swim.empty()){
		now = swim.front();
		swim.pop();
			
		for(int i=0; i<moveTo.size(); i++){
			int nextY = now.first  + moveTo.at(i).first;
			int nextX = now.second + moveTo.at(i).second;
				
			if(!rangeCheck(nextY,nextX)) continue;
			if(visitedSwan[nextY][nextX]) continue;

			visitedSwan[nextY][nextX] = 1;
				
			if(Map[nextY][nextX] == 'X') 	  nextSwim.push({nextY, nextX});
			else if(Map[nextY][nextX] == '.') swim.push({nextY,nextX});
			else if(Map[nextY][nextX] == 'L') return true;
		}
			
	}
	return false;
}




void run(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	input();
	
	while(true){
		if(moveSwan()) break;
		melting();
		water = nextWater;
		swim = nextSwim;
		QClear(nextSwim);
		QClear(nextWater);
		ret++;
	}
	
	cout << ret;
		
	return;
}


int main(){

	run();
		
	return 0;
} 
