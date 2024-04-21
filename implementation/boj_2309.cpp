#include<bits/stdc++.h>
#define N 9
#define C 7
#define FC 2

using namespace std;

vector<int> combi;
vector<int> dwarf;
vector<int> ans; 
int dsum = 0;

void input(){
	for(int i=0; i<N; i++){
		int height;
		cin >> height;
		dwarf.push_back(height);
		dsum += height;
	}
}

void combination(int start, int sum){
	if(!ans.empty()) return;
	
	if(combi.size() == C){
		if(sum == 100){
			for(int cidx=0; cidx<combi.size(); cidx++ ){
				int didx = combi.at(cidx);
				ans.push_back(dwarf.at(didx));
			}
		}
		sort(ans.begin(), ans.end());	
	}
	
	for(int i=start+1; i < dwarf.size(); i++){
		sum += dwarf.at(i);
		combi.push_back(i);
		
		combination(start+1, sum);
		
		sum -= dwarf.at(i);
		combi.pop_back();
	}
	 	
	return ;	
}  // 합이 100이 되는 조합 (9C7)

void fastCombination(int start, int sum){
	if(!ans.empty()) return;
	
	if(combi.size() == FC){
		if((dsum - sum) == 100){
			for(int didx = 0; didx<dwarf.size(); didx++){
				if(find(combi.begin(), combi.end(), didx) == combi.end()){
					ans.push_back(dwarf.at(didx));
				}
			}
			
			sort(ans.begin(), ans.end());
		}
	}
	
	for(int i=start+1; i < dwarf.size(); i++){
		sum += dwarf.at(i);
		combi.push_back(i);
		
		fastCombination(start+1, sum);
		
		sum -= dwarf.at(i);
		combi.pop_back();
	}
	 	
	return ;
} // 나머지의 합이 100이 되는 조합 (9C2) 

void output(){
	for(int i=0; i<ans.size(); i++){
		cout << ans.at(i) << endl;
	}
}

void run(){
	input();
	combination(-1, 0);
	//fastCombination(-1, 0);
	output();
}

int main(){
	run();
	return 0;
}
