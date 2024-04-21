#include<bits/stdc++.h>

using namespace std;

int N, M, ret =0 ;
int Map[4][4];


void run(){
	for(int mask=0; mask < 1<<(N*M); mask++){ // 자르는 패턴 
		int sum = 0;
		for(int i=0; i<N; i++){
			int nowInt = 0;
			
			for(int j=0; j<M; j++){
				int nowMask = 1<<(j+i*M);
			
				if(!(mask & nowMask)){
					nowInt *= 10;
					nowInt += Map[i][j];
				}
				else{
					sum += nowInt;
					nowInt = 0;
				}
			}
			
			sum += nowInt; 
		}
		
		
		for(int j=0; j<M; j++){
			int nowInt = 0;
			for(int i=0; i<N; i++){
				int nowMask = 1<<(j+i*M);
				if(nowMask & mask){
					nowInt *=10;
					nowInt += Map[i][j];	
				}
				else{
					sum += nowInt;
					nowInt = 0;
				}
			}
			sum += nowInt;
		}
		ret = max(ret, sum);
	}
	
	cout << ret;
	
}

void input(){
	string data;
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		cin >> data;
		for(int j=0; j<M; j++){
			Map[i][j] = data[j]-'0';
		}
	}
	
}

int main(){
	input();
	run();
	return 0;
}
