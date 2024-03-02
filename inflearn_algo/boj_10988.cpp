#include<bits/stdc++.h>

using namespace std;
string S;

void input(){
	cin >> S;
}

bool palin(int start, int end){
	if(start >= end) return true;
	
	if(S.at(start) != S.at(end)) return false;
	
	return palin(start+1, end-1);
}

bool rPalin(){
	string rev = S;
	reverse(rev.begin(), rev.end());
	return S == rev;
}

void output(){
	//cout << palin(0, S.size()-1);
	cout << rPalin();
}

void run(){
	input();
	output();
}

int main(){
	run();
	return 0;
}
