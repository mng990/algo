#include <bits/stdc++.h>

using namespace std;

void run(){
	while(true){
		int n;
		long long ans=1, test = 1;
		
		cin >> n;
		
		if(cin.eof() == true) {
			break;
		}`
		
		while(test%n != 0){
			test = 10* test+1; 
			test %= n; 
			ans++;
		}
	
		cout << ans << endl;
	}
	
	return ;
}


int main(){
	run();
	
	return 0;
}
