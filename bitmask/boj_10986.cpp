#include <bits/stdc++.h> 
#define ll long long

using namespace std;

ll arr[1000001], sum = 0;
ll DP[1000001] = {0,};
ll module[1000001] = {0,};


ll ret = 0;
int N, M;


void input(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> arr[i];
		
		arr[i] %= M;
		sum += arr[i];
		
		if(i == 0) DP[i] = arr[i];
		else	   DP[i] = (DP[i-1] + arr[i])%M;
		
		module[DP[i]]++;
	}
	
	ret += module[0];
}

void calCombi(){
	for(int i=0; i<M; i++){
		if(module[i] >= 2){
			ret += module[i]*(module[i]-1)/2; 
		} // nC2의 경우의 수를 식으로  계산해서 구함 
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	input();
	calCombi();
	cout << ret;
	
	return 0;
}
