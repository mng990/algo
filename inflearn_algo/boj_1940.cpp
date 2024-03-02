#include <bits/stdc++.h>

using namespace std;

int N, armor, ans = 0;
vector<int> pocket;
vector<int> combi;


void input(){
	cin >> N >> armor;
	for(int i=0; i<N; i++){
		int st;
		cin >> st;
		pocket.push_back(st);
	}
}

void combination(int start){
	if(combi.size() == 2){
		int stIdx1 = combi.at(0);
		int stIdx2 = combi.at(1);
		//cout << pocket.at(stIdx1) << " " << pocket.at(stIdx2) <<endl;
		if(pocket.at(stIdx1) + pocket.at(stIdx2) == armor) ans++;	
		return ;
	}
	
	for(int i=start+1; i<N; i++){
		combi.push_back(i);
		combination(i); 
		combi.pop_back();
	}
	return;
}

void output(){
	cout << ans;
}

void run(){
	input();
	combination(-1);
	output();
}

int main(){
	run();
	return 0;
}
