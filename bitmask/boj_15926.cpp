#include<bits/stdc++.h>

using namespace std;

string str;
int N, ret = 0, cnt = 0;
int DP[200004];
stack<int> bracket;

void pushTo(int sidx){
	
	if(str[sidx] == '('){
		bracket.push(sidx);
	}
	else if(!bracket.empty()){
		DP[sidx] = 1;
		DP[bracket.top()] = 1; // pop µÇ´Â top 
		bracket.pop();
	}
	
	return ; 
}

int main(){
	
	cin >> N;
	cin >> str;
	
	for(int sidx=0; sidx<str.size(); sidx++){		
		pushTo(sidx);		
	}
	
	for(int sidx=0; sidx<str.size(); sidx++){
		if(DP[sidx] == 1){
			cnt++;
			ret = max(cnt, ret);
		}
		else{
			cnt = 0;
		}
	}

	
	
	cout << ret << "\n";
	
	return 0;
}
