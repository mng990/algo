#include<bits/stdc++.h>

using namespace std;

int N, K, L, ret = 0;
int Map[104][104];

queue<pair<int,int>> snake;
queue<pair<int,char>> snakeMove;


vector<pair<int,int>> moveTo = 
{
	{0, 1}, { 1,0},  
	{0,-1}, {-1,0}
}; // if(dir == 'D') idx++, if(dir == 'L') idx--; 

void input(){
	cin >> N >> K; 
	
	for(int i=0; i<K; i++){
		int appleY, appleX;
		cin >> appleY >> appleX;
		
		Map[appleY-1][appleX-1] = 1;
	}
	cin >> L;
	
	for(int i=0; i<L; i++){
		pair<int,char> moveSet;
		cin >> moveSet.first >> moveSet.second;
		snakeMove.push(moveSet);	
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

bool crush(int headY, int headX){
	return !rangeCheck(headY,headX) || Map[headY][headX] == 2;
}

void printMap(int dir){
	cout << "time: " << ret << "\n";
	cout << "dir: " << dir << "\n";
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << "\n";
}

void play(){
	int headY=0, headX=0, dir=0;
	
	snake.push({headY,headX});	
	Map[headY][headX] = 2;
	
	while(true){
		pair<int,char> move = snakeMove.front();
		
		if(move.first == ret){			
			if(move.second == 'D') dir++;
			else				   dir--;
			
			if(dir <  0) dir+=4;
			if(dir >= 4) dir%=4;
			
			snakeMove.pop();
		}
		
				
		headY += moveTo[dir].first;
		headX += moveTo[dir].second;
		ret++;
		
		if(crush(headY, headX)){
			return;
		}
		
		if(Map[headY][headX] != 1){
			pair<int,int> tail = snake.front();
			
			Map[tail.first][tail.second] = 0;
			snake.pop();
		}
		
		Map[headY][headX] = 2;
		snake.push({headY, headX});
		
		
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
