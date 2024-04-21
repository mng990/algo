#include<bits/stdc++.h>
#define NUT 4
#define FNUT 5

using namespace std;

int nowNut[4];
int minNut[4]; //minP, minF, minS, minV;
int food[16][5];

int nowEat = 1;
int N, ret = INT_MAX, nowPrice = 0;

vector<string> result;

void input(){
	cin >> N;
	
	nowEat = (nowEat<<N) - 1;
	
	for(int i=0;i<NUT;i++)
		cin >> minNut[i];
		
	for(int i=1; i <= N; i++){
		for(int j=0; j<FNUT; j++){
			cin >> food[i][j];
		}
	}
	
	
}

int nutCheck(){
	for(int i=0; i<NUT; i++){
		if(minNut[i] > nowNut[i]) return false;
	}
	
	return true;
}

string translate(int mask){
	string str = "";
	
	for(int i=0; i<N; i++){
		if(mask & (1<<i)){
			str += to_string(i+1) + ' ';
		}
	}
	
	return str;	
}

void update(int nowMask){
	if(!nutCheck()) return;
	
	
	
	if(ret > nowPrice){
		ret = nowPrice;
		result.clear();
		result.push_back(translate(nowMask));
	}
	if(ret == nowPrice){
		result.push_back(translate(nowMask));
	}
}


void eat(int fidx){
	for(int i=0; i<NUT; i++){
		nowNut[i] += food[fidx][i];
	}
	nowPrice += food[fidx][NUT];
}



void eatAll(int mask){
	for(int i=0; i < N; i++){
		if(mask & (1<<i)){
			eat(i+1);
		}
	}
}


void combi(){
	for(int mask=0; mask < (1 << N); mask++){
		nowPrice = 0;
		memset(nowNut, 0, sizeof(nowNut));
		
		eatAll(mask);
		update(mask);
	}
}

void output(){
	if(result.empty()){
		cout << -1 << '\n';
		return;
	} 
	
	sort(result.begin(), result.end());
	
	cout << ret << '\n';
	cout << result.at(0);

	
}

void run(){
	input();
	combi();
	output();
}


int main(){
	run();
	return 0;
}
