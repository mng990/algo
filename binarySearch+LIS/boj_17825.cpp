#include<bits/stdc++.h>

using namespace std;

const int turn = 10;

vector<int> until10 = {2,4,6,8,10}; // -> until25[0], until20
vector<int> until20 = {12,14,16,18,20}; // -> until25[1], until30
vector<int> until30 = {22,24,26,28,30}; // -> until25[2], until40[0]

vector<vector<int>> until25 = {{13,16,19,25}, {22,24,25},{28,27,26,25}}; // until40[0]
vector<vector<int>> until40 = {{30, 35, 40}, {32,34,36,38,40}};
// 5 -> 4 -> 3 : นÝบน(208)
//  
void input(){
	int dice;
	
	for(int i=0; i<10; i++){
		cin >> dice;
	}
	
}


int main(){
	
	return 0;
}
