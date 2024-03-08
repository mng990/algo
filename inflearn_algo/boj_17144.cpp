#include<bits/stdc++.h>

using namespace std;

int R, C, T;
int auy=-1, aux=-1, ady=-1, adx=-1;

int Map[54][54];
int updateDust[54][54];

vector<pair<int,int>> moveTo = {
	{1, 0}, {0, 1},
	{-1,0}, {0,-1}
};

bool rangeCheck(int y, int x){
	return 0<=y && y<R && 0<=x && x<C ;
}

bool airCleanerCheck(int y, int x){
	return (y == auy && x == aux) || (y==ady && x== adx);
}

void printMap(){
	cout << '\n';
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << Map[i][j] << " ";
		}
		cout << '\n';
	}

}

void input(){
	cin >> R >> C >> T;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> Map[i][j];
			if(Map[i][j] == -1){
				if(auy == -1){
					auy = i;
					aux = j;
				}
				else{
					ady = i;
					adx = j;
				}
			}
		}
	}
}

void fineDust(int fy, int fx){
	int dust = Map[fy][fx]/5;

	for(int i=0; i<moveTo.size(); i++){
		int nextY = fy + moveTo.at(i).first;
		int nextX = fx + moveTo.at(i).second;
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(airCleanerCheck(nextY, nextX)) continue;
		
				
		updateDust[fy][fx] -= dust;
		updateDust[nextY][nextX] += dust;	 
	}
}

void spread(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			int now = Map[i][j];
			
			if(now > 0) 
				fineDust(i,j);
		}
	}
}

void updateSP(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			Map[i][j] += updateDust[i][j];
		}
	}
}

void updateAC(){
	// i = auy
	for(int j=aux+1; j<C; j++){
		Map[auy][j] = updateDust[auy][j]; 
	}
	
	// j = C-1
	for(int i=auy; i>=0; i--){
		Map[i][C-1] = updateDust[i][C-1];
	}
	
	// i = 0
	for(int j=C-1; j>=0; j--){
		Map[0][j] = updateDust[0][j];
	}
	
	// j = 0
	for(int i=0; i<auy; i++){
		Map[i][0] = updateDust[i][0];
	}
	
	// i = ady
	for(int j=adx+1; j<C; j++){
		Map[ady][j] = updateDust[ady][j];
	}
	// j = C - 1
	for(int i=ady; i<R; i++){
		Map[i][C-1] = updateDust[i][C-1];
	}
	// i = R-1
	for(int j=C-1; j>=0; j--){
		Map[R-1][j] = updateDust[R-1][j];
	}
	
	// j = adx
	for(int i=R-1; i>ady; i--){
		Map[i][adx] = updateDust[i][adx];
	}
}

void airCleanerUp(){
	// i = auy
	for(int j=aux+1; j<C; j++){
		int nextY = auy; 
		int nextX = j+1;
		if(!rangeCheck(nextY, nextX)) continue;
		updateDust[nextY][nextX] = Map[auy][j];
	}
	
	// j = C-1
	for(int i=auy; i>=0; i--){
		int nextY = i-1;
		int nextX = C-1;
		if(!rangeCheck(nextY, nextX)) continue;
		updateDust[nextY][nextX] = Map[i][C-1];
	}
	
	// i = 0
	for(int j=C-1; j>=0; j--){
		int nextY = 0;
		int nextX = j-1;
		if(!rangeCheck(nextY, nextX)) continue;
		updateDust[nextY][nextX] = Map[0][j];
	}
	
	// j = 0
	for(int i=0; i<auy; i++){
		int nextY = i+1;
		int nextX = 0;
		if(!rangeCheck(nextY, nextX)) continue;
		updateDust[nextY][nextX] = Map[i][0];
		
		if(nextY == auy) updateDust[nextY][nextX] = 0;
	}
}

void airCleanerDown(){
	// i = ady
	for(int j=adx+1; j<C; j++){
		int nextY = ady;
		int nextX = j+1;
		if(!rangeCheck(nextY, nextX)) continue;
		updateDust[nextY][nextX] = Map[ady][j];
	}
	// j = C - 1
	for(int i=ady; i<R; i++){
		int nextY = i+1;
		int nextX = C-1;
		if(!rangeCheck(nextY, nextX)) continue;
		updateDust[nextY][nextX] = Map[i][C-1];
	}
	// i = R-1
	for(int j=C-1; j>=0; j--){
		int nextY = R-1;
		int nextX = j-1;
		if(!rangeCheck(nextY, nextX)) continue;
		updateDust[nextY][nextX] = Map[R-1][j];
	}
	
	// j = adx
	for(int i=R-1; i>ady; i--){
		int nextY = i-1;
		int nextX = adx;
		if(!rangeCheck(nextY, nextX)) continue;
		updateDust[nextY][nextX] = Map[i][adx];
		
		if(nextY == ady) updateDust[nextY][nextX] = 0;
	}
}

int getResult(){
	int ret = 0;
	
	for(int i=0; i<R;i++){
		for(int j=0; j<C;j++){
			if(Map[i][j] < 0) continue;
			
			ret += Map[i][j];		
		}
	}
	return ret;
}

void run(){
	memset(updateDust, 0, sizeof(updateDust));
		
	spread();
	updateSP();
		
	//printMap();
	memset(updateDust, 0, sizeof(updateDust));
		
	airCleanerUp();
	airCleanerDown();
	updateAC();
	//printMap();	
}


int main(){
	input();
	for(int i=0; i<T; i++){
		run();
	}
	
	cout << getResult()<<'\n';
	
	return 0;
}
