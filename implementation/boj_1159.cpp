#include<bits/stdc++.h>

using namespace std;

int N;
string ans;
map<char, int> selection;
vector<char> bench;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		string player;
		cin >> player;
		selection[player.at(0)]++;
	}
}

void select(){
	for(int i=0; i<26; i++){
		char c = 'a' + i;
		
		if(selection[c] >= 5){
			ans.push_back(c);
		}
	}
}

void output(){
	if(ans.empty()) ans = "PREDAJA";
	cout << ans;
}

void run(){
	input();
	select();
	output();
}

int main(){
	run();
	return 0;
}
