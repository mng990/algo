#include<bits/stdc++.h>

using namespace std;

int N, pay, day, ret = 0;
vector<pair<int,int>> schedule;
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬, top에 가장 작은 값이 배치 


int main(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> pay >> day;
		schedule.push_back({day, pay});
	}
	
	sort(schedule.begin(), schedule.end()); // 오름차순으로 정렬, day -> pay 순으로 비교 
	
	for(int i=0; i<N; i++){
		pq.push(schedule[i].second); // pq에 pay 삽입
		if(pq.size() > schedule[i].first){ // pq.size() == 현재 기간(하루에 한 강연이니 강연의 수 == 기간) 
			pq.pop(); // 가장 pay가 적은 강연을 pop 
		} 
	}
	
	while(!pq.empty()){
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret << "\n";
		
	return 0;
}
