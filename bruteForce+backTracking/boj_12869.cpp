#include<bits/stdc++.h>

using namespace std;

int N, ret;
int life[64][64][64] = {0,};


struct scv{
	int scv1=0;
	int scv2=0;
	int scv3=0;
	
	int& operator[] (int idx) { return *(&scv1 + idx);}	
}typedef SCV;
 
SCV init;
vector<int> attack = {1, 3, 9};
vector<vector<int>> combo;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> init[i];
	}
}

void makeCombo(){
	do{
		combo.push_back(attack);
		
	}while(next_permutation(attack.begin(), attack.end()));	
}

void BFS(){
	queue<SCV> queSCV;
	queSCV.push(init);
	
	life[init[0]][init[1]][init[2]] = 0;
	while(!queSCV.empty()){
		SCV now = queSCV.front();
		
		for(int i=0; i<combo.size();i++){
			SCV next = now;			
						
			for(int j=0; j<3; j++){
				if(next[j] <= 0) continue;

				next[j] -= combo.at(i).at(j);
				next[j] = max(0, next[j]);
			}
			
			if(life[next[0]][next[1]][next[2]]) continue;
			
			life[next[0]][next[1]][next[2]] = life[now[0]][now[1]][now[2]]+1;
						
			if(life[0][0][0]){
				ret = life[0][0][0];
				return;
			}
			
			
			queSCV.push(next);
		}
		
		queSCV.pop();	
	}
}




void run(){
	input();
	makeCombo();
	BFS();
	cout << ret;
	
	
	//cout << ret;
}


int main(){
	run();
	return 0;
}
