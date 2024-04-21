#include<bits/stdc++.h>

using namespace std;

int buy, cntA, cntB, ret = 0;
vector<int> pizzaA;
vector<int> pizzaB;

int DP[2][2002] = {0,};

int arrA[2000001] = {0,};
int arrB[2000001] = {0,};

void input(){
	cin >> buy;
	cin >> cntA >> cntB;
	
	for(int i=1; i<=cntA; i++){
		int sizeA;
		cin >> sizeA;
		
		DP[0][i] = DP[0][i-1] + sizeA;
		pizzaA.push_back(sizeA);
	}
	
	for(int i=cntA+1; i<=2*cntA; i++){
		DP[0][i] = DP[0][i-1] + pizzaA[i-(cntA+1)];
	}
	
	for(int i=1; i<=cntB; i++){
		int sizeB;
		cin >> sizeB;
		
		DP[1][i] = DP[1][i-1] + sizeB;
		pizzaB.push_back(sizeB);
	}
	
	for(int i=cntB+1; i<=2*cntB; i++){
		DP[1][i] = DP[1][i-1] + pizzaB[i-(cntB+1)];
	}
}

void makePizzaA(){
	for(int i=1; i <=cntA; i++){
		for(int start=i; start<=cntA + i-1; start++){
			int sum = DP[0][start] - DP[0][start-i];
			arrA[sum]++;
			
			if(i == cntA) break;
		}
	}
	
}

void makePizzaB(){
	for(int i=1; i <= cntB; i++){
		for(int start=i; start<=cntB+i-1; start++){
			int sum = DP[1][start] - DP[1][start-i];
			arrB[sum]++;
			
			if(i == cntB) break;
		}
	}
}

void getAns(){
	ret += arrA[buy] + arrB[buy];
	
	for(int i=1; i<buy; i++){
		ret += arrA[i] * arrB[buy-i];
	}
}

void output(){
	cout << ret << "\n";
}

void run(){
	input();
	makePizzaA();
	makePizzaB();
	getAns();
	output();
}

int main(){
	run();
	return 0;
}
