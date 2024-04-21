#include<bits/stdc++.h>

using namespace std;

int N;
int arr[1001] = {0,}, pos[1001] = {0,}, ret = 0;

vector<int> lis;


void slow(){
	cin >> N;
	
	for(int i=1; i<=N; i++){
		cin >> arr[i];
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j]){
				pos[i] = max(pos[i], pos[j]+1);
			}
			
			ret = max(pos[i], ret);
		}
	}
	
	cout << ret;
}


void fast(){
	cin >> N;
		
	for(int i=0; i<N; i++){
		cin >> arr[i];
		int lisIdx = lower_bound(lis.begin(), lis.end(), arr[i]) 
					- lis.begin();
		
		if(lisIdx >= lis.size()){
			lis.push_back(arr[i]);
		}
		else{
			lis[lisIdx] = arr[i];
		}
	}
		
	cout << lis.size();
}

void run(){
	fast();
	//slow();
}

int main(){
	run();
	return 0;
}
