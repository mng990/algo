#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int N, S;
ll ret = 0;
vector<int> arr;

vector<int> ls; // 0 ~ N/2-1
vector<int> rs; // N/2 ~ N-1

map<int, int> dup;

void binarySearch(int target, int s, int e){
	if(s > e) return;
	
	int mid = (s+e)/2;
	
	if(target > rs[mid]){
		return binarySearch(target, mid+1, e);
	}
	
	if(target < rs[mid]){
		return binarySearch(target, s, mid-1);
	}
	
	ret += dup[rs[mid]];
	return;
}

int main(){
	cin >> N >> S;
	
	arr.resize(N);
	
	for(int i=0; i<N; i++) 
		cin >> arr[i];
	
	int half = N/2;
	
	for(int mask=1; mask < 1 << half; mask++){
		int left  = 0;
		int right = 0;
		
		for(int i=0; i < half; i++){
			if(mask & (1<<i)){
				left  += arr[i];
				right += arr[i+N/2];
			}
				
		}
		
		ret += (left == S) + (right == S);
		
		ls.push_back(left);
		rs.push_back(right);
		
		if(N%2){
			int additional = right + arr.back();
			
			rs.push_back(additional);
			ret += (S == additional);
			dup[additional]++;
		}
		
		dup[right]++;
 	}
 	
 	if(N%2){
 		dup[arr.back()]++;
 		ret += (S == arr.back());
 		rs.push_back(arr.back());
	 }
	
	sort(rs.begin(), rs.end());
	
	for(int i=0; i < ls.size(); i++){
		binarySearch(S - ls[i], 0, rs.size()-1);
	}
	
	cout << ret;
		
	return 0;
}