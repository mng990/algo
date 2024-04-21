#include<bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>> elec;
vector<pair<int,int>> lis;


bool sortFlag(pair<int,int> elec1, pair<int,int> elec2){
	return elec1.second < elec2.second;
}

void input(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		pair<int,int> e;
		cin >> e.second >> e.first;
		elec.push_back(e);
	}
	
	sort(elec.begin(), elec.end(), sortFlag);
}

void makeLIS(){
	for(int i=0; i<N; i++){
		int lidx = lower_bound(lis.begin(), lis.end(), elec[i]) - lis.begin();
		
		if(lidx >= lis.size()){
			lis.push_back(elec[i]);
		}
		else{
			lis[lidx] = elec[i];
		}
	}
}

void output(){
	cout << elec.size() - lis.size() << "\n";
}

void run(){
	input();
	makeLIS();
	output();
}

int main(){
	run();
	return 0;
}
