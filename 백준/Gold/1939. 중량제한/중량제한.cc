#include<bits/stdc++.h>
#define MAX 10001
#define MAXC 1000000001

using namespace std;
using pii = pair<int,int>;

int N, M, A, B, from, to;
int C;

vector<pii> graph[MAX];

int dijkstra(){
	vector<int> best(N+1, -1);
	
	priority_queue<pii> pq;
	
	pq.push({MAXC, from});
	
	while(!pq.empty()){
		int here  = pq.top().second;
		int  cost  = pq.top().first;
		pq.pop();
		
		if(best[here] > cost) continue;
		
		for(pii there: graph[here]){
			int accept = min(there.first, cost);
			
			if(best[there.second] < accept){
				best[there.second] = accept;
				pq.push({accept, there.second});
			}
		}
	}
		
	return best[to];
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=0; i<M; i++){
		cin >> A >> B >> C;
		graph[A].push_back({C, B});
		graph[B].push_back({C, A});
	}
	
	cin >> from >> to;
	
	cout << dijkstra();
	
	return 0;
}