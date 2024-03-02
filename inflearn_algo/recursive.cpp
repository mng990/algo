#include<bits/stdc++.h>

using namespace std;

int factRecursive(int n){
	if(n==1 || n==0) return 1;
	return n * factRecursive(n-1);
}

int fact(int n){
	int ret = 1;
	for(int i=1; i<=n; i++)
		ret *= i;
	return ret;
}

int fiboRecursive(int n){
	//cout << n << endl;
	if(n == 0 || n == 1) return n;
	return fiboRecursive(n-1) + fiboRecursive(n-2);
}


int n=5;

int main(){
	cout << factRecursive(5) << endl;
	cout << fiboRecursive(4) << endl;
	cout << fact(4) << endl;
	
	return 0;
}
