#include<bits/stdc++.h>

using namespace std;

int N, num;

int main(){	
	cin.tie(0);cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> num;
			pq.push(num);
			if(pq.size() > N) pq.pop();
		}
	}
	
	cout << pq.top();
	
	return 0;
}