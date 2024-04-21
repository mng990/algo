#include<bits/stdc++.h>

using namespace std;

void run(){
	int N, idx = 0;
	string beast = "666";
	int number = 666;
	
	cin >> N;
	while(true){
		if(to_string(number).find(beast) != string::npos){
			idx++;
			if(idx == N) break;
		}
		number = number+1;
	}
	
	cout << number;
}

int main(){
	run();
	return 0;
}
