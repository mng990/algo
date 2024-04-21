#include<bits/stdc++.h>

using namespace std;

int T, N, M, num;
int Note1[1000004] = {0,};


bool find(){
	int start = 0, end = N-1;
	
	int mid;
	
	while(start <= end){
		mid = (start+end)/2;
		
		if(Note1[mid] == num){
			return true;
		}
		else if(Note1[mid] > num){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	
	return false;
} // O(logN)

void run(){
	
	scanf("%d", &T);
	
	while(T--){
		
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", &Note1[i]);
		}
		
		sort(Note1, Note1+N);
				
		scanf("%d", &M);
		for(int i=0; i<M; i++){
			scanf("%d", &num);
			printf("%d\n", find());
		}
		
	}	
}

int main(){
	run();	
	return 0;
}
