#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M, K, high, ret = INT_MAX;
ll jam[300004] = {0,};


bool check(int mid){
	ll num = 0;
	
	for(int i=0; i<M; i++){
		num += jam[i]/mid;
		if(jam[i]%mid) num++;
	}
	
	return N >= num;
} 
// mid = 나눠주는 보석의 수, num = 받는 학생의 수 
// mid가 작아질수록  num이 커짐 
// num이 N 이하일 경우 mid를 감소시키면서 최적의 값 탐색 

void run(){
	cin >> N >> M;
	
	ll low = 1, high = 0, mid;
	
	for(int i=0; i<M; i++){
		cin >> jam[i];
		high = max(jam[i], high);
	}
	
	while(low<=high){
		mid = (low+high)/2;
		
		
		if(check(mid)){
			ret = min(ret, mid); 
			high = mid-1;
		}
		else{
			low = mid+1; // num이 N을 초과한 경우, mid를 증가시키면서 최적의 값을 탐색 
			}
	}
	
	cout << ret;
	
	return ;
}


int main(){
	run();
	return 0;
}
