#include<bits/stdc++.h>

using namespace std;


int N, ret = 0, maxTime = 0;

vector<int> vecRet;
vector<pair<int,int>> ramen;
priority_queue<int, vector<int>, greater<int>> pq;

bool sortFlag(pair<int,int> cup1, pair<int,int> cup2){
	if(cup1.second != cup2.second){
		return cup1.second < cup2.second;
	}
	else{
		return cup1.first > cup2.first;
	}
}


void run(){
	int deadline, cup;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> deadline >> cup;
		
		ramen.push_back({cup, deadline});
	}
	
	sort(ramen.begin(), ramen.end(), sortFlag);
	
	for(int i=0; i<ramen.size(); i++){
		pq.push(ramen[i].first);
		if(pq.size() > ramen[i].second)
			pq.pop();
	}
	
	while(!pq.empty()){
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret;
}

int main(){
	run();
	return 0;
}
