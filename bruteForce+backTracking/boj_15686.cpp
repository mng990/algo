#include<bits/stdc++.h>

using namespace std;

int N, M, minChicken = INT_MAX;
int chickenMap[54][54];
int visited[54][54]={0,};


vector<pair<int, int>> chicken; // 치킨거리 
vector<pair<int,int>> house;
vector<int> arrive;

void input(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> chickenMap[i][j];
			if(chickenMap[i][j] == 1)
				house.push_back(make_pair(i, j));
			if(chickenMap[i][j] == 2)
				chicken.push_back(make_pair(i,j));
		}
	}	
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

int getChickenDist(){
	int ret = 0;

	for(int i=0; i<house.size(); i++){
		int houseY = house.at(i).first;
		int houseX = house.at(i).second;
		int chickenDist = INT_MAX;
		
		for(int aidx = 0; aidx < arrive.size(); aidx++){
			int cidx = arrive.at(aidx);
			
			pair<int, int> nowChicken = chicken.at(cidx);
			int nowDist = abs(nowChicken.first - houseY) 
							+ abs(nowChicken.second - houseX);
		
			chickenDist = min(chickenDist, nowDist);
		}
		
		ret += chickenDist;
	}
	
	return ret;
}

void pickUp(int start){
	if(arrive.size() == M){
		int sum = getChickenDist();
		
		minChicken = min(sum, minChicken);
		return;
	}
	
	for(int i=start+1; i<chicken.size(); i++){
		arrive.push_back(i);
		pickUp(i);
		arrive.pop_back();
	}
}

void run(){
	input();	
	pickUp(-1);
	cout << minChicken;
}

int main(){
	run();
	return 0;
}
