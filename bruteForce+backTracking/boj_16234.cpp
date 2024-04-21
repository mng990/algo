#include<bits/stdc++.h>

using namespace std;

int N, L, R, ret = 0, sum=0;

vector<pair<int,int>> Union;
vector<vector<int>> adj = {
	{0, 1}, {0, -1},
	{1, 0}, {-1, 0}
};

int visited[54][54] = {0,};
int nation[54][54];


void input(){
	cin >> N >> L >> R;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> nation[i][j];
		}
	}
	
}

bool rangeCheck(int y, int x){
	return 0<=y && y<N && 0<=x && x<N;
}

void printNation(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << nation[i][j] << ' '; 
		}
		cout << '\n';
	}
	cout<< '\n';
}


void printUnion(){
	for(int i=0; i<Union.size(); i++){
		cout << Union[i].first << " "<<Union[i].second << endl;
	}
	cout<< '\n';
}

void DFS(int nowY, int nowX, vector<pair<int,int>> &Union){
		
	for(int i=0; i<adj.size();i++){
		int adjY = nowY + adj.at(i).at(0);
		int adjX = nowX + adj.at(i).at(1);
		
		if(!rangeCheck(adjY, adjX)) continue;
		if(visited[adjY][adjX]) continue;
		
		int gap = abs(nation[nowY][nowX] - nation[adjY][adjX]);
		if(gap < L || gap > R) continue;
		
		visited[adjY][adjX] = 1;
		Union.push_back(make_pair(adjY, adjX));
		sum += nation[adjY][adjX];
		DFS(adjY, adjX, Union);
	}
		
	return ;
} // pop, cnt

bool exodus(){
	bool flag = false;
	for(int i=0; i<N; i++){
		for(int j=0;j<N; j++){	
			if(visited[i][j]) continue;		
			Union.clear();
			
			visited[i][j] = true;
			sum = nation[i][j];
			Union.push_back(make_pair(i,j));
			
			DFS(i,j,Union);
			
			if(Union.size()==1) continue;
			
			for(auto uni: Union){
				nation[uni.first][uni.second] = sum/Union.size();
			}
			flag = true;
			
		}
	}
	
	return flag;
}

void output(){
	cout << ret;
}

void run(){
	input();
	while(true){
		memset(visited, 0, sizeof(visited));
		
		bool flag = false;
		
		if(!exodus()) break;
		ret++;

	}
	cout << ret;
}

int main(){
	run();
	return 0;
}
