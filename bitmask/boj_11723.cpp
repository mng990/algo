#include<bits/stdc++.h>

using namespace std;

int N, num;
string oper;

map<string,int> cmdMap;
int S = 0;
int init = (1<<21) -1;
int emptyMask = 0;

void makeCmdMap(){
	cmdMap["add"] = 1;
	cmdMap["remove"] = 2;
	cmdMap["check"] = 3;
	cmdMap["toggle"] = 4;
	cmdMap["all"] = 5;
	cmdMap["empty"] = 6;
}


void operate(string oper, int num){
	int key = cmdMap[oper];
	int mask = 1<<num;
	
	switch(key){
	case 1:
		S |= mask;
		break;
	case 2:
		if(S & mask) S ^= mask; // S &= ~(mask);
		break;
	case 3:
		if(S & mask) cout << 1 << '\n';
		else	cout << 0 << '\n';
		break;
	case 4:
		S ^= mask;
		break;
	case 5:
		S = init;
		break;
	case 6:
		S = emptyMask;
		break;					
	}
}

void run(){
	makeCmdMap();

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> oper >> num;
		operate(oper, num);
		cin.clear();
		//cout << oper << " / " << num <<'\n';
		//printArr();

	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
} 
