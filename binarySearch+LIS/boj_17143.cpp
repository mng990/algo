#include <bits/stdc++.h>

using namespace std;

int R, C, M, ret=0;
int Map[104][104] = {0,};
int swimMap[104][104] = {0,};

typedef struct shark{
	int speed;
	int size;
	pair<int,int> pos;
	pair<int,int> mT;
}SHARK;

vector<SHARK> vecShark;
vector<pair<int,int>> moveTo = {
	{-1,0}, {1, 0},
	{0, 1}, {0,-1}
};


bool rangeCheck(int y, int x){
	return 0<=y && y<R && 0<=x && x<C;
}

void input(){
	cin >> R >> C >> M;
	
	vecShark.push_back({0,0,{0,0},{0,0}});
	
	for(int i=1; i<=M; i++){
		
		int sharkY, sharkX, speed, size, dir;

		cin >> sharkY >> sharkX >> speed >> dir >> size;
			
		int prevIdx = Map[sharkY][sharkX];
			
		if(prevIdx > 0 && vecShark[prevIdx].size > size){
			size = 0;
		}
		
		vecShark.push_back({speed, size, {sharkY, sharkX}, moveTo[dir-1]});
		Map[sharkY][sharkX] = i;
	}
}

void catchUp(int fisherX){
	for(int i=1; i<=R; i++){
		if(Map[i][fisherX] != 0){
			ret += vecShark[Map[i][fisherX]].size;
			vecShark[Map[i][fisherX]].size = 0;
			Map[i][fisherX] = 0;
			
			break;
		}
	}
	
	return ;
}

void swim(SHARK& _shark){
	pair<int,int> pos = _shark.pos;
	pair<int,int> mT = _shark.mT;
	int speed = _shark.speed;
	
	if(mT.first  != 0 && speed >= 2*(R-1)){
		speed %= 2*(R-1);
		
	} 
	if(mT.second != 0 && speed >= 2*(C-1)){
		speed %= 2*(C-1);
	} 
	
	for(int i=0; i<speed; i++){
		if(pos.first == 1 && mT.first < 0){
			mT.first *= -1;
		}
		if(pos.second == 1 && mT.second < 0){
			mT.second *= -1;
		}
		
		if(pos.first == R && mT.first > 0){
			mT.first *= -1;
		}
		if(pos.second == C && mT.second > 0){
			mT.second *= -1;
		}
		
		pos.first += mT.first;
		pos.second += mT.second;

	}
	
	_shark.pos = pos;
	_shark.mT = mT;
	
	
	return;
}

void bite(int nowIdx){
	int prevIdx = swimMap[vecShark[nowIdx].pos.first][vecShark[nowIdx].pos.second];
		
	if(prevIdx > 0){
		int otherShark = vecShark[prevIdx].size;
			
		if(otherShark < vecShark[nowIdx].size){
			vecShark[prevIdx].size = 0;
			swimMap[vecShark[nowIdx].pos.first][vecShark[nowIdx].pos.second] = nowIdx;
		}
		else{
			vecShark[nowIdx].size = 0;
		}
	}
	else{
		swimMap[vecShark[nowIdx].pos.first][vecShark[nowIdx].pos.second] = nowIdx;
	}
	
	return;
}

void sharkWave(){	
	memset(swimMap, 0, sizeof(swimMap));
	
	for(int i=1; i<=M; i++){
		if(vecShark[i].size == 0) continue; // Á×Àº »ó¾î => size = 0 
				
		swim(vecShark[i]);
		bite(i);
	}
		
	memcpy(Map, swimMap, sizeof(swimMap));
}

void turn(int fisherX){
	catchUp(fisherX);
	sharkWave();
}

void output(){
	cout << ret << "\n";
}

void run(){
	input();
	for(int fisherX=1; fisherX<=C; fisherX++){
		turn(fisherX);
	}
	output();
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
