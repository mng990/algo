#include<bits/stdc++.h>
#define MAX 8

using namespace std;

int N, M;

vector<int[MAX]> result;

vector<int> arr;
int pick[MAX] = {0,};
bool visited[MAX] = {false,};

void combi(int start){
	if(start == M){
		for(int i=0; i<M; i++){
			cout << pick[i] << " ";
		}
		cout << "\n";
		return;		
	}
	
	for(int i=0; i<N; i++){
		if(visited[i]) continue;
		
		visited[i] = true;
		pick[start] = arr[i]; 
		combi(start+1);
		visited[i] = false;
	}
}

int main(){
	cin >> N >> M;
	
	arr.resize(N);
	
	for(auto& num: arr) cin >> num;
	
	sort(arr.begin(), arr.end());
	
	combi(0);
	
	return 0;
}