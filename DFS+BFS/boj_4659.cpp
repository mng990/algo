#include <bits/stdc++.h>

using namespace std;

string endMessage = "end";
int continuous[26] = {0,};
map<char, bool> vowelCheck;

void init(){
	vowelCheck['a'] = true;
	vowelCheck['e'] = true;
	vowelCheck['i'] = true;
	vowelCheck['o'] = true;
	vowelCheck['u'] = true;
}


bool FnordCom(string password){
	bool option1 = false;
	bool option3 = false;
	int vcnt = 0, ccnt = 0;
	
	for(int i=0; i<password.size(); i++){
		char now = password.at(i);
		option1 = option1 || vowelCheck[now];
		
		if(vowelCheck[now] == true){
			vcnt++;
			ccnt = 0;
			
			if(vcnt == 3){
				//cout << "vowel check failed"<<endl;
				return false;
			}
		}
		else{
			ccnt++;
			vcnt = 0;
			
			if(ccnt == 3){
				//cout << "consonant check failed"<<endl;
				return false;
			}
		}
		
		if(i > 0 && (now != 'e' && now != 'o')){
			char prev = password.at(i-1);
			
			if(prev == now){
				//cout << now <<" is continuous check failed" << endl;
				return false;	
			}
		}
	}
	
	return option1;
}

void output(string word){
	if(FnordCom(word)){
		cout << "<" << word << ">" << " is acceptable." << '\n';
	}
	else{
		cout << "<" << word << ">" << " is not acceptable." << '\n';
	}
}

void run(){
	init();
	while(true){
		string word;
		cin >> word;
		if(word == endMessage) break;
		output(word);
	}
}

int main(){
	run();
	return 0;
}
