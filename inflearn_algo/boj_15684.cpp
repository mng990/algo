#include<bits/stdc++.h>

using namespace std;


int N, M, H, ret = 0;

int ladder[14][34];
int adj[14][34];

void input(){
	cin >> N >> M >> H;

	for(int i=0; i<M; i++){
		int lev, from;
		cin >> lev >> from;
		
		adj[from  ][lev] = from+1;
		adj[from+1][lev] = from;
	}
}

int ride(int now, int level){
	if(level > H){
		return now;
		
	} 
	int next = now;
	
	if(adj[now][level]){
		next = adj[now][level];
	}

	return ride(next, level+1);
}

bool combi(int start, int depth, int size){	
	if(depth == size){
		
		for(int i=1; i <= N; i++){
			
			if(i != ride(i,1)) return false;
		}
		return true;
	}
	
	
	for(int i=1; i < N; i++){
		int j;
		for(j=start; j<=H;j++){
			if(adj[i][j] || adj[i+1][j]) continue;
			
			adj[i][j] = i+1;
			adj[i+1][j] = i;
			
			if(combi(j, depth+1, size)) return true;
			
			adj[i][j]   = 0;
			adj[i+1][j] = 0;
		}
		
		j=1;
	}
	
	return false;
}




int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	int size;
	
	input();
	
	for(size=0; size<4;size++){
		if(combi(0,0,size)) break;	
	}
	
	if(size == 4) ret = -1;
	else	   	  ret = size;
	cout << ret;
	return 0;
}
