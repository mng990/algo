#include<bits/stdc++.h>

using namespace std;

int N;
int vec[1000004], ret[1000004];
stack<int> stk;

int main(){
	cin >> N;
	fill(ret, ret+N, -1);
	for(int i=0; i<N; i++){
		cin >> vec[i];
		while(!stk.empty() && vec[stk.top()] < vec[i]){
			ret[stk.top()] = vec[i];
			stk.pop();
		}
		
		stk.push(i);
	}   // 새 index가 stk.top의 오큰수가 되는 모든 값을 ret에 저장 후
		// stack에서 pop
	   // 새로운 index를 stack에 push  
	
	return 0;
}
