#include<bits/stdc++.h>

using namespace std;

int W, H, K;

vector<pair<int,int>> moveTo = {
	{0, 1}, { 1,0},
	{0,-1}, {-1,0}
};

vector<pair<int,int>> jumpTo = {
	{2, 1}, {2, -1},
	{1, 2}, {1, -2},
	{-2,1}, {-2,-1},
	{-1,2}, {-1,-2}
};

int Map[204][204];
int visited[34][204][204] = {0,};
int result[204][204] = {0,};

typedef struct dot{
	int y;
	int x;
	int horse;
}DOT;

void input(){
	cin >> K;
	cin >> W >> H;
	
	for(int i=0; i<H; i++){
		for(int j=0;j<W; j++){
			cin >> Map[i][j];
		}
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<H && 0<=x && x<W;
}

bool goal(int y, int x){
	return y == H-1 && x == W-1;
}

int BFS(){
	int startY = 0, startX = 0;
	queue<DOT> queDot;
	
	visited[0][startY][startX] = 1;
	visited[1][startY][startX] = 1;
	
	queDot.push({startY, startX, 0});
	
	if(goal(startY, startX)){
		return result[startY][startX];
	}
	
	while(!queDot.empty()){
		int nowY = queDot.front().y;
		int nowX = queDot.front().x;
		int nowHorse = queDot.front().horse;
		
		
		for(int i=0; i<moveTo.size(); i++){
			int nextY = nowY + moveTo[i].first;
			int nextX = nowX + moveTo[i].second;
			
			if(!rangeCheck(nextY, nextX)) continue;
			if(Map[nextY][nextX]) continue;
			if(visited[nowHorse][nextY][nextX]) continue;
			
			result[nextY][nextX] = result[nowY][nowX] + 1;
			visited[nowHorse][nextY][nextX] = 1;
			
			if(goal(nextY, nextX)){
				return result[nextY][nextX];
			}
			
			queDot.push({nextY, nextX, nowHorse});
		}
		
		if(nowHorse < K){
			for(int i=0; i<jumpTo.size(); i++){
				int nextY = nowY + jumpTo[i].first;
				int nextX = nowX + jumpTo[i].second;
				
				if(!rangeCheck(nextY, nextX)) continue;
				if(Map[nextY][nextX]) continue;
				if(visited[nowHorse+1][nextY][nextX]) continue;
				
				result[nextY][nextX] = result[nowY][nowX] + 1;
				visited[nowHorse+1][nextY][nextX] = 1;
				
				if(goal(nextY, nextX)){
					return result[nextY][nextX];
				}
				queDot.push({nextY, nextX, nowHorse+1});
			}
		}
		
		queDot.pop();
	}
	
	return -1;
}

void printVisited(){
	for(int k=0; k<=K; k++){
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				cout << visited[k][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

void printResult(){
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(){
	input();
	cout << BFS() << "\n";
	//printVisited();
	//printResult();
	return 0;
}
