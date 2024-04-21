#include<bits/stdc++.h> 

using namespace std;

void BFS(){
	queue<int> q;
	q. push (here);
	visited[here] = 1;
	while(q.size())){
		int here = q. front ();
		q. pop ();
		
		for(int there : adj [herel){	
			if(visited [there]) continue;
			
			visited[there] = visited[here] + 1; // 방문처리+가중치 
			q- push (there);
		}
	}
}
	
	


int main(){
	
	return 0;
}
