#include<bits/stdc++.h>

using namespace std;

int N, K, ret=0;
int elec[104];
int visited[104] = {0,}; 

vector<int> multiTap;


void run(){
	cin >> N >> K;
	
	for(int i=0; i<K;i++){
		cin >> elec[i];
	}
	
	for(int i=0; i<K; i++){
		int now = elec[i];
		
		if(visited[now]) continue;
		
		
		if(multiTap.size() == N){
			int out = -1, maxDist = -1;
			
			for(auto ec: multiTap){
				int dist = INT_MAX; // 이후로 쓸 일이 없는 경우 가장 큰 값을 배정 
				for(int j=i+1; j<K; j++){
					if(ec == elec[j]){
						dist = j;
						break;
					}
				}
				
				if(maxDist < dist){
					maxDist = dist;
					out = ec;
				} // 가장 멀리 떨어진 전자제품을 선택  
			}
			
			visited[out] = 0;
			multiTap.erase(find(multiTap.begin(), multiTap.end(), out)); // 해당 제품을 삭제 
			ret++;
		}
		
		visited[now] = 1;
		multiTap.push_back(now);
	}
	
	
	
	cout << ret;
}

int main(){
	run();
	
	return 0;
}
