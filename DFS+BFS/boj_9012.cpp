#include<bits/stdc++.h>

using namespace std;

bool VPS(string str){
	stack<char> stk;
	for(int i=0; i<str.size(); i++){
		char now = str.at(i);
		
		if(stk.empty()){
			stk.push(now);
			continue;
		}
		
		char top = stk.top();
		
		if(now == ')' && top == '('){
			stk.pop();
		}
		else{
			stk.push(now);
		}
	}
	
	return stk.empty();
}

void run(){
	int N; 
	cin >> N;
	
	for(int i=0; i<N; i++){
		string str;
		cin >> str;
		if(VPS(str)){
			cout << "YES" << '\n';
		}
		else{
			cout << "NO" << '\n';
		}
	}
}

int main(){
	run();
	return 0;
}
