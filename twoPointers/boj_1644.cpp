#include<bits/stdc++.h>

using namespace std;

int N, ret = 0, pidx = 0, low = 0, high = 0, sum = 0;
int che[4000004] = {0,};
int prime[4000004] = {0,};


void era(int maxNum){
	for(int i=2; i <= maxNum; i++){
		if(che[i]) continue;
		
		for(int j = 2*i; j<=maxNum; j+=i){
			che[j] = 1;
		} // i의 배수들은 소수가 아니므로 모두 1로 표시 
	} // che[i]  == 0이라면 소수 
}

void run(){
	cin >> N;
	
	if(N == 1){
		cout << 0;
		return;
	}

	era(N);
	
	for(int i=2; i<=N; i++){
		if(!che[i]) prime[pidx++] = i;
	}
	
	while(true){
		if(sum >= N) sum -= prime[low++]; // 구간합이 N보다 크다면 low 증가(구간합 감소) 
		else if(high == pidx) break; // high가 0에서 출발해 끝점에 도달하면 break 
		else sum += prime[high++]; // 구간합이 N보다 작다면 high 증가(구간합 증가) 
		if(sum == N) ret++; // 구간합이 N과 같다면 ret++ 
	}
	
	cout << ret;
	
}

int main(){
	run();
	return 0;
}
