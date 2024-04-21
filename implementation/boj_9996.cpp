#include<bits/stdc++.h>

using namespace std;

int N, widx;
string wc, wsub1, wsub2;
vector<string> file;


void getWsub(){
	for(widx=0; widx<wc.size(); widx++){
		if(wc.at(widx) == '*') break;
	}
	
	wsub1 = wc.substr(0, widx);
	wsub2 = wc.substr(widx+1);
	
	return ;
}

void input(){
	cin >> N;
	cin >> wc;
	for(int i=0; i<N; i++){
		string str;
		cin >> str;
		file.push_back(str);
	}
	getWsub();
}



bool wildcard(string nowStr){
	if(wsub1.size() + wsub2.size() > nowStr.size()) 
		return false;
		
	if(wsub1 == nowStr.substr(0, wsub1.size()) && 
		wsub2 == nowStr.substr(nowStr.size()-wsub2.size(), wsub2.size()))
		return true;
	
	return false;
}



void run(){
	input();
	for(int i=0; i<file.size(); i++){
		string strNow = file.at(i);
		
		if(wildcard(strNow)){
			cout << "DA" << endl;
		}
		else cout << "NE" << endl;
	}
}

int main(){
	run();
	return 0;
}
