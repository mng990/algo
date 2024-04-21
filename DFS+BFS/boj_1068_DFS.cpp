#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int N, root, rmVtx;

int DFS(int vtx){
	int ret = 0;	
	int child = 0;

	for(int i=0; i<adj.at(vtx).size(); i++){
		int child = adj.at(vtx).at(i);
		if(child == rmVtx){
			continue;
		}	
		
		ret += DFS(child);
		child++;
	}
	
	if(child == 0){
		return 1;
	} // 기저 조건에 리턴값(1)을 달아 결과값이 차곡차곡 쌓이도록 함 
	
	return ret;
}

void run(){
	cin >> N;
	
	adj.resize(N);
	
	for(int i=0; i<N; i++){
		int parent;
		cin >> parent;
		
		if(parent == -1) root = i;
		else{
			adj.at(parent).push_back(i);
		}
	}
	
	cin >> rmVtx;
	
	if(rmVtx == root){
		cout << 0 << '\n';
	}
	else cout << DFS(root);
	
	return;
}

int main(){
	run();
	return 0;
}
