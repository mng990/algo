#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> paper;
vector<string> answer;

bool sortFlag(string str1, string str2){
	bool retFlag = false;
	if(str1.size() != str2.size())
		return str1.size() < str2.size();
	else{
		for(int i=0; i<str1.size();i++){
			if(str1[i] != str2[i])
				return str1[i] < str2[i];
		}
		
		return false;
	}
}


void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		string word;
		cin >> word;
		paper.push_back(word);
	}
}

void getMaxInt(string word){
	string prev = "";
	bool update = false;
	char now;
	
	for(int i=0; i<word.size(); i++){
		now = word.at(i);
		
		if(now >= 'a' && now <= 'z'){
			if(update) answer.push_back(prev);
			prev = "";
			update = false;
			continue;
		}	
		
		if(prev == "0") prev = now;
		else			prev += now;
		update = true;		
	}
	
	if(update)
		answer.push_back(prev);
		
	return ;
}

void output(){
	sort(answer.begin(), answer.end(), sortFlag);
	for(int i=0; i<answer.size(); i++){
		cout << answer.at(i) << endl;
	}
}

void run(){
	input();
	for(auto word: paper){
		getMaxInt(word);
	}
	output();
}

int main(){
	run();
	return 0;
}
