#include<bits/stdc++.h>

using namespace std;

int N, ret = 1;
vector<pair<int, int>> schedule;

bool sortFlag(pair<int,int> m1, pair<int,int> m2){
	bool flag = true;
	
	
	if(m1.second != m2.second)
		flag = (m1.second < m2.second);
	
	else if(m1.first != m2.first)
		flag = (m1.first < m2.first);
	
	
	return flag;
}

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		pair<int,int> meeting;
		
		cin >> meeting.first >> meeting.second;
		schedule.push_back(meeting);
	}
}

void printSchedule(){
	for(int i=0; i<N; i++){
		cout << schedule[i].first << " " << schedule[i].second << '\n';
	}
}

void setSchedule(){
	int prev = schedule[0].second;
	
	for(int i=1; i<N; i++){
		pair<int,int> meeting = schedule[i];
		if(meeting.first < prev) continue;
		
		prev = meeting.second;
		ret++;
	}
}

void run(){
	input();
	sort(schedule.begin(), schedule.end(), sortFlag);
	setSchedule();
	//printSchedule();
	//printVisited();
	cout << ret << '\n';
}

int main(){
	
	run();
	return 0;
}
