#include<bits/stdc++.h>
#define NUT 4
#define FNUT 5

using namespace std;

int N, ret = INT_MAX, nowPrice = 0;
int nowNut[4];
int minNut[4]; //minP, minF, minS, minV;
int food[16][5];

vector<int> nowEat;
vector<vector<int>> result;


void input(){
	cin >> N;
	
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

void eat(int fidx){
	for(int i=0; i<NUT; i++){
		nowNut[i] += food[fidx][i];
	}
	nowPrice += food[fidx][NUT];
}

void combi(int start, int size){
	if(nowEat.size() == size){
		nowPrice = 0;
		memset(nowNut, 0, sizeof(nowNut));
		
		for(int eidx=0; eidx<size; eidx++){
			int fidx = nowEat.at(eidx);
			eat(fidx);
		}
		
		if(nutCheck()){
			if(ret > nowPrice){
				ret = nowPrice;
				result.clear();
				result.push_back(nowEat);
			}
			if(ret == nowPrice) result.push_back(nowEat);
		}
		
		return;
	}
	
	for(int fidx=start; fidx<=N; fidx++){
		nowEat.push_back(fidx);
		combi(fidx+1, size);
		nowEat.pop_back();
	}
}

void output(){
	if(result.empty()){
		cout << -1 << '\n';
		return;
	} 
	
	sort(result.begin(), result.end());
	
	cout << ret << '\n';
	for(int i=0; i<result[0].size(); i++){
		cout << result[0][i] << ' ';
	}
}

void run(){
	input();
	for(int size=1; size<=N; size++)
		combi(1,size);
	output();
}


int main(){
	run();
	return 0;
}
