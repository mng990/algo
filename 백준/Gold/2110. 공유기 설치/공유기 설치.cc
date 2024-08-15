#include<bits/stdc++.h>
#define MAX 10e9

using namespace std;
using ll = long long;

int N, C;

vector<ll> village;

ll binarySearch(){
	ll start = 0, end = MAX, ret = 0;
	
	while(start <= end){
		ll mid = (start+end)/2;
		
		int cnt = 1;
		ll right = village.front();
		
		for(int i=1; i < N; i++){
			if(village[i] - right >= mid){
				cnt++;
				right = village[i];
			}
		}

		if(cnt >= C){
			start = mid+1;
			ret = max(ret, mid);
			continue;
		}
		
		end = mid - 1;
	}
	
	return ret;
}

int main(){
	cin >> N >> C;
	
	village.resize(N);
	
	for(auto& h: village){
		cin >> h;
	}
	
	sort(village.begin(), village.end());
	
	cout << binarySearch();	
	return 0;
}