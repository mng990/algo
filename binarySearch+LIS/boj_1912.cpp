#include<bits/stdc++.h>

using namespace std;

int N, sum = 0, ret = INT_MIN;

void run(){
	cin >> N;
	
	for(int i=1; i<=N; i++){
		int num;
		cin >> num;
		sum += num;
		ret = max(ret, sum); // 순차적으로 더해가며 ret을 매번 업데이트 
		if(sum < 0) sum = 0; // 구간합이 음수인 경우 초기화 
	}
	
	cout << ret;
}




int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
