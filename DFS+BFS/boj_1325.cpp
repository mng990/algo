#include <bits/stdc++.h> 

using namespace std;

int N, M, maxCmp = 0;

vector<vector<int>> adj;
vector<int> result;
int visited[10004] = {0,};
int DP[10004] = {0,};


int DFS(int cmp){
	int ret = 1;
	visited[cmp] = 1;


	for(int i=0; i < adj[cmp].size(); i++){
		int next = adj[cmp].at(i);
		
		if(visited[next]) continue;
		
		ret += DFS(next);
	}
		
	return ret;
}


void run(){
	cin >> N >> M;
	adj.resize(N+1);
	for(int i=0; i<M; i++){
		int A, B;
		cin >> A >> B;
		
		adj[B].push_back(A);
	}
	
	for(int i=1; i<=N; i++){
		fill(visited, visited+N+1, 0);
		DP[i] = DFS(i);
		maxCmp = max(maxCmp, DP[i]);
	}
	
	for(int i=1; i<=N; i++){
		if(maxCmp == DP[i])
			cout << i << " ";
	}
	
}



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    run();

	return 0;
}
