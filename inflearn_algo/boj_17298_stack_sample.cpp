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
	}   // �� index�� stk.top�� ��ū���� �Ǵ� ��� ���� ret�� ���� ��
		// stack���� pop
	   // ���ο� index�� stack�� push  
	
	return 0;
}
