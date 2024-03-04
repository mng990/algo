#include<bits/stdc++.h>

using namespace std;

int N, M, ans = 0;
int initLab[12][12] = {0,};
int lab[12][12] = {0,};
int visited[12][12] = {0,};

vector<pair<int,int>> wall;
vector<vector<pair<int,int>>> vecWall;
vector<vector<int>> moveTo = {
	{1,  0}, {-1, 0},
	{0, -1}, { 0, 1}
};

void printLab(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << lab[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void init(){
	copy(&initLab[0][0], &initLab[0][0] + 12*12, &lab[0][0]);
	//printLab();
	fill_n(&visited[0][0], 12*12, 0);
}

void makeWall(int startY, int startX){
	if(wall.size() == 3){
		vecWall.push_back(wall);
		return ;
	}
	
	
	
	for(int i=startY; i<N;i++){
		if(i > startY) startX = -1;
		for(int j=startX+1; j<M; j++){
			if(initLab[i][j] == 0){
				wall.push_back(make_pair(i,j));
				makeWall(i, j);
				wall.pop_back();
			}
		}
	}
	
	return ;
}

void input(){

	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			int data;
			cin >> data;
			initLab[i][j] = data;
		}
	}
	
	makeWall(0, -1);
}

bool rangeCheck(int y, int x){
	return (0<=y && y< N) && (0<=x && x< M);
}

void virus(int startY, int startX){
	queue<pair<int,int>> spreadOut;
	spreadOut.push(pair<int,int>(startY, startX));
	
	while(!spreadOut.empty()){
		pair<int, int> now = spreadOut.front();
		int nowY = now.first;
		int nowX = now.second;
		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = nowY + moveTo.at(i).at(0);
			int nextX = nowX + moveTo.at(i).at(1);
			
	 		if(!rangeCheck(nextY, nextX)) continue;
	 		if(lab[nextY][nextX] != 0) continue;
	 		if(visited[nextY][nextX]) continue;
	 		
	 		lab[nextY][nextX] = 2;
	 		visited[nextY][nextX] = 1;
	 		spreadOut.push(pair<int,int>(nextY, nextX));
		}
		
		spreadOut.pop();
	}
}

int safeZone(){
	int cnt = 0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(lab[i][j] == 0) cnt++;
		}
	}
	
	return cnt;
}

void spread(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(lab[i][j] == 2 && !visited[i][j]){
				virus(i, j);
			}
		}
	}
	return ;
}

void printWall(){
	for(int i=0; i<vecWall.size(); i++){
		int wallY1 = vecWall.at(i).at(0).first;
		int wallX1 = vecWall.at(i).at(0).second;
		int wallY2 = vecWall.at(i).at(1).first;
		int wallX2 = vecWall.at(i).at(1).second;
		int wallY3 = vecWall.at(i).at(2).first;
		int wallX3 = vecWall.at(i).at(2).second;		
		
		if((wallY1 == 0 && wallX1 == 1)){
			cout << vecWall.at(i).at(0).first << vecWall.at(i).at(0).second << ' ';
			cout << vecWall.at(i).at(1).first << vecWall.at(i).at(1).second << ' ';
			cout << vecWall.at(i).at(2).first << vecWall.at(i).at(2).second << '\n';
		}
		
	}
	cout << '\n';
}


void run(){
	input();
	//printWall();
	for(int i=0; i<vecWall.size(); i++){
		init();
		
		for(int j=0; j<3; j++){
			int wallY = vecWall.at(i).at(j).first;
			int wallX = vecWall.at(i).at(j).second;
					
			lab[wallY][wallX] = 1;
		}
		
		spread();
		
		int nowSF = safeZone();
		
		if(ans < nowSF){
			ans = max(ans, safeZone());
		}
	}
	
	cout << ans << '\n';
}




void test(){
	input();
	//printWall();
	//spread();
	//printLab();
}

int main(){
	run();
	return 0;
}
