#include<bits/stdc++.h>

using namespace std;

int R, C, ret=0;

char Map[1004][1004];
int visitedJ[1004][1004] = {0,};
int visitedF[1004][1004] = {0,};

vector<pair<int, int>> vecF;
pair<int, int> J;
vector<pair<int,int>> moveTo = {
	{1,0 }, {0, 1},
	{-1,0}, {0,-1}
};

bool rangeCheck(int y, int x){
	return 0<=y && y<R && 0<=x && x<C;
}

bool blocked(int y, int x){
	return Map[y][x] == '#';
}

int goalCheck(){
	int ret = INT_MAX;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(i == R-1 || j == C-1 || i==0 || j==0){
				if(visitedJ[i][j]){
					ret = min(ret, visitedJ[i][j]);
				}
			}
		}
	}
	return ret;
}

void input(){
	cin >> R >> C;
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> Map[i][j];
			if(Map[i][j] == 'F'){
				vecF.push_back(make_pair(i, j));
			}
			if(Map[i][j] == 'J'){
				J = make_pair(i, j);
			}
		}
	}
}

void printVisitedF(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << visitedF[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void printVisitedJ(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << visitedJ[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}


void fire(pair<int, int> F){
	queue<pair<int,int>> queFire;
	queFire.push(F);
	visitedF[F.first][F.second] = 1;
	
	while(!queFire.empty()){
		pair<int,int> nowF = queFire.front();
		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = nowF.first  + moveTo.at(i).first;
			int nextX = nowF.second + moveTo.at(i).second;
			int nextVF = visitedF[nowF.first][nowF.second] + 1;
			
			if(!rangeCheck(nextY, nextX)) continue;
			if(visitedF[nextY][nextX] && 
			visitedF[nextY][nextX] <= nextVF) continue;
			
			if(Map[nextY][nextX] == '#') continue;
			
			visitedF[nextY][nextX] = nextVF;
			queFire.push(make_pair(nextY, nextX));
		}
		queFire.pop();
	}	
}

void JH(){
	queue<pair<int,int>> queJH;
	queJH.push(J);
	visitedJ[J.first][J.second] = 1;
	
	while(!queJH.empty()){
		pair<int,int> nowJ = queJH.front();
		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = nowJ.first  + moveTo.at(i).first;
			int nextX = nowJ.second + moveTo.at(i).second;
			int nextVS = visitedJ[nowJ.first][nowJ.second]+1;
			
			if(!rangeCheck(nextY, nextX)) continue;
			if(visitedJ[nextY][nextX]) continue;
			if(Map[nextY][nextX] == '#') continue;
			if(visitedF[nextY][nextX]){
				if(visitedF[nextY][nextX] <= nextVS) continue;
			} 
				

			visitedJ[nextY][nextX] = nextVS;
			queJH.push(make_pair(nextY, nextX));
		}
		queJH.pop();
	}	
}

void output(){
	int ret = goalCheck();
	
	if(ret == INT_MAX){
		cout << "IMPOSSIBLE" << '\n';	
	}
	else{
		cout << ret << '\n';
	}
}

void run(){
	input();
	for(int i=0; i<vecF.size(); i++){
		fire(vecF.at(i));
	}
	
	JH();
	
	//printVisitedF();
	//printVisitedJ();
	
	output();
}

int main(){
	run();
	return 0;
}
