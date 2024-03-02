#include<bits/stdc++.h>


using namespace std;

vector<int> combi;
vector<int> dwarf;
vector<int> ans; 

void input(){
	for(int i=0; i<9; i++){
		int height;
		cin >> height;
		dwarf.push_back(height);
	}
}

void combination(int start, int sum){
	if(!ans.empty()) return;
	
	if(combi.size() == 7){
		
		if(sum == 100){
			for(int cidx=0; cidx<combi.size(); cidx++ ){
				int didx = combi.at(cidx);
				ans.push_back(dwarf.at(didx));
			}
		}
		
		sort(ans.begin(), ans.end());
		
		return ;
	}
	
	for(int i=start+1; i < dwarf.size(); i++){
		sum += dwarf.at(i);
		combi.push_back(i);
		
		combination(start+1, sum);
		
		sum -= dwarf.at(i);
		combi.pop_back();
	}
	
	return ;
}

void output(){
	for(int i=0; i<ans.size(); i++){
		cout << ans.at(i) << endl;
	}
}

void run(){
	input();
	combination(-1, 0);
	output();
}

int main(){
	run();
	return 0;
}
