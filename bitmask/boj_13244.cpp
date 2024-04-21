#include<bits/stdc++.h>

using namespace std;

int T, N ,M; // 트리 개수, 노드 개수, edge 개수 
int visited[1004];
vector<vector<int>> tree;

int DFS(int now){
	int cnt = 1;
		
	for(int i=0; i<tree[now].size();i++){
		int next = tree[now][i];
	
		if(visited[next]) continue;
		visited[next] = 1;
		cnt += DFS(next);	
	}
	
	return cnt;
}
void run(){
	cin >> T;
	for(int t=0; t<T; t++){
		int A, B;
		cin >> N >> M;
		
		tree.clear();
		tree.resize(N+1);
		memset(visited, 0, sizeof(visited));
		
		for(int i=0; i<M; i++){
			cin >> A >> B;
			tree[A].push_back(B);
			tree[B].push_back(A);
		}
		
		visited[A] = 1;
		int nodeCnt = DFS(A);

		if(nodeCnt-1 == M){
			cout << "tree" << '\n';
		}
		else{
			cout << "graph" << '\n';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
