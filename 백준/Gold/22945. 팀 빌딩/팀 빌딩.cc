#include<bits/stdc++.h>

using namespace std;

int N, ret = -1;
vector<int> dev;

void twoPointers(){
	int left = 0, right = N-1;
	
	while(left < right){
		int weak = min(dev[right], dev[left]);
		int status = weak * (right - left-1);
		ret = max(status, ret);
		
		if(weak == dev[left]) left++;
		else				  right--;
	}
}

int main(){
	cin >> N;
	dev.resize(N);
	
	for(auto& d: dev) cin >> d;

	twoPointers();
	
	cout << ret;
	
	return 0;
}