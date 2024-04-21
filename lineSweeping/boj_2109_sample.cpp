#include<bits/stdc++.h>

using namespace std;

int N, pay, day, ret = 0;
vector<pair<int,int>> schedule;
priority_queue<int, vector<int>, greater<int>> pq; // �������� ����, top�� ���� ���� ���� ��ġ 


int main(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> pay >> day;
		schedule.push_back({day, pay});
	}
	
	sort(schedule.begin(), schedule.end()); // ������������ ����, day -> pay ������ �� 
	
	for(int i=0; i<N; i++){
		pq.push(schedule[i].second); // pq�� pay ����
		if(pq.size() > schedule[i].first){ // pq.size() == ���� �Ⱓ(�Ϸ翡 �� �����̴� ������ �� == �Ⱓ) 
			pq.pop(); // ���� pay�� ���� ������ pop 
		} 
	}
	
	while(!pq.empty()){
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret << "\n";
		
	return 0;
}
