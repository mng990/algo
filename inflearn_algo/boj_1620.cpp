#include<bits/stdc++.h>

using namespace std;

int N, M, pnum;

map<string, int> pokeDic;
vector<string> pokeVec;
vector<string> problem;

string poke, pokeCode;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	
	pokeVec.push_back("");
	
	for(int i=1; i<=N; i++){		
		cin >> poke;
		
		pokeVec.push_back(poke);
		pokeDic[poke] = i;
		
	}
	
	for(int i=0; i<M; i++){
		cin >> pokeCode;
		int nowInt = atoi(pokeCode.c_str());
		
		if(nowInt == 0){
			cout << pokeDic[pokeCode] << '\n';
		}
		else{
			cout << pokeVec[nowInt] << '\n';
		}
	}
	
	return 0;
}
