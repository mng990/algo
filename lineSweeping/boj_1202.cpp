#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, K, ret = 0;
ll visited[300004] = {0,};

vector<ll> bag;
vector<pair<ll,ll>> jewelry;
priority_queue<ll> pq; // val


void run(){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		ll weight, value;
		cin >> weight >> value;
		
		jewelry.push_back({weight, value});
	}
	
	sort(jewelry.begin(), jewelry.end());
	
	for(int i=0; i<K; i++){
		ll limit;
		cin >> limit;
		bag.push_back(limit);
	}
	
	sort(bag.begin(), bag.end());
	
	
	
	int j=0;
	
	for(int i=0; i<bag.size(); i++){
		
		while(j < N && jewelry[j].first <= bag[i]) 
			pq.push(jewelry[j++].second);
		
		if(!pq.empty()){
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret << "\n";
}


int main(){
	run();
	return 0;
}
