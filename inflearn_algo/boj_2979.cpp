#include<bits/stdc++.h>
#define LEN 3

using namespace std;

vector<int> cost;
vector<pair<int,int>> parking;
int lastTime = -1, startTime = INT_MAX, ans = 0;
int parkingLot[100] = {0,};

void input(){
	cost.push_back(0);
	for(int i=1; i<=LEN; i++){
		int cst;
		cin >> cst;
		cost.push_back(cst*i);
	}
	
	for(int i=0; i<LEN; i++){
		int start, end;
		cin >> start >> end;
		pair<int,int> park(start, end);
		parking.push_back(park);
		
		startTime = min(startTime, start);
		lastTime = max(lastTime, end);
	}
	
}

void calCost(){
	for(int i=startTime; i<lastTime; i++){
		ans += cost.at(parkingLot[i]);
	}
}

void park(){
	for(int i=0; i<parking.size(); i++){
		int start = parking.at(i).first;
		int end   = parking.at(i).second;
		
		for(int i=start; i<end; i++){
			parkingLot[i] += 1;
		}
	}
	
	calCost();
}


void output(){
	cout << ans << endl;
}

void run(){
	input();
	park();
	output();
}

int main(){
	run();
	return 0;
}
