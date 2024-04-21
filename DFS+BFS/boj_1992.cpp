#include <bits/stdc++.h>

using namespace std;

int N;
string ans = "";
int Map[68][68] = {0,};
vector<vector<int>> moveTo = {
	{0, 0}, {0, 1},
	{1, 0}, {1, 1}
};

void input(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		string data;
		cin >> data;
		for(int j=0; j<N; j++){
			Map[i][j] = data.at(j)-'0';
		}
	}
		
	return;	
}

void quardSearch(int startY, int startX, int size){	
	int endY = startY + size;
	int endX = startX + size;
	int rval = Map[startY][startX];
	bool quard = false;
	
	
	for(int i=startY; i<endY; i++){
		for(int j=startX; j<endX; j++){
			if(rval != Map[i][j]){
				int nextSize = size/2;				
				ans += '(';

				for(int mIdx=0; mIdx<moveTo.size(); mIdx++){
					int nextY = startY + moveTo.at(mIdx).at(0) * nextSize;
					int nextX = startX + moveTo.at(mIdx).at(1) * nextSize;
					 
					quardSearch(nextY, nextX, nextSize);
				}
				
				ans += ')';
				
				quard = true;
				break;
			}	
		}
		if(quard) break;
	}
	
	if(!quard) ans += to_string(rval);
	
	return;
}

string quard(int startY, int startX, int size){	
	if(size == 1) return to_string(Map[startY][startX]);
	
	int endY = startY + size;
	int endX = startX + size;
	int rval = Map[startY][startX];
	string ret = "";
	
	
	for(int i=startY; i<endY; i++){
		for(int j=startX; j<endX; j++){
			if(rval != Map[i][j]){
				int nextSize = size/2;				
				ret += '(';

				for(int mIdx=0; mIdx<moveTo.size(); mIdx++){
					int nextY = startY + moveTo.at(mIdx).at(0) * nextSize;
					int nextX = startX + moveTo.at(mIdx).at(1) * nextSize;
					 
					ret += quard(nextY, nextX, nextSize);
				}
				
				ret += ')';
				
				return ret;
			}	
		}
	}
	
	return to_string(Map[startY][startX]);
}

void output(){
	cout << ans << '\n';
}

void printMap(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N;j++){
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
}

void run(){
	input();
	//printMap();
	cout << quard(0, 0, N) << endl;
	//output();
}


int main(){
	run();
	return 0;
}
