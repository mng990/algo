#include<bits/stdc++.h>

using namespace std;

int N, ret = 0;
int visited[104][104] = {0,};

vector<int> dragon[4][11];
vector<vector<int>> dragonCurve;
vector<pair<int,int>> moveTo = {
	{0, 1}, {-1,0},
	{0,-1}, { 1,0}
}; 
// idx + 1 => 90도 회전  
// 뻗어나가는 방향의 규칙성 찾기!! 
// 0 / 1 / 2, 1 / 2,3, 2,1 / 2,3,0,3, 2,3,2,1

bool rangeCheck(int y, int x){
	return 0<=y && y<=100 && 0<=x && x<=100;
}

void makeDragon(){
	for(int i=0; i<moveTo.size(); i++){
		dragon[i][0].push_back(i);
		dragon[i][1].push_back((i+1)%4);
		
		for(int j=2; j<=10; j++){
			int n = dragon[i][j-1].size();
			
			for(int k=n-1; k>=0; k--){
				dragon[i][j].push_back((dragon[i][j-1][k]+1) % 4);
			} // 이전 세대의 rotate (prevIdx+1, 역순으로 push_back)
			
			for(int k=0; k<n; k++){
				dragon[i][j].push_back(dragon[i][j-1][k]);
			} // 이전 세대 
		}
	}
}

void draw(int dcIdx){
	vector<int> DC = dragonCurve[dcIdx];
	int x = DC[0], y = DC[1], dir = DC[2], g = DC[3];
	
	visited[y][x] = 1;
	
	for(int i=0; i<=g; i++){
		for(int j=0; j<dragon[dir][i].size(); j++){
			int nowDir = dragon[dir][i][j];
			y += moveTo[nowDir].first;
			x += moveTo[nowDir].second;
						
			visited[y][x] = 1;
		}
	}
	//cout << dcIdx <<", draw::end" << "\n";
	return;
}

bool isSquare(int y, int x){
	return visited[y][x] && visited[y+1][x] && visited[y][x+1] && visited[y+1][x+1];
}

void printVisited(){
	for(int i=0; i<=100; i++){
		for(int j=0; j<=100; j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void getCnt(){
	for(int i=0; i<=100; i++){
		for(int j=0; j<=100; j++){
			if(isSquare(i, j)) ret++;
		}
	}
}


void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		int y, x, d, g;
		cin >> x >> y >> d >> g;
		dragonCurve.push_back({x,y,d,g});
	}
}

void output(){
	cout << ret;
}

void run(){
	input();
	makeDragon();
	for(int dcIdx=0; dcIdx<dragonCurve.size(); dcIdx++){
		draw(dcIdx);
	}
	getCnt();
	output();
}

int main(){
	run();
	return 0;
}
