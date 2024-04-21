#include<bits/stdc++.h>

using namespace std;

int N, ret = INT_MAX;
int Map[14][14];
int visited[14][14] = {0,};


vector<int> pot;
vector<pair<int,int>> flower{
	{1, 0}, {0, 1},
	{-1,0}, {0,-1}
};


bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

void input(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> Map[i][j];
		}
	}	
}

bool flowerCheck(int y, int x){
	
	if(visited[y][x]) return false;
	
	for(int i=0; i<flower.size(); i++){
		int nextY = y + flower.at(i).first;
		int nextX = x + flower.at(i).second;
		
		if(!rangeCheck(nextY, nextX)) return false;
		if(visited[nextY][nextX]) return false;
	}
	
	return true;
}

int blossom(int y, int x){
	int i, cost = 0;
	
	cost += Map[y][x];
	visited[y][x] = 1;
	
	for(i=0; i<flower.size(); i++){
		int nextY = y + flower.at(i).first;
		int nextX = x + flower.at(i).second;
		
		cost += Map[nextY][nextX];
		visited[nextY][nextX] = 1;
	}
	
	return cost;
}

void sear(int y, int x){
	visited[y][x] = 0;
	
	for(int i=0; i<flower.size(); i++){
		int nextY = y + flower.at(i).first;
		int nextX = x + flower.at(i).second;
		
		visited[nextY][nextX] = 0;
	}
	
	pot.pop_back();
}

void printVisited(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << visited[i][j] << ' '; 
		}
		cout << '\n';
	}
	cout << '\n';
}

void pickUp(int cnt, int sum){
	
	if(cnt == 3){		
		ret = min(ret, sum);
		return;
	}

	for(int i=0; i<N;i++){
		for(int j=0; j<N; j++){
			if(flowerCheck(i, j)){	
				pickUp(cnt+1, sum + blossom(i,j));	
				sear(i, j);
			}
		}
	}	
}

void output(){
	cout << ret;
}

void run(){
	input();
	pickUp(0, 0);
	output();
}	


int main(){
	run();
	return 0;
}
