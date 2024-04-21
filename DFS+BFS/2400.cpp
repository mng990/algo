#include<bits/stdc++.h>

using namespace std;

int N;

void run(){
	cin >> N;
	int num = 2400;
	string strNum = to_string(2400);

	for(int i=1; i<=N;){
		string strNow = to_string(num);
		if(strNow.find("2400") != string::npos){
			i++;
		}
		num++;
	}
	
	cout << num-1;
}
 

int main(){
	run();
	return 0;
}
