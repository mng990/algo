#include<bits/stdc++.h>

using namespace std;

int N, btIdx, arr[1001] = {0,}, pos[1001] = {0,};
vector<int> lis;

void run(){
	cin >> N;
		
	for(int i=0; i<N; i++){
		cin >> arr[i];
		int lisIdx = lower_bound(lis.begin(), lis.end(), arr[i]) 
					- lis.begin();
		
		pos[i] = lisIdx;
		
		if(lisIdx >= lis.size()){
			lis.push_back(arr[i]);
		}
		else{
			lis[lisIdx] = arr[i];
		}
	}

	
	cout << lis.size() << "\n";
	
	
	btIdx = lis.size()-1;
	
	for(int i = N-1; i>=0; i--){
		if(pos[i] == btIdx){
			lis[btIdx] = arr[i];
			btIdx--;
		}	
	}
		
	for(int i=0; i<lis.size(); i++){
		cout << lis[i] << " ";
	}
}

int main(){
	run();
	return 0;
}
