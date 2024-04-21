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
		} // i�� ������� �Ҽ��� �ƴϹǷ� ��� 1�� ǥ�� 
	} // che[i]  == 0�̶�� �Ҽ� 
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
		if(sum >= N) sum -= prime[low++]; // �������� N���� ũ�ٸ� low ����(������ ����) 
		else if(high == pidx) break; // high�� 0���� ����� ������ �����ϸ� break 
		else sum += prime[high++]; // �������� N���� �۴ٸ� high ����(������ ����) 
		if(sum == N) ret++; // �������� N�� ���ٸ� ret++ 
	}
	
	cout << ret;
	
}

int main(){
	run();
	return 0;
}
