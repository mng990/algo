#include<bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int N, num;
stack<pii> stk;
vector<int> ans;

// num, index

int main(){
	cin >> N;
	ans.resize(N, -1);
	
	for(int i=0; i<N; i++){
		cin >> num;
		
		if(stk.empty()) {
			stk.push({num, i});
			continue;
		}
		
		while(!stk.empty() && stk.top().first < num){
			ans[stk.top().second] = num;
			stk.pop();
		}
		
		stk.push({num, i});
	}
	
	for(int i=0; i<N; i++)
		cout << ans[i] << " ";
		
	return 0;
}