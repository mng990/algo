#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

ll N, ret = 0;
vector<ll> arr;
ll visited[100004] = {0,};

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		ll num;
		cin >> num;
		arr.push_back(num);
	}
}

void pickUp(){ // 전제: 중복되지 않는 연속된 수로 이루어진 조합의 수는 해당 범위의 부분집합의 수와 같다 
	ll low=0, high = 0;
		
	while(high < N){
		

		if(!visited[arr[high]]){
			visited[arr[high]] = 1; // 중복되지 않는 수라면 체크 
			high++; // high를 늘려가며 탐색 
		} 	
		else{
			ret += (high - low); // 중복되는 수를 만나면 해당 수를 포함하는 연속된 수로 이뤄진 부분집합의 수를 더함 
			visited[arr[low]] = 0; 
			low++;  // 해당 수를 빼줌(arr[low]) 
		}
		
	}
	
	ret += (high - low)*(high - low + 1)/2; // 범위 내 조건을 만족하는 부분집합의 수를 더함 
	
	cout << ret << "\n";
	return;
}

int main(){
	input();
	pickUp();
	return 0;
}
