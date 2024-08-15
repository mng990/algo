#include<bits/stdc++.h>
#define MAX 50001
#define INF 9876543

using namespace std;
using dot = pair<int,int>;


int n, T;

bool canMove(dot from, dot to){
	return abs(from.first - to.first) <= 2 
	&& abs(from.second - to.second) <= 2;
}

vector<dot> mountain;
int visited[MAX] = {0,};

int bfs(){
	int nowIdx = 0;
	
	queue<int> step;	
	step.push(nowIdx);
	visited[0] = 1;
	
	while(!step.empty()){
		nowIdx = step.front();
		step.pop();
		
		dot spot = mountain[nowIdx];
		dot bottom = {spot.first-2, spot.second-2};
		dot top    = {spot.first+2, spot.second+2};
		
		
		auto low  = lower_bound(mountain.begin(), mountain.end(), bottom);
		auto high = upper_bound(mountain.begin(), mountain.end(), top);

		
		for(auto iter = low; iter<high; iter++){
			int nextIdx = iter - mountain.begin();
			if(visited[nextIdx]) continue;
			if(!canMove(mountain[nowIdx], mountain[nextIdx])) continue;
			
			visited[nextIdx] = visited[nowIdx]+1;
			step.push(nextIdx);
			
			if(mountain[nextIdx].first == T){
				return visited[nextIdx]-1;
			}
		}
		
	}
	
	return -1;
}

int main() {
	cin >> n >> T;
	
	
	mountain.push_back({0,0});
	
	for(int i=0; i<n; i++){
		dot next;
		cin >> next.second >> next.first;
		mountain.push_back(next);
	}
	
	sort(mountain.begin(), mountain.end());

	cout << bfs();
		
	return 0;
}