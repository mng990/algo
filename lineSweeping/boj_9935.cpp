#include<bits/stdc++.h>

using namespace std;

stack<char> stk;
string str, bomb, ret;

string split(string str, string delimeter){
	int start = 0;
	int end = str.find(delimeter);
	string ret;
	
	while(end != string::npos){
		ret += str.substr(start, end-start);
		start = end + delimeter.size();
		end = str.find(delimeter, start);
	}
	
	ret += str.substr(start);
	
	return ret;
}


void check(){
	string checkStr = "";

	while(!stk.empty()){
		
		checkStr += stk.top(); 
		stk.pop();		
		if(checkStr.size() == bomb.size()) break;
	}
	
	reverse(checkStr.begin(), checkStr.end());
	
	if(checkStr != bomb){
		for(char c: checkStr){
			stk.push(c);
		}
	}
}


void run(){
	cin >> str >> bomb;
	
	for(int i=0; i<str.size(); i++){
		stk.push(str[i]);
		
		if(stk.top() == bomb.back()){
			check();
		}
	}
	
	
	if(stk.empty()) cout << "FRULA";
	else{
		while(!stk.empty()){
			ret += stk.top();
			stk.pop();	
		}
	}
	
	reverse(ret.begin(), ret.end());
	
	cout << ret;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
