#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll N, road, maxRoad;
ll minCost = INT_MAX, minIdx = 0, ret = 0;
vector<ll> cost;
vector<ll> dist;

void run(){
	cin >> N;
	for(int i=0; i<N-1; i++){
		int d;
		cin >> d;
		dist.push_back(d);
		road += d;
		maxRoad = road;
	}
	
	for(int i=0; i<N-1; i++){
		int c;
		cin >> c;
		
		cost.push_back(c);

	}
	
	for(int i=0; i<N-1; i++){
		int nowDist = dist[i];
		int nowCost = cost[i];
		
		if(minCost > nowCost){
			minCost = nowCost;		
		}
		
		ret += minCost * nowDist;		
	}

	cout << ret;
}


int main(){
	run();
	return 0;
}
