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

void pickUp(){ // ����: �ߺ����� �ʴ� ���ӵ� ���� �̷���� ������ ���� �ش� ������ �κ������� ���� ���� 
	ll low=0, high = 0;
		
	while(high < N){
		

		if(!visited[arr[high]]){
			visited[arr[high]] = 1; // �ߺ����� �ʴ� ����� üũ 
			high++; // high�� �÷����� Ž�� 
		} 	
		else{
			ret += (high - low); // �ߺ��Ǵ� ���� ������ �ش� ���� �����ϴ� ���ӵ� ���� �̷��� �κ������� ���� ���� 
			visited[arr[low]] = 0; 
			low++;  // �ش� ���� ����(arr[low]) 
		}
		
	}
	
	ret += (high - low)*(high - low + 1)/2; // ���� �� ������ �����ϴ� �κ������� ���� ���� 
	
	cout << ret << "\n";
	return;
}

int main(){
	input();
	pickUp();
	return 0;
}
