#include <bits/stdc++.h>

using namespace std;

vector<string> fruit= {"���", "����", "����", "��"};



void combi(){
	for(int i=0; i<(1 << fruit.size()); i++){
		for(int j=0; j<fruit.size();j++){
			if(i &(1<<j)){
				cout << fruit.at(j) << ' ';
			}
		}
		cout << '\n';
	}	
}

int main(){
	combi();
	return 0;
}
