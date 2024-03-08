#include<bits/stdc++.h>

using namespace std;

int N, K, ret = 0;

int DP[100004] = {0,};
int cnt[100004] = {0,};
// 0 걷기
// 1 순간이동 
vector<int> moveTo = {1, -1, 0}; 
vector<int> result;

void updateDP(int now, int next){
	if(DP[next] == -1) DP[next] = DP[now]+1;
	else			   DP[next] = min(DP[next], DP[now]+1);
}

void move(){	
	queue<int> quePath;
	quePath.push(N);
	
	int time = 0;
	DP[N] = 1; // 거리 DP 
	cnt[N] = 1; // 경우의수 DP 
	
	
	while(!quePath.empty()){
		int now = quePath.front();
										
		for(int i=0; i<moveTo.size(); i++){ // for(int next: {now+1, now-1, now*2})
			int next = now + moveTo.at(i);	
			if(next == now) next = now*2;
			
			if(next < 0 || next > 100000) continue; // 범위 설정 
			
			if(DP[next] == 0){
				DP[next] = DP[now] + 1;
				cnt[next] += cnt[now];
				quePath.push(next);
			} 
			else if(DP[next] == DP[now]+1){
				cnt[next] += cnt[now];
			}
		}
		
		quePath.pop();
		
	}
	
	return;
}

void run(){
	cin >> N >> K;
	
	move();
	
	cout << DP[K]-1 << '\n';
	cout << cnt[K] << '\n';
}

int main(){
	run();
	return 0;
}
