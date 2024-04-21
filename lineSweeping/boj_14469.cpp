#include<bits/stdc++.h>

using namespace std;

int N, ret;
vector<pair<int,int>> cow;

void printCow(){
	for(int i=0; i<cow.size(); i++){
		cout << cow[i].first << " / " << cow[i].second<<"\n";
	}
}

void run(){
	cin >> N;
	for(int i=0; i<N; i++){
		int start, check;
		cin >> start >> check;
		cow.push_back({start, check});
	}
	
	sort(cow.begin(), cow.end());
	
	for(auto c: cow){
		if(ret < c.first) ret = c.first;
		ret += c.second;
	}
	cout << ret;
//	printCow();
}

int main(){
	run();
	return 0;
}
