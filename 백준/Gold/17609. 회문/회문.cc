#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int T;


int isPalin(string input, int ret){
	if(ret == 2) return ret;
	
	int len = input.length();
	int startIdx = 0, endIdx = len-1;
	
	while(startIdx <= endIdx)
	{		
		if(input[startIdx] == input[endIdx]){
			startIdx++;
			endIdx--;
			continue;
		}
		
		string withoutStart = input.substr(0, startIdx) + input.substr(startIdx+1);
		string withoutEnd   = input.substr(0, endIdx) + input.substr(endIdx+1);
		
		return min(isPalin(withoutStart, ret+1), isPalin(withoutEnd, ret+1));
	}
	
	return ret;
}

int main(){
	cin >> T;
	
	for(int i=0; i<T; i++){
		string input;
		cin >> input;
		cout << isPalin(input,0) << endl;;
	}	
	return 0;
}