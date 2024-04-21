#include<bits/stdc++.h>

using namespace std;


int R, C;
char Map[24][24];
int mask = 0, ret = INT_MIN;

vector<pair<int,int>> moveTo = {
	{1, 0}, {0,1},
	{-1,0}, {0,-1}
};

void input(){
	cin >> R >> C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> Map[i][j];
		}
	}
}

bool rangeCheck(int y, int x){
	return 0<=y && y<R && 0<=x && x<C;
}

int DFS(int nowY, int nowX, int cnt){
	bool blocked = true;
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = nowY + moveTo.at(i).first;
		int nextX = nowX + moveTo.at(i).second;
		
		if(!rangeCheck(nextY, nextX)) continue;	
		int nextAlpha = 1 << (Map[nextY][nextX]-'A');
		if(mask & nextAlpha) continue;
		
		mask |= nextAlpha;
		DFS(nextY, nextX, cnt+1);
		mask ^= nextAlpha;
		blocked = false;
	}	
	
	if(blocked){
		ret = max(ret, cnt);
	} 
	
	return cnt;
}

int main(){
	input();
	mask = 1 << (Map[0][0]-'A');
	DFS(0,0,1);
	cout << ret;
	
	return 0;
}
