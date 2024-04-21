#include<bits/stdc++.h>

using namespace std;

typedef struct dot{
	int data;
	bool merge;
}DOT;


int N, ret = 0;
DOT initMap[24][24];
DOT Map[24][24];

vector<pair<int,int>> moveTo = {
	{ 1,0}, {0, 1},
	{-1,0}, {0,-1}
}; // down, right, up, left

vector<int> vecDir;


bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

void initMerge(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			Map[i][j].merge = false;
		}
	}
}

void merge(int& nowY, int& nowX, int& nextY, int& nextX, int dir){
	if(rangeCheck(nextY, nextX)){
		if(Map[nowY][nowX].data == Map[nextY][nextX].data && 
			!Map[nowY][nowX].merge && !Map[nextY][nextX].merge){
			
			Map[nowY][nowX].data = 0;
			Map[nextY][nextX].data *= 2;
			Map[nextY][nextX].merge = true;
					
			nowY = nextY, nowX = nextX;
			nextY += moveTo[dir].first;
			nextX += moveTo[dir].second;
		}
	}
}

void slide(int& nowY, int& nowX, int& nextY, int& nextX, int dir){
	
	while(rangeCheck(nextY, nextX) && Map[nextY][nextX].data == 0){
		Map[nextY][nextX] = Map[nowY][nowX];
		Map[nowY][nowX].data = 0;
		Map[nowY][nowX].merge = false;
		nowY = nextY, nowX = nextX;
		
		nextY += moveTo[dir].first;
		nextX += moveTo[dir].second;
	}
}

void down(){
	for(int j=0; j<N; j++){
		for(int i=N-1; i>=0; i--){
			if(Map[i][j].data == 0) continue;
			
			int nowY = i, nowX = j;
			int nextY= i+1, nextX = j;
			
			slide(nowY, nowX, nextY, nextX, 0);
			merge(nowY, nowX, nextY, nextX, 0);
			slide(nowY, nowX, nextY, nextX, 0);
		}		
	}
}

void up(){
	for(int j=0; j<N; j++){
		for(int i=0; i<N; i++){
			if(Map[i][j].data == 0) continue;
			
			int nowY = i, nowX = j;
			int nextY= i-1, nextX = j;
			
			slide(nowY, nowX, nextY, nextX, 2);
			merge(nowY, nowX, nextY, nextX, 2);
			slide(nowY, nowX, nextY, nextX, 2);
		}		
	}
}

void right(){
	for(int i=0; i<N; i++){
		for(int j=N-1; j>=0; j--){
			if(Map[i][j].data == 0) continue;
			
			int nowY = i, nowX = j;
			int nextY= i, nextX = j+1;
			
			slide(nowY, nowX, nextY, nextX, 1);
			merge(nowY, nowX, nextY, nextX, 1);
			slide(nowY, nowX, nextY, nextX, 1);
		}		
	}
}

void left(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(Map[i][j].data == 0) continue;
			
			int nowY = i, nowX = j;
			int nextY= i, nextX = j-1;
			
			slide(nowY, nowX, nextY, nextX, 3);
			merge(nowY, nowX, nextY, nextX, 3);
			slide(nowY, nowX, nextY, nextX, 3);
		}		
	}
}

void swipe(int dir){
	initMerge();
	
	switch(dir){
	case 0:
		down();
		break; // down
	case 1:
		right();
		break;	
	case 2:
		up();
		break;
	case 3:
		left();
		break;			
	}
}

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int data;
			cin >> data;
			initMap[i][j].data = data;
			initMap[i][j].merge = false;
		}
	}
}

void update(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			ret = max(ret, Map[i][j].data);
		}
	}
}

void printMap(){
	cout << "\n";
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << Map[i][j].data << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void play(){
	if(vecDir.size() == 5){
		memcpy(Map, initMap, sizeof(initMap));
				
		for(int dIdx=0; dIdx<5; dIdx++){
			swipe(vecDir[dIdx]);
		}
		
		update();

		return;
	}
	
	for(int dir=0; dir<4; dir++){
		vecDir.push_back(dir);
		play();
		vecDir.pop_back();
	}
	
	return;
}

void output(){
	cout << ret;
}

void run(){
	input();
	play();
	output();
}

int main(){
	run();
	return 0;
}
