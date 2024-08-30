#include<bits/stdc++.h>

using namespace std;

int N, num, top = 1;
string output = "";
stack<int> stk;


int main(){
	cin >> N;
		
	for(int i=0; i<N; i++){
		cin >> num;
		
		for(top; top<=num; top++){
			stk.push(top);
			output += "+\n";			
		}
		
		if(stk.empty()){
			cout << "NO";
			exit(0);
		}
		
		while(stk.top() > num){
			output += "-\n";
			stk.pop();
		}
		
		if(stk.empty()){
			cout << "NO";
			exit(0);
		}
		
		stk.pop();
		output += "-\n";
	}
	
	cout << output;
	
	return 0;
}