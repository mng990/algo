#include <bits/stdc++.h>

using namespace std;

vector<string> fruit= {"사과", "딸기", "포도", "배"};



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
