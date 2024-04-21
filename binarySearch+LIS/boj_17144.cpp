#include<bits/stdc++.h>

using namespace std;

int R, C, T, ret = 0;
vector<pair<int,int>> filter;

int Map [1004][1004] = {0,};
int dust[1004][1004] = {0,};

vector<pair<int, int>> moveTo = {
	{1, 0}, {0, 1},
	{-1,0}, {0,-1}
};

bool rangeCheck(int y, int x){
	return 0<=y && y<R && 0<=x && x<C;
}

bool isFilter(int y, int x){
	for(int i=0; i<filter.size(); i++){
		if(filter[i].first == y && filter[i].second == x){
			return true;
		}
	}
	
	return false;
}


void input(){
	cin >> R >> C >> T;
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> Map[i][j];
			if(Map[i][j] == -1){
				filter.push_back({i, j});
			}
		}
	}
}


void updateDust(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			Map[i][j] += dust[i][j];
		}
	}
	
	memset(dust, 0, sizeof(dust));

}

void updateAC(){
	
	pair<int,int> up = filter[0];
	pair<int,int> down = filter[1];
	// up
	// i == up.first
	for(int j=1; j<C; j++){
		Map[up.first][j] = dust[up.first][j];
	}
	
	// j == C-1;
	for(int i=up.first; i>=0; i--){
		Map[i][C-1] = dust[i][C-1];
	} 

	// i == 0
	for(int j=C-1; j>=0; j--){
		Map[0][j] = dust[0][j];
	}
	
	// j == 0
	for(int i=0; i < up.first; i++){
		Map[i][0] = dust[i][0];
	}
	
	
	//down
	// i == down.first;
	for(int j=1; j<C; j++){
		Map[down.first][j] = dust[down.first][j];
	}
	
		
	// j == C-1;
	for(int i = down.first; i<R; i++){
		Map[i][C-1] = dust[i][C-1];
	}

	
	// i == R-1;
	for(int j=C-1; j>=0; j--){
		Map[R-1][j] = dust[R-1][j];
	}
	
	// j == down.second;
	for(int i=R-1; i>down.first; i--){
		Map[i][0] = dust[i][0];  
	}	

	memset(dust, 0, sizeof(dust));
}



void printMap(){
	cout << "\n";
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << Map[i][j] << " ";
		}
		
		cout << "\n";
	}
}

void printDust(){
	cout << "\n";
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << dust[i][j] << " ";
		}
		
		cout << "\n";
	}
}


void spread(int dustY, int dustX){
	
	int nowDust = Map[dustY][dustX];
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = dustY + moveTo[i].first;
		int nextX = dustX + moveTo[i].second;
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(isFilter(nextY, nextX)) continue;
		
		Map [dustY][dustX] -= nowDust/5;
		dust[nextY][nextX] += nowDust/5;
	}
	
	return ;
}

void airCycle(){
	
	pair<int,int> up = filter[0];
	pair<int,int> down = filter[1];
	
	// up
	// i == up.first;
	for(int j=1; j<C; j++){
		if(j+1 < C) dust[up.first][j+1] = Map[up.first][j];
	}
	
	// j == C-1;
	for(int i=up.first; i>=0; i--){
		if(i -1 >= 0) dust[i-1][C-1] = Map[i][C-1];
	} 

	// i == 0
	for(int j=C-1; j>=0; j--){
		if(j-1 >= 0) dust[0][j-1] = Map[0][j];
	}
	
	// j == 0
	for(int i=0; i < up.first; i++){
		if(i+1 < up.first) dust[i+1][0] = Map[i][0];
	}
	
	
	//down
	// i == down.first;
	for(int j=1; j<C; j++){
		if(j+1 < C) dust[down.first][j+1] = Map[down.first][j];
	}
	
	
	// j == C-1;
	for(int i = down.first; i<R; i++){
		if(i+1 < R) dust[i+1][C-1] = Map[i][C-1];
	}

	
	// i == R-1;
	for(int j=C-1; j>=0; j--){
		if(j-1 >= 0) dust[R-1][j-1] = Map[R-1][j];
	}
	
	// j == down.second;
	for(int i=R-1; i>=down.first; i--){
		if(i-1 > down.first) dust[i-1][0] = Map[i][0];  
	}
}

void turn(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(Map[i][j] > 0){
				spread(i, j);
			}
		}
	}
	
	updateDust();

	
	airCycle();
	updateAC();
	
	//printMap();
}

void culDust(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(Map[i][j] != -1)
				ret += Map[i][j];
		}
	}
}

void output(){
	cout << ret <<"\n";
}

int main(){
	input();
	for(int i=0; i<T; i++){
		turn();
	}
	culDust();
	output();
	
	return 0;
}
