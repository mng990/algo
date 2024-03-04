#include<bits/stdc++.h>

using namespace std;

int visited[10] = {0,};
vector<vector<int>> adj(10);
vector<int> path;

void travel(int vtx){
	
	if(path.size() == 3){
		cout <<"path: ";
		for(int i=0; i<path.size(); i++){
			cout << path.at(i)<<' ';	
		}
		cout << '\n';
		return;
	}
	
	cout << vtx << " " << path.size() << '\n';
		
	for(int i=0; i<adj[vtx].size(); i++){
		int next = adj[vtx][i];
		
		if(!visited[next]){
			visited[next] = true;
			path.push_back(next);
			travel(next);
			visited[next] = false;
			path.pop_back();
		} 
	}

	
	return ;
}

int main(){
	adj[0].push_back(1);
	adj[1].push_back(0);
	
	adj[1].push_back(2);
	adj[2].push_back(1);
	
	adj[1].push_back(3);
	adj[3].push_back(1);
	
	visited[0] = true;
	path.push_back(0);
	travel(0);
	
		
	return 0;
}
