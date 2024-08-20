#include<bits/stdc++.h>
#define MAX 20
using namespace std;
using pii = pair<int,int>;

int R, C, ret = 1;

bool rangeCheck(int y, int x){
	return 0 <= y && y < R && 0 <= x && x < C;
}
vector<pii> moveTo = {
	{0, 1}, {1, 0},
	{-1,0}, {0,-1}
};


vector<int> dic(26, 0);
char arr[20][20] = {0,};

void DFS(int nowY, int nowX, int cnt){		
	bool block = true;
	
	int now = (int)(arr[nowY][nowX] - 'A');
	
	dic[now] = 1;
	
	for(auto m: moveTo){
		int y = nowY + m.first;
		int x = nowX + m.second;
				
		if(!rangeCheck(y, x)) continue;
		
		int next = (int)(arr[y][x] - 'A');
		if(dic[next]) continue;
	
		DFS(y, x, cnt+1);
		block = false;
	}
	
	if(block){
		ret = max(ret, cnt);
	}
	
	dic[now] = 0;
	
	return ;
}



int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> R >> C;
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> arr[i][j];
		}
	}
	
	DFS(0,0,1);
	
	cout << ret << "\n";
	
	
	return 0;
}