#include<bits/stdc++.h>

using namespace std;


bool balance(char now, char top){
	if( (now == ')' && top == '(')
	|| (now == ']' && top == '[')){
		return true;
	}
	else return false;
}

bool bracket(char now){
	if(now == '(' || now == '[' 
	|| now == ']' || now == ')') return true;
	else 						 return false;
}

void run(){
	while(true){
		string str;
		getline(cin, str);
		
		if(str == ".") break;
		stack<char> stk;

		
		for(int i=0; i<str.size();i++){
			char now = str.at(i);
		
			if(bracket(now)){
				if(!stk.empty() && balance(now, stk.top())){
					stk.pop();
				}
				else{
					stk.push(now);
				}
			}
		}	
		
		if(stk.empty()){
			cout << "yes" << '\n';
		}
		else{
			cout << "no" << '\n';
		}
		
	}
	
	
}

int main(){
	run();
	return 0;
}
