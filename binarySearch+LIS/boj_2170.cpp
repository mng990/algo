#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
ll sum = 0;
vector<pair<ll,ll>> line;

bool sortFlag(pair<ll,ll> line1, pair<ll,ll> line2){
	if(line1.first != line2.first)
		return line1.first < line2.first;
	else{
		line1.second < line2.second;
	}
}

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		int start, end;
		cin >> start >> end;
		line.push_back({start, end});
	}
	
	sort(line.begin(), line.end(), sortFlag);
} 

void lineSweeping(){
	sum += line[0].second - line[0].first;
	
	for(int i=1; i<line.size(); i++){
		if(line[i-1].second > line[i].first){
			line[i].first = line[i-1].second;
		}
		
		if(line[i].first > line[i].second){
			line[i].second = line[i].first;
		}
		
		sum+=line[i].second - line[i].first;
	}
}

void output(){
	cout << sum << "\n";
}

void run(){
	input();
	lineSweeping();
	output();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	run();
	return 0;
}
