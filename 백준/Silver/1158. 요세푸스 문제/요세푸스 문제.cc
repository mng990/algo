#include<bits/stdc++.h>
#define MAX 5001

using namespace std;

int visited[MAX];
queue<int> que;
int main() {
	int N, K;
	cin >> N >> K;
	
	cout << "<";
	
	for(int i=1; i<=N; i++){
		que.push(i);
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<K-1; j++){
			que.push(que.front());
			que.pop();
		}
		
		cout << que.front();
		que.pop();
		
		if(i < N-1) cout << ", ";	
	}	
	cout << ">";
	
	
	
	return 0;
}