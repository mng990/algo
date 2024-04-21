#include<bits/stdc++.h>

using namespace std;

string split(string str, string delimeter){
	string ret;
	
	int start = 0;
	int end = str.find(delimeter);
	string dl = "";
	
	if(delimeter != "/") dl = "/";
		
	while(end != string::npos){
		ret += str.substr(start, end-start) + dl;
		start = end + delimeter.size();
		end = str.find(delimeter, start);
	}
	
	ret += str.substr(start);
	
	
	return ret;
}

vector<string> pika = {"pi", "ka", "chu"};

int main(){
	string str;
	cin >> str;
	
	for(int i=0; i<pika.size(); i++){
		str = split(str, pika[i]);
	}
	
	//cout << str << endl;
	str = split(str, "/");
	
	if(str.empty()) cout << "YES";
	else			cout << "NO";	

	
	return 0;
}
