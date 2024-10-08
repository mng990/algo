#include<bits/stdc++.h>

using namespace std;

int row, col, cnt;
int cheese[104][104];
int visited[104][104];
int air[104][104];
vector<pair<int,int>> vmelted;

vector<vector<int>> moveTo = {
	{0,1}, {0,-1},
	{1,0}, {-1,0}
};


bool rangeCheck(int y, int x){
	return 0<=y && y<row && 0<=x && x<col;
}

void airGun(int nowY, int nowX){
	air[nowY][nowX] = 1;
	if(cheese[nowY][nowX]){
		
		vmelted.push_back(make_pair(nowY, nowX));
		return;
	}
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = nowY + moveTo[i][0];
		int nextX = nowX + moveTo[i][1];
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(air[nextY][nextX]) continue;
		
		airGun(nextY, nextX);
	}
	
	return ;
}

bool isCheese(){
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++){
			if(cheese[i][j] > 0){
				return true;
			}
		}
	
	return false;
}


void run(){
	int hours = 1;
	cin >> row >> col;
	
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			cin >> cheese[i][j];
	
	while(true){
		int startY = 0, startX = 0;
		
		memset(&air[0][0], 0, sizeof(air));
		vmelted.clear();
		
		airGun(0,0);
		
		for(auto melted: vmelted){
			int meltedY  = melted.first;
			int meltedX  = melted.second;
			
			cheese[meltedY][meltedX] = 0;
		}			
		
		
		if(!isCheese()) break;
				
		hours++;
	}
	
	cout << hours <<'\n';
	cout << vmelted.size() << '\n';
}
	



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
}
