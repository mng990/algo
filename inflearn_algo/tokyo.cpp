#include<bits/stdc++.h>

using namespace std;


int N, ans=0;
int numbers[104];
vector<int> combi;

bool isPrime(int num){
	if(num < 2) return false;
	if(num % 2 == 0) return false;
	for(int i=2; i*i<=num; i++){
		if(num % i == 0) return false;
	}
	return true;
}

void getCombi(int start, int size){
	if(combi.size() == size){
		int sum = 0;
		for(int i=0; i<combi.size(); i++){
			sum += numbers[combi.at(i)];
		}
		if(isPrime(sum)) ans++;
		return ;
	}
	
	for(int i = start+1; i<N;i++){
		combi.push_back(i);
		getCombi(i, size);
		combi.pop_back();
	}
}

int go(int idx, int sum){
	if(idx == N){
		return isPrime(sum);
	}
	return go(idx+1, sum+numbers[idx]) + go(idx+1, sum);
}

void run(){
	
	
	cin >> N;
	
	for(int i=0; i<N;i++){
		cin >> numbers[i];
	}
	
	for(int i=1; i<=N; i++){
		getCombi(-1, i);
	}
	
	//ans = go(0, 0);
	
	cout << ans;
}

int main(){
	run();
	return 0;
}
