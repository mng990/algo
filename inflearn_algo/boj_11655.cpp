#include<bits/stdc++.h>

using namespace std;
string S;

void ROT13(){
	//S.pop_back();	
	for(int i=0; i<S.size(); i++){

		if(S.at(i) >= 'A' && S.at(i) <= 'Z'){
			S.at(i) += 13;

			if(S.at(i) > 'Z')
				S.at(i) = S.at(i) - 26;
		}
		else if(S.at(i) >= 'a' && S.at(i) <= 'z' ){
			S.at(i) += 13;

			if(S.at(i) > 'z')
				S.at(i) = S.at(i) - 26;
		}
		
		cout << S.at(i);
	}	
		
	return;
}

void input(){
	getline(cin ,S);
}

void run(){
	input();
	ROT13();
}

int main(){
	run();
	return 0;
}
