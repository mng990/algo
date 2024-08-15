#include<bits/stdc++.h>
#define MAX 10000

using namespace std;

int N, M, dis = -1;

vector<int> arr;


int binarySearch(){
	int start =0, end = MAX, ret = MAX;
	
	while(start<=end){
		int mid = (start+end)/2;
		
		int minN = arr.front(), maxN = arr.front();
		int cnt = 1;
		for(int i=0; i<arr.size(); i++){
			minN = min(minN, arr[i]);
			maxN = max(maxN, arr[i]);
			
			if(maxN - minN > mid){
				cnt++;
				minN = maxN = arr[i];
			}
		}
		
		if(cnt <= M){
			ret = min(ret, mid);
			end = mid - 1;
			continue;
		}
		
		start = mid + 1;
	}
	
	return ret;
	
}

int main(){
	cin >> N >> M;
	arr.resize(N);
	
	for(auto& num: arr){
		cin >> num;
	}
	
	cout << binarySearch();
	
	return 0;
}