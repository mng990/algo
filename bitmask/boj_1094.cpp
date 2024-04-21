#include <bits/stdc++.h>

using namespace std;

int X, ret = 1,stick = 64;

void broke(int shortOne){
	int half = shortOne/2;

	if(stick == X) return;
	
	if(stick - half > X)
		stick -= half;
	else if(stick - half == X){
		return ;
	}
	else ret++;
	
	return broke(half);
}

int binaryBroke(){
	int cnt = 0;
	
	for(int i=0; (1<<i)<=X; i++){
		if(X & (1<<i)) cnt++;
	}
	
	return cnt;
}


void run(){
	cin >> X;
	cout << binaryBroke();
}

int main(){
	run();
	return 0;
}
