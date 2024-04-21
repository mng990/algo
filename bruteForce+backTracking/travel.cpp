#include<bits/stdc++.h>

using namespace std;


int money = 0;

vector<vector<int>> Map = {
	{10, 20, 21},
	{70, 90, 12},
	{80, 110, 120}
};

vector<vector<int>> moveTo = {
	{1,  0}, {0, 1},
	{-1, 0}, {0, -1}
};

vector<int> path;

int visited[3][3] = {0, };

bool goal(int y, int x){
	return y == 2 && x == 2;
}

bool rangeCheck(int y, int x){
	return 0<=y && y<3 && 0<=x && x<3;
}

void travel(int y, int x){
	if(goal(y,x)){
		for(int i=0; i<path.size(); i++){
			cout << path.at(i) << " ";
		}
		cout << '\n';
		
		cout << "total: " << money << '\n'<< '\n';
		return ; 
	}
	
	for(int i=0; i<moveTo.size(); i++){
		int nextY = y + moveTo.at(i).at(0);
		int nextX = x + moveTo.at(i).at(1);
		
		if(!rangeCheck(nextY, nextX)) continue;
		if(visited[nextY][nextX]) continue;
		
		visited[nextY][nextX] = true;
		money += Map[nextY][nextX];
		path.push_back(Map[nextY][nextX]);
		
		travel(nextY, nextX);
		
		money -= Map[nextY][nextX];
		visited[nextY][nextX] = false;
		path.pop_back();
	}
	
	return;
}

int main(){
	visited[0][0] = true;
	money += Map[0][0];
	path.push_back(Map[0][0]);
	travel(0, 0);

	return 0;
}
