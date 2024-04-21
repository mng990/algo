#include<bits/stdc++.h>
#define INF 9999999

using namespace std;

int N, DP[16][1<<16];
int weight[16][16] = {0,};

void input()
{	
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> weight[i][j];
		}
	}
	
	return ;
}

int travel(int mask, int from){
	// 이전에 기록해둔 값이 존재하면 바로 반환 
	if(DP[from][mask]){
		return DP[from][mask];
	}
	
	// 모든 곳을 순회했을 때 출발지로 돌아가는 비용을 더해 반환
	// 만약 출발지로 갈 수 없는 곳이라면 INF 반환 
	if(mask == (1<<N) - 1){
		if(weight[from][0] == 0){
			return DP[from][mask] = INF;
		}
		else{
			return DP[from][mask] + weight[from][0];
		}
	}
	
	// DP값을 INF로 초기화 
	DP[from][mask] = INF;
	
	for(int i=0; i<N; i++){
		// 도시들 중 mask에 기록된 도시 혹은 지나갈 수 없는 도시는 continue 
		if(mask & (1<<i) || weight[from][i] == 0) continue;
		
		// 다음 행선지로 이동
		// 모든 방문지를 순회 후  최소 비용을 기록 
		DP[from][mask] = 
			min(DP[from][mask], 
				travel(mask | (1<<i), i) + weight[from][i]);
	}
	
	return DP[from][mask];
}

void output(){
	cout << travel(1, 0);
}

void run()
{
	input();
	output();
}

int main(){
	run();
	return 0;
}
