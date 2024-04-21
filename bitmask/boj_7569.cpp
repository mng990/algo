#include <bits/stdc++.h>

using namespace std;

int M, N, H, ret = 1, blank = 0, total, nowG = 0;
int Map[104][104][104] = {0,};
int nextMap[104][104][104] = {0,};
int visited[104][104][104] = {0,};
int visitedG[104][104][104] = {0,};


struct Dimension{
	int z;
	int y;
	int x;
	
	int operator[](int idx) const {
		return *(&z+idx);
	}
}typedef TD;


queue<TD> queGrown;
vector<TD> adj = {
	{1,0,0}, {-1,0,0},
	{0,1,0}, {0,-1,0},
	{0,0,1}, {0,0,-1},
}; // z, y, x

bool rangeCheck(int z, int y, int x){
	return 0 <= z && z<H && 0<=y && y<N 
		&& 0 <= x && x<M;
}

void input(){
	cin >> M >> N >> H;
	
	for(int h=0; h<H; h++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cin >> Map[h][i][j];
				if(Map[h][i][j] == -1) blank++;
				if(Map[h][i][j] == 1){
					 queGrown.push({h, i, j});
					 visited[h][i][j] = 1;
				}
			}
		}
	}
	total = N*M*H - blank;
	nowG = queGrown.size();
}

void printMap(){
	cout << '\n';
	for(int h=0; h<H; h++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cout << Map[h][i][j] << " ";
			}
			cout << '\n';
		}
	}
	cout << '\n';
}

void printVisited(){
	cout << '\n';
	for(int h=0; h<H; h++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cout << visited[h][i][j] << " ";
			}
			cout << '\n';
		}
	}
	cout << '\n';
}

void grown(){
	queue<TD> queNext;
	
	while(!queGrown.empty()){
		TD now = queGrown.front();
		
		for(int i=0; i<adj.size(); i++){
			int nextZ = now[0] + adj[i][0];
			int nextY = now[1] + adj[i][1];
			int nextX = now[2] + adj[i][2];
			
			if(!rangeCheck(nextZ, nextY, nextX)) continue;
			if(Map[nextZ][nextY][nextX] == -1) continue;	
			if(visited[nextZ][nextY][nextX] == 1) continue;
			
			visited[nextZ][nextY][nextX] = 1;
			queNext.push({nextZ, nextY, nextX});
		}

		
		queGrown.pop();
	}
	
	nowG += queNext.size();
	
	queGrown = queNext;
}

void getOld(){
	int prevG = -1;
	
	while(total != nowG){
		ret++;
		grown();
		
		if(nowG == prevG){
			ret = 0;
			break;
		}		
		
		prevG = nowG;
	}
	
	cout << ret-1 << '\n';
	
	return;
}




int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	input();
	getOld();
	return 0;
}
