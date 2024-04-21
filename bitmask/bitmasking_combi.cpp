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
} // for(int r=0; r<n; i++) cout << nC(r+1);

void appleCombi(int mask){
	string ret = "";
	for(int i=0; i<fruit.size();i++){
		if(mask & (1<<i)) ret += fruit[i] + " "; // i번째 원소가 포함되었다면 출력 
	}
	cout << ret << '\n';
}


int main(){
	cout << "combi 1" << '\n';
	combi();
	cout << '\n'<< "combi 2" << '\n';
	for(int i=1; i<fruit.size(); i++){
		appleCombi(1 | (1<<i)); // 사과를 반드시 포함하는 한 쌍을 출력(ex. 1001-> 사과, 배) 
	}
	return 0;
}
// n <= 31까지만 가능(-2^31 <= int <= 2^31) 
