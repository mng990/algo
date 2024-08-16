#include<bits/stdc++.h>

using namespace std;
using ll = long long;


ll N, ret = 0;
vector<vector<ll>> arr(4);
vector<ll> front, back;

int main(){
	cin >> N;	
	for(auto& sub: arr){
		sub.resize(N);
	}
	
	for(int i=0; i<N; i++){
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
	}
	
	for(auto& sub:arr){
		sort(sub.begin(), sub.end());
	}
	
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			ll half = arr[0][i] + arr[1][j];
			front.push_back(half);
		}
	}
	sort(front.begin(), front.end());
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			ll half = arr[2][i] + arr[3][j];
			back.push_back(half);
		}
	}
	
	sort(back.begin(), back.end());
	
	for(auto sum: front){
		ret += upper_bound(back.begin(), back.end(), -sum) 
			 - lower_bound(back.begin(), back.end(), -sum);
	}
	
	cout << ret;
	
	
	return 0;
}