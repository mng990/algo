#include<bits/stdc++.h>

using namespace std;

int N, num, top = 1;
string output = "";
stack<int> stk;


int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
	cin >> N;
		
	for(int i=0; i<N; i++){
		cin >> num;
		
		while(top <= num){
			stk.push(top++);
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