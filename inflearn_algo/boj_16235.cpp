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

vector<Tree> forest;
vector<vector<int>> spread = {
	{-1, -1}, {-1, 0}, 
	{-1, 1}, {0, -1},
	{0, 1}, {1, -1}, 
	{1, 0}, {1, 1}
};

bool forestSort(Tree left, Tree right){
	return left.age < right.age;	
}

bool rangeCheck(int y, int x){
	return 1<=y && y<=N && 1<=x && x<=N;
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
		forest.push_back(Tree({ty, tx, age}));
	}// x, y, z (나무의 위치 + 나이) 
	
	sort(forest.begin(), forest.end(), forestSort);
	
	// year section
	for(int i=0; i<K; i++){
		vector<Tree> nextYear;
		
		for(int i=0; i<forest.size();i++){
			int ty = forest.at(i).ty;
			int tx = forest.at(i).tx;
					
			if(nutrients[ty][tx] < forest.at(i).age){
				forest.at(i).age = -forest.at(i).age;
			}
			else{
				nutrients[ty][tx] -= forest.at(i).age;
				forest.at(i).age++;
				
				if(forest.at(i).age %5 == 0){
					for(int i=0; i<spread.size(); i++){
						int newY = ty + spread.at(i).at(0);
						int newX = tx + spread.at(i).at(1);
						
						if(!rangeCheck(newY, newX)) continue;
						
						nextYear.push_back(Tree({newY, newX, 1}));
					}
				}
			}
		}
		
		for(int i=0; i<forest.size();i++){
			Tree tnow = forest.at(i);
			if(tnow.age < 0){
				nutrients[tnow.ty][tnow.tx] += -tnow.age/2;
			} // summer
			else{
				nextYear.push_back(tnow);
			}
		}
		
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				nutrients[i][j] += S2D2[i][j];
			}
		}//winter
			
		forest.swap(nextYear);
		//sort(forest.begin(), forest.end(), forestSort);
	}
	
	//output section
	cout << forest.size() << '\n';
	return 0;
}
