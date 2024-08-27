#include <bits/stdc++.h>

using namespace std;

int N, packet;

int main(){
	cin >> N;
	queue<int> router;
	
	while(true){
		cin >> packet;
		if(packet == -1) break;

		if(packet == 0){
			router.pop();
			continue;
		}
		
		if(router.size() == N) continue;
		
		router.push(packet);	
	}
	
	if(router.empty()) cout << "emtpy";
	
	while(!router.empty()) {
		cout << router.front() << " ";
		router.pop(); 
	}
	
	return 0;
}