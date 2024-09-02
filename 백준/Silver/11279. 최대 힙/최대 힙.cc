#include<bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(0);cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int N, input;
	
	priority_queue<int> pq;
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> input;
		
		if(input == 0){
			
			if(pq.empty()){
				cout << 0 << "\n";
				continue;
			}
			
			cout << pq.top() << "\n";
			pq.pop();
			continue;
		}
		
		pq.push(input);
	}
	
	return 0;
}