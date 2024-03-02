#include<bits/stdc++.h>
using namespace std;

string S;
map<char,int> dic;

void input(){
	cin >> S;
}

void makeDic(){
	for(int i=0; i<S.size(); i++){
		char c = S.at(i);
		dic[c] = dic[c]+1;
	}
}

void output(){
	for(int i=0; i<26; i++){
		char key = 'a' + i;
		cout << dic[key] << " ";
	}
}

void run(){
	input();
	makeDic();
	output();
}

int main(){
	run();
	return 0;
}
