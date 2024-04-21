#include <bits/stdc++.h> 
#define MAX 14

using namespace std;

int N, ret = INT_MAX;
int pop[MAX];
int comp[MAX] = {0,};
int visited[MAX] = {0,};
vector<int> adj[MAX];

void input(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> pop[i];
	} 
	
	for(int i=0; i<N; i++){
		int loop;
		cin >> loop;
		
		for(int j=0; j<loop;j++){
			int adjVtx;
			cin >> adjVtx;
			adj[i].push_back(adjVtx-1);  
		}
	}
}


pair<int,int> dfs(int now, int val){
	visited[now] = 1;
	pair<int,int> ret = {1, pop[now]}; // 컴포넌트 수, 인구수
	
	for(int next:adj[now]){
		if(comp[next] != val) continue;
		if(visited[next]) continue;
		
		pair<int,int> nextRet = dfs(next, val);
		ret.first += nextRet.first;
		ret.second += nextRet.second;
	} 
	
	return ret; //ret에 방문한 컴포넌트의 수와 인구수를 모아줌 
}


void electionDist(){
	for(int dist=1; dist < (1<<N)-1; dist++){
		memset(comp, 0, sizeof(comp));
		memset(visited, 0, sizeof(visited));
		int idx1 = -1, idx2 = 1;
		
		
		for(int j=0; j<N; j++){
			if(dist & 1<<j){
				comp[j] = 1; //dist에 존재하면 1로 색칠 
				idx1 = j;		
			}
			else{
				idx2 = j; // 아니라면 -1로 색칠  
			}
		}
		pair<int,int> comp1 = dfs(idx1,1); 
		pair<int,int> comp2 = dfs(idx2,0);
		
		if(comp1.first + comp2.first == N) ret = min(abs(comp1.second-comp2.second), ret);
	}
}

void output(){
	if(ret == INT_MAX) ret = -1;
	
	cout << ret;
}


int main(){
	input();
	electionDist();
	output();

	return 0;
}
