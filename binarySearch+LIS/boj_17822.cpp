#include <bits/stdc++.h>

using namespace std;


int N, M, T, ret = 0;

typedef struct rotate{
	int x;
	int dir;
	int k;
} R;

vector<vector<int>> discSet;
vector<R> vecRotate;

void rotateDisc(vector<int>& disc, R rdata){
	int k = rdata.k;
	int dir = rdata.dir;
	
	vector<int> newDisc(disc.size());
	
	if(dir == 0){
		for(int i=0; i<M; i++){
			int adj = (i+k)%M;
			
			newDisc[adj] = disc[i];
		}
	}
	else{
		for(int i=0; i<M; i++){
			int adj = i-k;
			if(adj < 0) adj += M;
			
			newDisc[adj] = disc[i];
		}
	}
	
	disc = newDisc;
	
	return ;
}

void meanSet(vector<vector<int>>& discSet, double mean){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(discSet[i][j] == 0) continue;
			
			if(discSet[i][j] < mean) discSet[i][j]++;
			else if(discSet[i][j] > mean) discSet[i][j]--;
		}
	}
}


void adjDelete(){
	vector<vector<int>> newDiscSet(N,vector<int>(M));
	int sum = 0;
	int cnt = 0;
	bool isDeleted = false;
	
	for(int i=0; i < N; i++){
		
				
		for(int j=0; j<M; j++){
			if(discSet[i][j] == 0) continue;
			
			int adjR = (j+1)%M;
			int adjL = j-1;
			int adjUp = i+1;
			int adjDown = i-1;
			
			if(adjL < 0) adjL += M;
						
			if(discSet[i][j] == discSet[i][adjR]){
				newDiscSet[i][j] = 0;
				isDeleted = true;
			}
			else if(discSet[i][j] == discSet[i][adjL]){
				newDiscSet[i][j] = 0;
				isDeleted = true;
			}
			else if(adjUp < N && discSet[i][j] == discSet[adjUp][j]){
				newDiscSet[i][j] = 0;
				isDeleted = true;
			}
			else if(adjDown >= 0 && discSet[i][j] == discSet[adjDown][j]){
				newDiscSet[i][j] = 0;
				isDeleted = true;
			}
			else{
				newDiscSet[i][j] = discSet[i][j];
				sum += discSet[i][j];
				cnt++;
			}
			
			//sum += discSet[i][j];
		}	
	}
	
	if(isDeleted == false) meanSet(newDiscSet, (double)sum/cnt);
	
	copy(newDiscSet.begin(), newDiscSet.end(), discSet.begin());
	
	return ;
}

void rotate(R rdata){
	
	for(int i=0; i<N; i++){
		if((i+1) % rdata.x == 0){
			rotateDisc(discSet[i], rdata);
		}	
	}
	
	adjDelete();
	
	return ;
}

void printDisc(){
	cout << "\n";
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << discSet.at(i).at(j) << " ";
		}
		cout << "\n";
	}
}

void getSum(){
	for(int i=0; i<discSet.size(); i++){
		for(int j=0; j<discSet.at(i).size(); j++){
			ret += discSet[i][j];
		}
	}
}

void input(){
	cin >> N >> M >> T;
	
	for(int i=0; i<N; i++){
		vector<int> disc;
		
		for(int j=0; j<M; j++){
			int num;
			cin >> num;
			disc.push_back(num);
		}
		discSet.push_back(disc);
	}
	
	for(int i=0; i<T; i++){
		R rdata;
		cin >> rdata.x >> rdata.dir >> rdata.k;
		vecRotate.push_back(rdata);
	}
	
	return ;
}

void output(){
	cout << ret;
}

void run(){
	input();
	for(int i=0; i<vecRotate.size(); i++){
		rotate(vecRotate[i]);
	}
	getSum();
	output();
}

int main(){
	run();
	return 0;
}
