#include<bits/stdc++.h>
#define llg long long

using namespace std;


llg multiple(llg A, llg B, llg C){
	if(B == 1) return A%C;
	
	llg halfB = B/2;
	

	if(B%2 == 1){
		return (A*multiple(A, B-1, C))%C;
	}
	else{
		llg half = multiple(A, halfB, C)%C;

		return (half * half)%C;
	}
}

int main(){
	llg A, B, C;
	cin >> A >> B >> C;
	cout << multiple(A, B, C)%C;
	
	return 0;
}
