#include<bits/stdc++.h>
#define MAX 10e18

using namespace std;
using ll = unsigned long long;

ll M, N, ret = MAX;
vector<ll> booth;

void binarySearch(){
	ll start = 1, end = MAX;
	
	while(start <= end){
		ll mid = (start+end)/2;
		ll bound = 0;
		
		for(auto b: booth){
			bound += mid/b;	
		}
		
		if(bound >= M){
			end = mid-1;
			ret = min(ret, mid);
			continue;
		}
		
		start = mid+1;
	}
}

int main(){
	cin >> N >> M;
	
	booth.resize(N);
	for(auto& t: booth) cin >> t;
	
	binarySearch();
	cout << ret;
	
	return 0;
}