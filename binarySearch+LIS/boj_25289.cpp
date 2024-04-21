#include <bits/stdc++.h>

using namespace std;

int N, ret = 0;
int arr[100004] = {0,};
int DP[100004] = {0,};


void run(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	for(int k=-99; k<100; k++){
		memset(DP, 0, sizeof(DP));
		for(int i=0; i<N; i++){
			if(arr[i] - k < 1 || arr[i] - k > 100)
				DP[arr[i]] = 1;
			else
				DP[arr[i]] = DP[arr[i]-k] + 1;
			
			ret = max(ret, DP[arr[i]]);
		}
	}
	
	cout << ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	run();
	return 0;
}
