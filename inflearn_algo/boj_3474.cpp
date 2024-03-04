#include <bits/stdc++.h>

using namespace std;

int T, N;

int getDV(int num, int DV){
	int rst = 0;
	for(int i=5; i<=num; i*=DV){ // i*=DV°¡ ÇÙ½É 
		rst += num/i;
	}
	
	return rst;
}

int getZero(int num){
	return getDV(num, 5);
}

void run(){
	cin >> T;
	
	for(int t=0; t<T; t++){
		cin >> N;
		cout << getZero(N) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
