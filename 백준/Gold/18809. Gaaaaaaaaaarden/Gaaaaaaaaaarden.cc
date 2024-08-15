#include<bits/stdc++.h>
#define MAX 50

using namespace std;

int initG  [MAX][MAX] = {0,};
int garden [MAX][MAX] = {0,};
int visited[MAX][MAX] = {0,};

int ret = 0;


vector<vector<int>> moveTo = {
	{0, 1}, { 1,0},
	{0,-1}, {-1,0}
}; 

vector<pair<int,int>> spot;
vector<pair<int,int>> choose;

int N, M, G, R;

// 호수 = 0, 빈칸 = 1, 황토 = 2 
// G = 3, R = 4, flower = 5

void print(){
	cout << "garden" << "\n"; 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << garden[i][j] << " ";
		}
		cout << endl;
	}
	
	
//	cout << "season" << "\n";
//	
//	for(int i=0; i<N; i++){
//		for(int j=0; j<M; j++){
//			cout << visited[i][j] << " ";
//		}
//		cout << endl;
//	}
}

bool rangeCheck(int y, int x){
	return 0 <= y && y < N && 0 <= x && x < M;
}


void spread(){
	queue<pair<int,int>> step;
	
	for(pair<int,int> dot: choose){
		step.push(dot);
	}
	
	while(!step.empty()){
		pair<int,int> now = step.front();
		step.pop();
		
		int col    = garden [now.first][now.second];
		int season = visited[now.first][now.second]+1;
		if(col == 5) continue;
						
		for(int i=0; i<moveTo.size(); i++){
			int nextY = now.first  + moveTo[i][0];
			int nextX = now.second + moveTo[i][1];
			
			if(!rangeCheck(nextY, nextX)) continue;
			if(garden[nextY][nextX] == 0) continue;	
			
			if(visited[nextY][nextX] > 0 
			&& visited[nextY][nextX] < season) continue;
			
			if(garden[nextY][nextX] == col) continue;
			if(garden[nextY][nextX] ==   5) continue;
			
			if(visited[nextY][nextX] == season
			&& ((garden[nextY][nextX] == 3 && col == 4)
			||   garden[nextY][nextX] == 4 && col == 3)){	
				
				garden[nextY][nextX] = 5;
				continue;
			}
			
					
			garden[nextY][nextX] = col;
			visited[nextY][nextX] = season;
			step.push({nextY,nextX});
		}
	}
	
	return ;
}

void update(int here[MAX][MAX], int there[MAX][MAX]){

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			here[i][j] = there[i][j];
		}
	}
}

int getFlowers(){
	int cnt = 0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cnt += (garden[i][j] == 5);
		}
	}
	
	return cnt;
}

void turn(int mask){	
	memset(visited, 0, sizeof(visited));
	update(garden, initG);
	
	for(int i=0; i<choose.size(); i++){
		int y = choose[i].first;
		int x = choose[i].second;
		
		visited[y][x] = 1;
		
		if(mask & (1 << i)) garden[y][x] = 4;
		else				garden[y][x] = 3;
	}
	
	
	spread();
		
	ret = max(ret, getFlowers());
}

int popcount(int mask){
	int cnt = 0;
	
	while(mask > 0){
		if(mask & 1) cnt += 1;
		mask = mask >> 1;
	}
	
	return cnt;
}

void pickUp(int start){
	if(choose.size() == G+R){		
		int cnt = G+R;
		for(int mask = 1; mask < (1 << cnt); mask++){
			if(popcount(mask) == R){
				turn(mask);
			}
		}
	
		return;
	}
	
	for(int i=start; i<spot.size(); i++){
		choose.push_back(spot[i]);
		pickUp(i+1);
		choose.pop_back();
	}
}

int main(){
	cin >> N >> M >> G >> R;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> initG[i][j];
			if(initG[i][j] == 2)
				spot.push_back({i,j});
		}
	}
	
	pickUp(0);
	
	cout << ret;	
	
	
	return 0;
}