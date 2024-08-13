#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<vector<int>> result;
vector<int> arr;

bool sortFlag(vector<int>& left, vector<int>& right){
	
	for(int i=0; i<M; i++){
		if(left[i] <= right[i]) return true;
	}
	
	return false;
}

vector<int> pick;

void combi(int start){
	if(pick.size() == M){
		result.push_back(pick);	
		return;
	}
	
	for(int i=start; i<N; i++){
		pick.push_back(arr[i]);
		combi(i);
		pick.pop_back();
	}
}

int main(){
	
	cin >> N >>M;
	
	for(int i=0; i<N; i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	
	sort(arr.begin(), arr.end());
	
	combi(0);

	sort(result.begin(), result.end());
	
	for(vector<int> out: result){
		for(int num: out){
			cout << num <<" ";
		}
		cout << "\n";
	}
	
	return 0;
}