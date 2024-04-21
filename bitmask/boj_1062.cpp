#include<bits/stdc++.h>

using namespace std;

int N,K, ret = 0;
int edu[26] = {0,};
int visited[54][26] = {0,};
int req[54][26];

int language[54];

int translate(string str){
	int strMask = 1;
	for(int i=0; i<str.size(); i++){
		strMask |= 1 << (str[i] - 'a');
	}	
	return strMask;
}

void input(){
	cin >> N >> K;
	
	if(K < 5){
		cout << 0;
		exit(0);
	}
	
	for(int i=0; i<N; i++){
		string input;
		cin >> input;
		language[i] = translate(input);
	}	
}

void education(int start, int eduMask, int size){
	if(size == K){
		int cnt = 0;
		for(int i=0; i<N; i++){
			int lcheck = language[i] | eduMask;
			if(lcheck == eduMask) cnt++;
		}
		
		ret = max(ret, cnt);
		return;
	}
	
	
	for(int i=start; i<26; i++){
		eduMask |= 1<<i; 
		education(i+1, eduMask, size+1);
		eduMask ^= 1<<i;
	}
}

void printLanguage(){
	for(int i=0; i<N; i++){
		cout << language[i] << '\n';
	}
}

int main(){
	input();
	education(0, 0, 0);
	cout << ret;
	return 0;
}
