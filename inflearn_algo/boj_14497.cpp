#include <bits/stdc++.h>

using namespace std;

int N, M, ret = 0;

char Map[304][304];
int visited[304][304] = {0,};
int cost[304][304] = {0,};

pair<int,int> JN;
pair<int,int> choco;

queue<pair<int,int>> blankQueue; 

queue<pair<int,int>> wave;
vector<pair<int,int>> moveTo = {
	{1,0}, {-1,0},
	{0,1}, {0,-1}
};

void input(){
	cin >> N >> M;
	
	cin >> JN.first >> JN. second;
	JN.first--;
	JN.second--;
	
	wave.push(JN);
	blankQueue.push(JN);
	visited[JN.first][JN.second] = 1;
		
	cin >> choco.first >> choco.second;
	choco.first--;
	choco.second--;
	
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> Map[i][j];	
		}
	}
}

bool rangeCheck(int y, int x){
	return 0 <= y && y <N && 0 <= x && x < M;
}

void printVisited(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void printCost(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << cost[i][j] << " ";
			
		}
		cout << '\n';
	}
	cout << '\n';
}

bool spread(int nowY, int nowX, int dir, int cost){
	int nextY = nowY + moveTo.at(dir).first;
	int nextX = nowX + moveTo.at(dir).second;
	
	if(!rangeCheck(nextY,nextX)) return false;
	if(visited[nextY][nextX]) return false;

	wave.push(make_pair(nextY, nextX));
	visited[nextY][nextX] = cost;
	
	if(nextY == choco.first && nextX == choco.second){
		cout << visited[nextY][nextX]-1 << '\n';
		exit(0);
	}
	
	if(Map[nextY][nextX] != '0') return false;

		
	for(int i=0; i<moveTo.size(); i++){
		spread(nextY, nextX, i, cost);
	}
	
	return true;
}



void BFS(){
	
	while(!wave.empty()){
		int qsize = wave.size();
		for(int i=0; i<qsize; i++){

			pair<int,int> now = wave.front();
			int nowCost = visited[now.first][now.second];

			for(int dir=0; dir<moveTo.size(); dir++){
				if(!spread(now.first, now.second, dir, nowCost+1)){
					continue;
				}
			}
			
			wave.pop();
		}
	}
	
	return;
}

void DoubleQueue(){
	int cnt = 0;
	while(Map[choco.first][choco.second]!='0'){
		cnt++; // ·¹º§¸µ 
		queue<pair<int,int>> costQueue;
		while(!blankQueue.empty()){
			pair<int,int> now = blankQueue.front();
			blankQueue.pop();
			
			for(int i=0; i<moveTo.size(); i++){
				int nextY = now.first  + moveTo.at(i).first;
				int nextX = now.second + moveTo.at(i).second;
				
				if(!rangeCheck(nextY, nextX)) continue;
				if(visited[nextY][nextX]) continue;
				
				visited[nextY][nextX] = cnt;
				
				if(Map[nextY][nextX] != '0'){
					costQueue.push(make_pair(nextY, nextX));
					Map[nextY][nextX] = '0';					
				}
				else{
					blankQueue.push(make_pair(nextY, nextX));
				}
			}
		}
		blankQueue = costQueue;
	}
}

int main(){
	input();
	DoubleQueue();
	//printVisited();
	//printCost();
	cout << visited[choco.first][choco.second];
	//printVisited();
	return 0;
}

