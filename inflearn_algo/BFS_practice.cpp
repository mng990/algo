#include<bits/stdc++.h> 

using namespace std;

int N, M, startY, startX, carrotY, carrotX;


vector<vector<int>> Map;
vector<vector<int>> moveTo = {
	{0,1}, {0,-1},
	{1,0}, {-1,0}
};

vector<vector<int>> visited;

/*
void BFS(){
	queue<int> q;
	q.push(here);
	visited[here] = 1;
	while(q.size()){
		int here = q.front ();
		q.pop();
		
		for(int there : adj [here]){	
			if(visited[there]) continue;
			
			visited[there] = visited[here] + 1; // 방문처리+가중치 
			q.push(there);
		}
	}
}
*/
void input(){
	cin >> N >> M;
	cin >> startY >> startX;
	cin >> carrotY >> carrotX;
	
	for(int i=0; i<N; i++){
		vector<int> mrow;
		vector<int> vrow(M);
		
		for(int j=0; j<M; j++){
			int data;
			cin >> data;
			mrow.push_back(data);
		}
		
		Map.push_back(mrow);
		visited.push_back(vrow);
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<M;
}

void printVisited(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << visited[i][j] << " "; 
		}
		cout << endl;
	}
	cout << endl;
}


void carrot(int nowY, int nowX){
	queue<vector<int>> carrotBox;
	
	visited.at(nowY).at(nowX) = 1;
	carrotBox.push(vector<int>({nowY, nowX}));

	printVisited();
	while(!carrotBox.empty()){
		vector<int> now = carrotBox.front();
		nowY = now.at(0), nowX = now.at(1);
		
		printVisited();

		for(int i=0; i<moveTo.size(); i++){
			int nextY = nowY += moveTo.at(i).at(0);
			int nextX = nowX += moveTo.at(i).at(1);
			
			if(!rangeCheck(nextY,nextX)) continue;
			if(Map.at(nextY).at(nextX) == 0) continue;
			if(visited.at(nextY).at(nextX) > 0) continue;
			
			visited.at(nextY).at(nextX) = visited.at(nowY).at(nowX) + 1;
					
			carrotBox.push(vector<int>({nextY, nextX}));
			if(nextY == carrotY && nextX == carrotX) return;
		}		
		carrotBox.pop();
	}
	
	return ; 
}

void output(){
	cout << visited.at(carrotY).at(carrotX) << '\n';
}	
	
void run(){
	input();
	carrot(startY, startX);
	output();
}

int main(){
	run();
	return 0;
}
