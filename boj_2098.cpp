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
	// ������ ����ص� ���� �����ϸ� �ٷ� ��ȯ 
	if(DP[from][mask]){
		return DP[from][mask];
	}
	
	// ��� ���� ��ȸ���� �� ������� ���ư��� ����� ���� ��ȯ
	// ���� ������� �� �� ���� ���̶�� INF ��ȯ 
	if(mask == (1<<N) - 1){
		if(weight[from][0] == 0){
			return DP[from][mask] = INF;
		}
		else{
			return DP[from][mask] + weight[from][0];
		}
	}
	
	// DP���� INF�� �ʱ�ȭ 
	DP[from][mask] = INF;
	
	for(int i=0; i<N; i++){
		// ���õ� �� mask�� ��ϵ� ���� Ȥ�� ������ �� ���� ���ô� continue 
		if(mask & (1<<i) || weight[from][i] == 0) continue;
		
		// ���� �༱���� �̵�
		// ��� �湮���� ��ȸ ��  �ּ� ����� ��� 
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
