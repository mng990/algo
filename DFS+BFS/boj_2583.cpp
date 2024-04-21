#include<bits/stdc++.h>

using namespace std;

int row, col, K;
int Map[104][104] = {0,};
int visited[104][104] = {0,};
vector<int> result;
vector<vector<int>> moveTo = {
	{0,1}, {0,-1},
	{1,0}, {-1,0}
};

void drawSquare(pair<int, int> leftDown, pair<int,int> rightUp){
	int leftY = leftDown.first, leftX = leftDown.second;
	int rightY = rightUp.first, rightX = rightUp.second;
	
	for(int i = leftY; i < rightY; i++){
		for(int j = leftX; j < rightX; j++){
			Map[i][j] = 1;
		}
	}
}

void input(){
	cin >> row >> col >> K;
	
	for(int i=0; i<K; i++){
		int leftY, leftX, rightY, rightX;
		cin >> leftX >> leftY >> rightX >> rightY;
		 
		pair<int, int> leftDown = make_pair(leftY, leftX);
		pair<int, int> rightUp  = make_pair(rightY, rightX);
		
		drawSquare(leftDown, rightUp);
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<row && 0<=x && x<col;
}

int DFS(int y, int x, int cnt){
	
	visited[y][x] = 1;
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = y + moveTo.at(i).at(0);
		int nextX = x + moveTo.at(i).at(1);
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(Map[nextY][nextX]) continue;
		if(visited[nextY][nextX]) continue;
		
		cnt = DFS(nextY, nextX, cnt+1);		
	}
	
	return cnt;
}

void printVisited(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}

void searchMap(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(!visited[i][j] && !Map[i][j]) result.push_back(DFS(i, j, 1));
		}
	}
}

void output(){
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for(int i=0; i<result.size(); i++)
		cout << result.at(i)<< " ";
}

void printMap(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cout << Map[i][j] << ' ';
		cout << '\n';
	}
}



void run(){
	input();
	searchMap();
	output();
}



int main(){
	run();
	
	return 0;
}
