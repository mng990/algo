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
				int dist = INT_MAX; // ���ķ� �� ���� ���� ��� ���� ū ���� ���� 
				for(int j=i+1; j<K; j++){
					if(ec == elec[j]){
						dist = j;
						break;
					}
				}
				
				if(maxDist < dist){
					maxDist = dist;
					out = ec;
				} // ���� �ָ� ������ ������ǰ�� ����  
			}
			
			visited[out] = 0;
			multiTap.erase(find(multiTap.begin(), multiTap.end(), out)); // �ش� ��ǰ�� ���� 
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
