#include<bits/stdc++.h>

using namespace std;

int N, M;

vector<int> pick;
vector<string> result;

void combi(int start){
	if(pick.size() == M){
		do{
			string str = "";
			for(auto num: pick){
				str += to_string(num) + " ";
			}
			result.push_back(str);
		}while(next_permutation(pick.begin(), pick.end()));
		
		return;		
	}
	
	for(int i=start; i<=N; i++){
		pick.push_back(i);
		combi(i+1);
		pick.pop_back();
	}
}

int main(){
	cin >> N >> M;
	combi(1);
	
	sort(result.begin(), result.end());
	
	for(auto out: result){
		cout << out << "\n";
	}
	
	return 0;
}