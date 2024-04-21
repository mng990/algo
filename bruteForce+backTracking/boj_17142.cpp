#include <bits/stdc++.h>

using namespace std;

int Map[54][54];
int visited[54][54] = {0,};
bool check[54][54] = {0,};
int N, M, ret = INT_MAX, wallSize=0, blank = 0;


vector<int> able;
queue<pair<int,int>> quePath;

vector<pair<int,int>> virus;
vector<pair<int,int>> moveTo = {
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};

void input(){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> Map[i][j];
			
			if(Map[i][j] == 0) blank++;
			if(Map[i][j] == 2){
				virus.push_back(make_pair(i,j));
			}
			
		}
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

void BFS(){ // start´Â virus Áß 1 
	int cnt = 0, maxCost = 0;
	bool pass = false;
	
	
	for(auto v: virus){
		int virusY = v.first, virusX = v.second;
		
		if(Map[virusY][virusX] != 2){
			quePath.push(make_pair(virusY, virusX));
			visited[virusY][virusX] = 1;
		}
	}
	
		while(!quePath.empty()){
			pair<int,int> now = quePath.front();
			int nowY = now.first;
			int nowX = now.second;		
			
			for(int i=0; i < moveTo.size(); i++){
				int nextY = nowY + moveTo.at(i).first;
				int nextX = nowX + moveTo.at(i).second;
				
				if(!rangeCheck(nextY, nextX)) continue;
				if(Map[nextY][nextX] == 1) continue;
				
				
				if(visited[nextY][nextX] == 0){
					quePath.push(make_pair(nextY, nextX));
					visited[nextY][nextX] = visited[nowY][nowX]+1;	
					
					if(Map[nextY][nextX] == 0){
						cnt++;
					}
					if(cnt == blank){
						ret = min(ret, visited[nextY][nextX]-1);	
					}
				}		
			}
			
			
			quePath.pop();
		}
		
	
	
	
	return ;
}

void abled(int start, int size){
	if(size == M){
		memset(check, 0, sizeof(check));
		memset(visited, 0, sizeof(visited));
		BFS(); 
		return;
	}
	
	for(int i=start+1; i<virus.size(); i++){
		pair<int,int> dVirus = virus.at(i);
		Map[dVirus.first][dVirus.second] = 3;
		abled(i, size+1);
		Map[dVirus.first][dVirus.second] = 2;
	}
	
	return ;
}

void output(){
	if(ret == INT_MAX) ret = -1;
	cout << ret;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	input();
	if(blank == 0){
		cout << 0 << endl;
		return 0;
	}
	abled(-1,0);
	output();
	return 0;
}
