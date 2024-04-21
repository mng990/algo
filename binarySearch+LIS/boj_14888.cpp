#include <bits/stdc++.h>

using namespace std;

int N, retMax = INT_MIN, retMin = INT_MAX;
int num[104] = {0,};
int oper[4] = {0,};
vector<int> vecOper;


void calSample(int index, int cur, int plus, int minus, int mul, int div){
	if(index == N-1){
		retMax = max(cur, retMax);
		retMin = min(cur, retMin);
		return;
	}
	
	if(plus) calSample(index+1, cur+num[index+1], plus-1, minus, mul, div);
	if(minus) calSample(index+1, cur-num[index+1], plus, minus-1, mul, div);
	if(mul) calSample(index+1, cur*num[index+1], plus, minus, mul-1, div);
	if(div) calSample(index+1, cur/num[index+1], plus, minus, mul, div-1);
	
	return;
}

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> num[i];
	}
	
	for(int i=0; i<4; i++){
		cin >> oper[i];
		
		for(int j=0; j<oper[i]; j++){
			vecOper.push_back(i);
		}
	}
}

void cal(){
	do{
		int sum = num[0];
		for(int i=1; i<N; i++){
			int nowOp = vecOper[i-1];
			
			switch(nowOp){
			case 0:
				sum += num[i];
				break;
			case 1:
				sum -= num[i];
				break;
			case 2:
				sum *= num[i];
				break;
			case 3:
				sum /= num[i];
				break;			 	
			}
		}
		
		retMax = max(retMax, sum);
		retMin = min(retMin, sum);
		
	}while(next_permutation(vecOper.begin(), vecOper.end()));
}

void output(){
	cout << retMax << "\n";
	cout << retMin;
}

void run(){
	input();
	//cal();
	calSample(0, num[0], oper[0],oper[1],oper[2],oper[3]);
	output();
}

int main(){
	run();
	return 0;
} 
