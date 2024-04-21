#include<bits/stdc++.h>

using namespace std;

int N, ret;
vector<int> vec;

void input(){
	cin >> N;
	
	for(int i=0;i<N; i++){
		int data;
		cin >> data;
		vec.push_back(data);
	}
}

int maxMOD11(int idx, int sum){
	if(ret == 10) return; 
	// backTracking: 이미 최대값인 10을 구한 상태라 더이상 탐색 X 
	if(idx == N){
		ret = max(ret, sum%11);
		return ret;
	}
	maxMOD11(idx+1, sum+vec[idx])%11;
	maxMOD11(idx+1, sum)%11;
	
	return ret;
}

void run(){
	input();
	cout << maxMOD11(0, 0) << '\n';
}

int main(){
	run();
	return 0;
}
