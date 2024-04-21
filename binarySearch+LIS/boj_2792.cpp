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
// mid = �����ִ� ������ ��, num = �޴� �л��� �� 
// mid�� �۾�������  num�� Ŀ�� 
// num�� N ������ ��� mid�� ���ҽ�Ű�鼭 ������ �� Ž�� 

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
			low = mid+1; // num�� N�� �ʰ��� ���, mid�� ������Ű�鼭 ������ ���� Ž�� 
			}
	}
	
	cout << ret;
	
	return ;
}


int main(){
	run();
	return 0;
}
