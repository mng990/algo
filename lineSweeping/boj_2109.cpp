#include<bits/stdc++.h>

using namespace std;

int N, day, pay, ret = 0, maxDay = 0;
int DP[10004] = {0,};
int visited[10004] = {0,};
vector<pair<int,int>> schedule;


bool sortFlag(pair<int,int> s1, pair<int,int> s2){
	if(s1.first != s2.first){
		return s1.first > s2.first;
	}
	else{
		return s1.second < s2.second;
	}		
}

void printSchedule(){
	cout << "\n";
	for(int i=0; i<schedule.size(); i++){
		cout << schedule[i].first << " " << schedule[i].second << "\n";
	}
}

void printDP(){
	cout << "\n";
	for(int i=0; i<=maxDay; i++){
		cout << DP[i] << "\n";
	}
	cout << "\n";
}

void makeDP(){
	for(int now = maxDay; now >= 1; now--){
		for(int i=0; i<schedule.size(); i++){
			pair<int,int> semina = schedule[i];
			int pay = semina.first;
			int day = semina.second;
			
			if(day < now) continue;
			if(DP[now]) continue;
			if(visited[i]) continue;
	
			DP[now] = pay;
			visited[i]= true;
			ret += pay;
		}
	}
	
}

void input(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> pay >> day;
		
		schedule.push_back({pay, day});
		maxDay = max(day, maxDay);
	}
}

int main(){
	input();
	sort(schedule.begin(), schedule.end(), sortFlag);
	makeDP();
	cout << ret <<"\n";

	//printSchedule();
	//printDP();
	return 0;
}
