#include<bits/stdc++.h>

using namespace std;


int N, M, K;
int S2D2[14][14];
int nutrients[14][14];

struct tree{
	int ty;
	int tx;
	int age;
}typedef Tree;

deque<Tree> forest;
vector<vector<int>> spread = {
	{-1, -1}, {-1, 0}, 
	{-1, 1}, {0, -1},
	{0, 1}, {1, -1}, 
	{1, 0}, {1, 1}
};

bool forestSort(Tree left, Tree right){
	return left.age > right.age;	
}

bool rangeCheck(int y, int x){
	return 1<=y && y<=N && 1<=x && x<=N;
}

void printYear(int k){
	cout << "year: " << k << '\n';
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << nutrients[i][j]<<' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	//input section
	cin >> N >> M >> K;

	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			cin >> S2D2[i][j];
			nutrients[i][j] = 5;
		}
	}
	
	for(int i=0; i<M; i++){
		int tx, ty, age;
		cin >> tx >> ty >> age; 
		forest.push_back({ty, tx, age});
	}// x, y, z (나무의 위치 + 나이) 
	
	sort(forest.begin(), forest.end(), forestSort);
	
	// year section
	int death = 0;
	for(int i=0; i<K; i++){
		printYear(i+1);

		for(int i=forest.size()-1; i>=0; i--){
			int ty = forest[i].ty;
			int tx = forest[i].tx;
			if(forest[i].age <= 0) continue;
					
			if(nutrients[ty][tx] < forest[i].age){
				forest[i].age *= -1;
				death++;
			}
			else{
				nutrients[ty][tx] -= forest[i].age;
				forest[i].age++;
				
				if(forest[i].age %5 == 0){
					for(int i=0; i<spread.size(); i++){
						int newY = ty + spread[i][0];
						int newX = tx + spread[i][1];
						
						if(!rangeCheck(newY, newX)) continue;
						
						forest.push_back({newY, newX, 1});
					}
				}
			}
		}
		
		for(int i=0; i<forest.size();i++){
			if(forest[i].age < 0){
				nutrients[forest[i].ty][forest[i].tx] += abs(forest[i].age)/2;
				forest[i].age = 0;
			} // summer
		}
		
		
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				nutrients[i][j] += S2D2[i][j];
			}
		}//winter
	}
	
	//output section
	cout << forest.size()-death << '\n';
	return 0;
}
