#include<bits/stdc++.h>

using namespace std;

int N, K, ret = 0;

int DP[100004] = {0,};
// 0 걷기
// 1 순간이동 
vector<int> moveTo = {1, -1, 0}; 
vector<int> result;
stack<int> path;

void move(){	
	queue<int> quePath;
	quePath.push(N);
	
	int time = 0;
	DP[N] = 1; // 거리 DP 
	
	
	while(!quePath.empty()){
		int now = quePath.front();
										
		for(int i=0; i<moveTo.size(); i++){ // for(int next: {now+1, now-1, now*2})
			int next = now + moveTo.at(i);	
			if(next == now) next = now*2;
			
			if(next < 0 || next > 100000) continue; // 범위 설정 
			if(DP[next]) continue;
			
		
			DP[next] = DP[now] + 1;
			
			if(next == K) return;
			quePath.push(next); 
		}
		
		quePath.pop();
		
	}
	
	return;
}

void lis(){
	int time = DP[K];
	int prev=K;
	path.push(K);
	time--;
	
	for(int i=K+1; i>=0; i--){
		if(time == 0) break; 

		if(DP[i] == time){
			
			if(i == prev+1 || i == prev/2 || i == prev-1){
				path.push(i);
				time--;
				prev = i;
				i += 2;
			}
		}
		
	}
	
	while(!path.empty()){
		int top = path.top();
		cout << top << " ";
		path.pop();
	}
}

void run(){
	cin >> N >> K;
	
	move();
	
	cout << DP[K]-1 << '\n';
	lis();
}

int main(){
	run();
	return 0;
}
