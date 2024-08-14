#include<bits/stdc++.h>

using namespace std;
const int lottery = 6;
int k, num;

vector<int> S;
vector<int> pickUp;
vector<vector<int>> cases;
vector<vector<vector<int>>> result;


void combi(int start){
	if(pickUp.size() == lottery){
		cases.push_back(pickUp);
		return ;
	}
	
	for(int i=start; i<k; i++){
		pickUp.push_back(S[i]);
		combi(i+1);
		pickUp.pop_back();
	}
}

int main(){
	
	while(true){
		cin >> k;
		
		if(k == 0) break;
		
		S.clear();
		pickUp.clear();
		cases.clear();
		
		for(int i=0; i<k; i++){
			cin >> num;
			S.push_back(num);
		}
				
		combi(0);
		
		result.push_back(cases);
 	}
	
	for(vector<vector<int>> dim: result){
		for(vector<int> row: dim){
			for(int num : row){
				cout << num << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	
	return 0;
}