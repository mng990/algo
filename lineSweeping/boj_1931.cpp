#include<bits/stdc++.h>

using namespace std;

int N, ret=0, realTime = 0;
vector<pair<int,int>> schedule;

bool sortFlag(pair<int,int> m1, pair<int,int> m2){
	if(m1.second != m2.second)
		return m1.second < m2.second;
	else
		return m1.first < m2.first;
}

void run(){
	cin >> N;
	for(int i=0; i<N; i++){
		int start, end;
		cin >> start >> end;
		schedule.push_back({start, end});
	}
	
	sort(schedule.begin(), schedule.end(), sortFlag);
	
	for(int i=0; i<schedule.size(); i++){
		if(realTime > schedule[i].first) continue;
		realTime = schedule[i].second;
		ret++;
	}
	
	cout << ret;
}

int main(){
	run();
	return 0;
}
