#include<bits/stdc++.h>
#define N 10
using namespace std;

vector<vector<int>> graph;
vector<bool> visited(N, false);

vector<vector<int>> graphGL(10);

void makeGraphByVector(){
	for(int i=0; i<N;i++){
		vector<int> grow;
		for(int j=0; j<N; j++){
			grow.push_back(0);
		}
		graph.push_back(grow);
	}
	
	graph.at(1).at(2) = 1;
	graph.at(2).at(1) = 1;
	graph.at(1).at(3) = 1;
	graph.at(3).at(1) = 1;
	graph.at(3).at(4) = 1;
	graph.at(4).at(3) = 1;
} // graph.at(vtx).at(adj) = vtx와 연결된 adj의 존재 여부(0 = x, 1= adj) 

void makeGraphByList(){
	vector<int> adj01 = {2, 3};
	vector<int> adj02 = {1};
	vector<int> adj03 = {1, 4};
	vector<int> adj04 = {3};

	
	graphGL.at(1) = adj01; // graphGL.at(1)
	graphGL.at(2) = adj02; // graphGL.at(2)
	graphGL.at(3) = adj03; // graphGL.at(3)
	graphGL.at(4) = adj04; // graphGL.at(4)
	
	return;
} // graphGL.at(vtx).at(adj) = vtx와 연결된 adj의 index 

void DFS(int vtx){	
	if(visited[vtx] == true) return;
	
	visited[vtx] =  true;
	cout << vtx << endl;

	for(int i=0; i<N; i++){
		int next = graph.at(vtx).at(i);
		
		if(next > 0 && visited[i] == false){
			DFS(i);
		}
	}
		
	return;	
}

void DFSL(int vtx){
	if(visited[vtx] == true) return;
	
	visited[vtx] = true;
	cout << vtx << endl;
	
	for(auto adj : graphGL.at(vtx)) DFSL(adj);
}

void printVisited(){
	
	for(int i=0; i<N; i++)
		cout << visited[i] << " ";
	cout << endl;
}



int main(){
	makeGraphByList();
	printVisited();

	for(int vtx=0; vtx<graphGL.size(); vtx++){
		if(!graphGL.at(vtx).empty()) DFSL(vtx);
	}
		
	return 0;
}



