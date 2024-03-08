#include<bits/stdc++.h>

using namespace std;

int R,C, ret = 1;

vector<pair<int,int>> moveTo ={
	{0,1}, {0,-1},
	{1,0}, {-1,0}
};

map<char,int> check;
int visitedAlpha[26] = {0,};
int visited[24][24] = {0,};
char Map[24][24];


bool rangeCheck(int y, int x){
	return 0<=y && y<R && 0<=x && x<C;
}


void DFSSample(int nowY, int nowX, int len){
	ret = max(ret, len);
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = nowY + moveTo.at(i).first;
		int nextX = nowX + moveTo.at(i).second;
		int nextAlpha = Map[nextY][nextX] - 'A';
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(visitedAlpha[nextAlpha]) continue;
		if(check[Map[nextY][nextX]]) continue;
		
		visitedAlpha[nextAlpha] = 1;
		DFSSample(nextY,nextX,len+1);
		visitedAlpha[nextAlpha] = 0;
	}
}

void DFS(int nowY, int nowX){

	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = nowY + moveTo.at(i).first;
		int nextX = nowX + moveTo.at(i).second;
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(visited[nextY][nextX]) continue;
		if(check[Map[nextY][nextX]]) continue;
		
		visited[nextY][nextX] = visited[nowY][nowX]+1;
		check[Map[nextY][nextX]] = 1;
		ret = max(ret, visited[nextY][nextX]);
		DFS(nextY,nextX);
		visited[nextY][nextX] = 0;
		check[Map[nextY][nextX]] = 0;
	}
	
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	cin >> R >> C;
	
	for(int i=0; i<R; i++){
		string str;
		cin >> str;
		for(int j=0; j<str.size(); j++){
			Map[i][j] = str.at(j); 
		}
	}
	
	visitedAlpha[Map[0][0] - 'A'] = 1;
	DFSSample(0,0,1);
	

	
	cout << ret << endl;
	
	return 0;
}
