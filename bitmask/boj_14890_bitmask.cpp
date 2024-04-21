#include<bits/stdc++.h>

using namespace std;

int N, L, ret = 0;

int Map[104][104];
int mask[204] = {0,};
int visited[2][104][104] = {0,};
int slope[4][104][104] = {0,};

vector<pair<int,int>> moveTo = {
	{0, 1}, {1, 0},
	{0,-1}, {-1,0}
};

void input(){
	cin >> N >> L;
	for(int i=0; i<N; i++){
		for(int j=0;j<N; j++){
			cin >> Map[i][j];
		}
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

bool setSlope(int nowY, int nowX, bool isRow, int dir){
	int i = 0;
	int base = Map[nowY][nowX];
	
	for(i; i<L; i++){
		int nextY = nowY + moveTo.at(dir).first*i;
		int nextX = nowX + moveTo.at(dir).second*i;
		
		if(base != Map[nextY][nextX]) break;
		if(!rangeCheck(nextY,nextX)) break;

		if(isRow){
			
			if(visited[0][nextY][nextX]) break;
			visited[0][nextY][nextX] = 1; 
		}
		else{

			if(visited[1][nextY][nextX]) break;	
			visited[1][nextY][nextX] = 1;
		}
		
	}
	
	bool isSet = (i == L);
	
	if(!isSet){
		i--;
		for(i; i>=0; i--){
			int nextY = nowY + moveTo.at(dir).first*i;
			int nextX = nowX + moveTo.at(dir).second*i;
			
			if(isRow){
				visited[0][nextY][nextX] = 0;			
			}
			else{
				visited[1][nextY][nextX] = 0;
			}
		}
	}
	else{	
		slope[dir][nowY][nowX]++;
	}
	
	return isSet;
}

void printMap(){
	cout << '\n';
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << Map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void printSlope(){
	cout << '\n';
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << slope[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
}

void printMask(){
	cout << "row" << endl;
	for(int i=0; i<N; i++){
		
		cout << bitset<6>(mask[i]);
		
		cout << '\n';
	}
	
	cout << "col" << endl;
	for(int i=N; i<2*N; i++){
		
		cout << bitset<6>(mask[i]);
		
		cout << '\n';
	}
}

void getRet(){
	for(int i=0; i<N; i++){
		int j=0;
		for(j; j<N-1; j++){
			int gap = Map[i][j] - Map[i][j+1];
			
			if(abs(gap) > 1) break;
			
			if(gap == 1  && !slope[0][i][j+1]) break;
			if(gap == -1 && !slope[2][i][j]) break;
		}
		
		if(j == N-1){
			//cout << "row " << i << " is complete!"<<'\n';
			ret++;
		}
	}
	
	for(int j=0; j<N; j++){
		int i=0;
		for(i; i<N-1; i++){
			int gap = Map[i][j] - Map[i+1][j];
			if(gap == 0) continue;
			
			if(abs(gap)>1) break;
			if(gap ==  1 && !slope[1][i+1][j]) break;
			if(gap == -1 && !slope[3][i][j]) break;
		}
		
		
		if(i == N-1){
			//cout << "col " << j << " is complete!"<<'\n';
			ret++;
		}
	}
}

void run(){
	
	for(int i=0; i<N; i++){
		int j=0;
		for(j; j<N-1; j++){
			int gapRow = Map[i][j] - Map[i][j+1];
			if(gapRow == 0) continue;
			if(abs(gapRow) > 1) break;

			if(gapRow == -1){
				if(!setSlope(i, j, true, 2)) break;
			}
			if(gapRow == 1){
				if(!setSlope(i, j+1, true, 0)) break;
			}
		}
	}
	
	for(int j=0; j<N; j++){
		int i=0;
		for(i; i<N-1; i++){
			int gapCol = Map[i][j] - Map[i+1][j];
			if(gapCol == 0) continue;
			if(abs(gapCol) > 1) break;
			
			if(gapCol == -1){
				if(!setSlope(i, j,false, 3)) break;
			}
			if(gapCol == 1){
				if(!setSlope(i+1, j, false, 1)) break;
			}
		}
	}
	
	

}



int main(){
	input();
	run();
	getRet();
	cout << ret;
	return 0;
}
