#include<bits/stdc++.h>

using namespace std;

int N ,L, cnt = 0;

int Map[104][104];
int visited[4][104][104] = {0,};
vector<pair<int,int>> moveTo = {
	{1, 0}, {0, 1},
	{-1,0}, {0,-1}
};

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

bool setSlope(int startY, int startX, int dir){
	bool flag = true;
	
	int height = Map[startY][startX];
	for(int i=0; i<L; i++){
		int nowY = startY + moveTo.at(dir).first*i;
		int nowX = startX + moveTo.at(dir).second*i;
		
		
		if(dir%2 == 0){
			if(visited[0][nowY][nowX] || visited[2][nowY][nowX]){
				flag = false;
				break;
			}
		}
		if(dir%2 == 1){
			if(visited[1][nowY][nowX] || visited[3][nowY][nowX]){
				flag = false;
				break;
			}
		}
		
		if(!rangeCheck(nowY, nowX)){
			flag = false;
			break;
		} 
		
		
		if(Map[nowY][nowX] != height){
			flag = false;
			break;
		}
	}
	
	if(flag){
		for(int i=0; i<L; i++){
			int nowY = startY + moveTo.at(dir).first*i;
			int nowX = startX + moveTo.at(dir).second*i;
			visited[dir][nowY][nowX] = 1;	
		}
	}
	
	return flag;
} // dir = 0 -> row, dir = 1 -> col 

void bridge(){
	
	for(int j=0; j<N; j++){
		int i;
		for(i=0; i<N; i++){
			pair<int,int> down = moveTo.at(0);

			int downY = i+down.first, donwX = j+down.second;
			
			if(rangeCheck(downY, donwX)){
				if(Map[i][j] != Map[downY][donwX]){
					int gap = Map[i][j] - Map[downY][donwX];
					
					if(gap == 0) continue;
					else if(gap == 1){
						if(visited[0][downY][donwX]) continue;
						if(setSlope(downY, donwX, 0)) continue;
					}
					else if(gap == -1){
						if(visited[2][i][j]) continue;
						if(setSlope(i,j,2)) continue;
					}
					break;
				}
			}		
		}
		
		if(i==N){
			//cout << "col " << j << endl;
			cnt++;
		} 
	}
	
	for(int i=0; i<N; i++){
		int j;
		for(j=0; j<N; j++){
			pair<int,int> right = moveTo.at(1);
			pair<int,int> left = moveTo.at(3);
			int rightY = i+right.first, rightX = j+right.second;
			int leftY  = i+left.first , leftX  = j+left.second;
			
			if(rangeCheck(rightY, rightX)){
				if(Map[i][j] != Map[rightY][rightX]){
					int gap = Map[i][j] - Map[rightY][rightX];
					
					if(gap == 0) continue;
					
					else if(gap == 1){
						if(visited[1][rightY][rightX]) continue;
						if(setSlope(rightY, rightX, 1)) continue;
					}
					else if(gap == -1){
						if(visited[3][i][j]) continue;
						if(setSlope(i, j, 3)) continue;
					}
					break;
				}
			}		
		}
		
		if(j==N){
			//cout << "row " << i << endl;
			cnt++;
		} 
	}

	
}


void input(){
	cin >> N >> L;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> Map[i][j];
		}
	}
}

void printVisited(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}



int main(){
	input();
	bridge();
	cout << cnt << endl;
	//printVisited();
	return 0;
}
