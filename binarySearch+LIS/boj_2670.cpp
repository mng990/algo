#include<bits/stdc++.h>

using namespace std;

int N;
double num, ret = 0.0, now = 1.0;


void run(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%lf", &num);
		
		now = max(now, 1.0);
		
		now *= num;

		ret = max(ret, now);
	}
	
	printf("%0.3lf", ret);
}


int main(){
	run();
	
	return 0;
}
