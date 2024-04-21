#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll N, ret = 0, height;
stack<pair<ll,ll>> stk;

void run(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> height;
		int cnt = 1;
			
		while(!stk.empty() && stk.top().first <= height){
			ret += stk.top().second;
		
			if(stk.top().first == height){
				cnt = stk.top().second+1;
			}		
		
			stk.pop();
		}
		
		if(!stk.empty()) ret++;
		stk.push({height, cnt});
	}
	
	cout << ret;
}


int main(){
	run();
	return 0;
}
