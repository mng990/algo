#include<bits/stdc++.h>

using namespace std;

int N, ans = 0;
vector<string> report;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		string word;
		cin >> word;
		report.push_back(word);
	}	
}

void goodWord(string now){
	stack<char> vertical;
	
	for(int i=0; i<now.size(); i++){
		if(vertical.empty()){
			vertical.push(now.at(i));
			continue;
		}
		
		char alpha = vertical.top();
		
		if(alpha == now.at(i)){
			vertical.pop();
		}
		else{
			vertical.push(now.at(i));
		}
	}
	
	if(vertical.empty()){
		ans++;
		//cout << now <<" is goodWord!!" << endl;
	}
	
	return;
}

void output(){
	cout << ans;
}

void run(){
	input();
	for(int i=0; i<report.size(); i++){
		goodWord(report.at(i));
	}
	
	output();
}

int main(){
	run();
	return 0;
}
