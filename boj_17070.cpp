#include<bits/stdc++.h>

using namespace std;

int N, Map[17][17] = {0,}, DP[17][17] = {0,}, ret = 0;
bool visited[3][17][17] = {0,};


typedef struct pipe{
	int dir;
	int y;
	int x;
} PIPE; // 0: 가로, 1: 세로, 2: 대각선 

vector<pair<int,int>> moveTo = 
{
	{0,1}, {1,0},
	{1,1}
};

bool wallCheck(int y, int x, int dir){
	if(dir == 0 || dir == 1) return !Map[y][x];
	else return !Map[y][x] && !Map[y-1][x] && !Map[y][x-1];
}

bool rangeCheck(int y, int x){
	return 1 <= y && y <= N && 1 <= x && x <= N;
}

void input(){
	cin >> N;
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> Map[i][j];
	
	DP[1][2] = 1;
}

void printDP(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
}

void dfs(PIPE now, PIPE prev){
	if(!rangeCheck(now.y, now.x)) return;	
	if(now.y == N && now.x == N) ret++;

	
	if(now.dir == 0){
		PIPE to_hor = {0, now.y+moveTo.at(0).first, now.x+moveTo.at(0).second};
		PIPE to_dia = {2, now.y+moveTo.at(2).first, now.x+moveTo.at(2).second};
		
		if(wallCheck(to_hor.y, to_hor.x, 0) && rangeCheck(to_hor.y,to_hor.x)) dfs(to_hor, now);
		if(wallCheck(to_dia.y, to_dia.x, 2) && rangeCheck(to_dia.y, to_dia.x)) dfs(to_dia, now);
	}
	
	if(now.dir == 1){
		PIPE to_ver = {1, now.y+moveTo.at(1).first, now.x+moveTo.at(1).second};
		PIPE to_dia = {2, now.y+moveTo.at(2).first, now.x+moveTo.at(2).second};
		
		if(wallCheck(to_ver.y, to_ver.x, 1) && rangeCheck(to_ver.y,to_ver.x)) dfs(to_ver, now);
		if(wallCheck(to_dia.y, to_dia.x, 2) && rangeCheck(to_dia.y,to_dia.x)) dfs(to_dia, now);
	}
	
	if(now.dir == 2){
		PIPE to_hor = {0, now.y+moveTo.at(0).first, now.x+moveTo.at(0).second};
		PIPE to_ver = {1, now.y+moveTo.at(1).first, now.x+moveTo.at(1).second};
		PIPE to_dia = {2, now.y+moveTo.at(2).first, now.x+moveTo.at(2).second};
		
		if(wallCheck(to_hor.y, to_hor.x, 0) && rangeCheck(to_hor.y,to_hor.x)) dfs(to_hor, now);
		if(wallCheck(to_ver.y, to_ver.x, 1) && rangeCheck(to_ver.y,to_ver.x)) dfs(to_ver, now);
		if(wallCheck(to_dia.y, to_dia.x, 2) && rangeCheck(to_dia.y,to_dia.x)) dfs(to_dia, now);
	}
	
	return;
}

void output(){
	cout << ret;
	//cout << DP[N][N];
}



void run(){
	input();
	
	PIPE start  = {0, 1, 2};
	PIPE to_hor = {0, 1, 3};
	PIPE to_dia = {2, 2, 3};
	
	if(wallCheck(to_hor.y, to_hor.x, 0) && rangeCheck(to_hor.y, to_hor.x)) dfs(to_hor, start);
	if(wallCheck(to_dia.y, to_dia.x, 2) && rangeCheck(to_dia.y, to_dia.x)) dfs(to_dia, start);
	
	output();
	
	return;
}


int main(){
	run();
	return 0;
}
