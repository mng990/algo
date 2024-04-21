#include<bits/stdc++.h>

using namespace std;

int N, num;
stack<int> stk;
stack<int> cmp;
stack<int> ans;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> num;
		stk.push(num);
	}
}

void NGE(){
	while(!stk.empty()){
		int now = stk.top();
		while(true){
			if(cmp.empty()){
				ans.push(-1);
				break;
			}
			
			int cmpNow = cmp.top();
			if(now < cmpNow){
				ans.push(cmpNow);
				break;
			}
			else{
				cmp.pop();
			}
		}
		
		cmp.push(now);
		stk.pop();
	}		
}	

void output(){
	while(!ans.empty()){
		cout << ans.top() << " ";
		ans.pop();
	}
}

void run(){
	input();
	NGE();
	output();
}


int main(){
	run();
	return 0;
}
