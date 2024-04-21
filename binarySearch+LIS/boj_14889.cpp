#include<bits/stdc++.h>

using namespace std;

int N, ret = INT_MAX;
int Map[24][24];

void input(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> Map[i][j];
			
		} // power[101] = Map[2][1] + Map[1][2]
	}
}

int getDist(vector<int> start, vector<int> link){
	int SP = 0, LP = 0;
	
	for(int i=0; i<N/2; i++){
		for(int j=i+1; j<N/2; j++){
			int sIdx1 = start[i], sIdx2 = start[j];
			int lIdx1 = link[i], lIdx2 = link[j];
			
			SP += Map[sIdx1][sIdx2] + Map[sIdx2][sIdx1];
			LP += Map[lIdx1][lIdx2] + Map[lIdx2][lIdx1];
		}
	}
	
	return abs(SP - LP);
}

void makeTeam(){
	for(int team = 0; team < 1<<N; team++){
		
		if(__builtin_popcount(team) != N/2) continue;
		
		vector<int> start, link;
		
		for(int j=0; j<N; j++){
			if(team & 1<<j) start.push_back(j);
			else 			link .push_back(j);
		}
		
		ret = min(ret, getDist(start, link));
	}
	
	return;
}

void run(){
	input();
	makeTeam();
	cout << ret << "\n";	
}

int main(){
	run();
	return 0;
}
