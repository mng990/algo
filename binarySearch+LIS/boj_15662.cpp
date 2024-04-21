#include<bits/stdc++.h>

using namespace std;

int N, K, boundMask = (1<<8)-1, ret = 0;

int rMap[1000] = {0,};


vector<int> vecG;
vector<pair<int,int>> vecR;



int strToBi(string gear){
	int biGear = 0;
	
	for(int i=0; i<LENG; i++){
		biGear = biGear | ((gear[i] - '0') << (LENG - (i+1)));
	}
		
	return biGear;
}

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		string gear;
		cin >> gear;
		
		vecG.push_back(strToBi(gear));
	}
	
	cin >> K;
	for(int i=0; i<K; i++){
		pair<int,int> rotate;
		
		cin >> rotate.first >> rotate.second;
		vecR.push_back(rotate);
	}
}


int clockWise(int gidx){
	int nowG = vecG[gidx];
	int tail = nowG & 1; // head = 7, tail = 0
	// 3시 방향 = gear & (1<<5), 9시 방향 = gear & (1<<1)
	
	
	nowG = ((nowG >> 1) | (tail << 7)) & boundMask;
	
	return nowG;
	
}// left = gear & (1<<1), right = gear & (1<<5), up = gear & (1<<7)

int counterCW(int gidx){
	int nowG = vecG[gidx];
	// 3시 방향 = gear & (1<<1), 9시 방향 = gear & (1<<5)
	int head = ((vecG[gidx] & (1<<7)) >> 7);

	nowG = ((nowG << 1) | head) & boundMask;
	
	return nowG;
}



int doRotate(int gidx, int rflag){
	if(rflag == 1){
		return clockWise(gidx);
	}
	else{
		return counterCW(gidx);
	}
}


void makeRMap(int gidx, int rFlag){
	int nowG = vecG[gidx];
	int tail = nowG & (1<<0); // head = 7, tail = 0
	int three = ((nowG & (1<<5)) >>5) & boundMask;
	int nine  = ((nowG & (1<<1)) >>1) & boundMask; 
	
	rMap[gidx] = rFlag;
	
	if(gidx-1 >= 0){
		int nextLT = ((vecG[gidx-1]&(1<<5)) >> 5) & boundMask;
		
		if(nextLT != nine && rMap[gidx-1] == 0){
			makeRMap(gidx-1, -rFlag);
		}
	}
	
	if(gidx+1 < vecG.size() && rMap[gidx+1] == 0){
		int nextRN = ((vecG[gidx+1]&(1<<1)) >> 1)& boundMask;
		
		if(nextRN != three){	
			makeRMap(gidx+1, -rFlag);
		}
	}
}

void rotate(int rIdx){
	memset(rMap, 0, sizeof(rMap));
	
	int gIdx  = vecR[rIdx].first-1;
	int rFlag = vecR[rIdx].second;
	
	makeRMap(gIdx, rFlag);
	
	for(int i=0; i<vecG.size(); i++){
		if(rMap[i] != 0){
			vecG[i] = doRotate(i, rMap[i]);
		}
	}
	
	return ;
}

void getCnt(){
	for(int i=0; i<vecG.size(); i++){
		if(vecG[i] & (1<<7)){
			ret++;
		}
	}
}

void output(){
	cout << ret;
}

void run(){
	input();
	for(int i=0; i<vecR.size(); i++){
		rotate(i);
	}
	getCnt();
	output();	
}


int main(){
	run();
	return 0;
}
