#include<bits/stdc++.h>

using namespace std;

int N, M, space = 0, ret = INT_MAX;
int Map[9][9] = {0,};
int watchMap[9][9] = {0,};


vector<int> vecDir;
vector<pair<int,int>> vecCCTV;
vector<pair<int,int>> moveTo = {
	{-1,0}, {0, 1},
	{ 1,0}, {0,-1}
};

bool rangeCheck(pair<int,int> dot){
	return 0<=dot.first && dot.first < N && 0<=dot.second && dot.second < M;
}

void setWatch(pair<int,int> watch, int dir){
	
	while(true){
		watch.first  += moveTo[dir].first;
		watch.second += moveTo[dir].second;
		
		if(!rangeCheck(watch)) break;
		if(Map[watch.first][watch.second] == 6) break;
		
		if(watchMap[watch.first][watch.second] == 0)
			watchMap[watch.first][watch.second] = -1;
	}		
}

void cctv1(pair<int,int> cctv, int dir){
	setWatch(cctv, dir);
	return ;
}

void cctv2(pair<int,int> cctv, int dir){
	
	if(dir == 0){
		setWatch(cctv, 0);
		setWatch(cctv, 2);
	}
	else{
		setWatch(cctv, 1);
		setWatch(cctv, 3);
	}
	
	return;
}

void cctv3(pair<int,int> cctv, int dir){
	setWatch(cctv, dir);
	setWatch(cctv, (dir+1)%4);
}

void cctv4(pair<int,int> cctv, int dir){
	for(int i=0; i<moveTo.size(); i++){
		if(i == dir) continue;
		setWatch(cctv, i);
	}
}

void cctv5(pair<int,int> cctv){
	for(int i=0; i<moveTo.size(); i++){
		setWatch(cctv, i);
	}
}

void setCCTV(pair<int,int> cctv, int dir){
	int type = Map[cctv.first][cctv.second];
	
	switch(type){
	case 1:
		cctv1(cctv, dir);
		break;
	case 2:
		cctv2(cctv, dir);
		break;
	case 3:
		cctv3(cctv, dir);
		break;
	case 4:
		 cctv4(cctv, dir);
		 break;
	case 5:
		cctv5(cctv);
		break;		
	}
}

void update(){
	int cnt = 0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(watchMap[i][j] == 0){
				cnt++;
			}
		}
	}
	
	ret = min(ret, cnt);
}

void turnOn(){
	if(vecDir.size() == vecCCTV.size()){
		memcpy(watchMap, Map, sizeof(Map));
		for(int i=0; i<vecCCTV.size(); i++){
			setCCTV(vecCCTV[i],vecDir[i]);
		}
		update();
		
		return;
	}
	
	
	for(int dir=0; dir<moveTo.size(); dir++){
		vecDir.push_back(dir);
		turnOn();
		vecDir.pop_back();
	}
}

void input(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> Map[i][j];
			if(1 <= Map[i][j] && Map[i][j] <= 5){
				vecCCTV.push_back({i,j});
			}
		}
	}
}

int main(){
	input();
	turnOn();
	cout << ret << "\n";
	return 0;
} 
