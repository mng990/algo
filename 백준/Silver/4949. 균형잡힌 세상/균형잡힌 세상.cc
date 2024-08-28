#include<bits/stdc++.h>

using namespace std;


bool isBalance(string input){
	stack<char> stk;
	
	for(auto c: input) {
		if(c != '(' && c != ')' && c != '[' && c != ']') continue;
		
		if(c == '(' || c == '['){
			stk.push(c);
			continue;
		}
		
		if(stk.empty()) return false;
						
		if(c == ')' && stk.top() == '('){
			stk.pop();
			continue;
		}
		
		if(c == ']' && stk.top() == '['){
			stk.pop();
			continue;
		}
		
		return false;
	}
	
	return stk.empty();
}

int main(){
	string input = "start";
	
	while(true){
		getline(cin, input, '.');
		cin.ignore();
		if(input == "") break;
		
		if(isBalance(input)) cout << "yes\n";
		else				 cout << "no\n";
	}
	
	return 0;
}