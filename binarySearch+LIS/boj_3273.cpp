#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, X, sum = 0, ret = 0;
vector<ll> arr;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	cin >> X;
	
	sort(arr.begin(), arr.end());
}

void pickUp(){
	int low = 0, high = N-1;
	
	while(low < high){
		sum = arr[low] + arr[high];
		
		if(sum < X){
			low++;
		}
		else if(sum > X){
			high--;
		}
		else{
			ret++;
			low++;		
		}
	}
	
	cout << ret << "\n";
	
}

int main(){
	input();
	pickUp();
	return 0;
} 
