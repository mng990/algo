#include<bits/stdc++.h>

using namespace std;


queue<pair<int,int>> nowQue; // start, end
queue<pair<int, int>> nextQue;
vector<int> biTree;

int N;

void input(){
	cin >> N;
	
	for(int i=0; i < pow(2,N)-1; i++){
		int data;
		cin >> data;
		biTree.push_back(data);
	} 
}

void Qclear(queue<pair<int,int>>& que){
	queue<pair<int,int>> empty;
	swap(que, empty);
}

void inorder(){
	nowQue.push({0, biTree.size()-1});
	pair<int,int> now;
	bool stop = false;
	
	while(true){
		
		while(!nowQue.empty()){
			now = nowQue.front();
			nowQue.pop();
			
			int start = now.first, end = now.second;
			int mid = (start+end)/2;
			
			cout << biTree.at(mid) << " ";
			
			if(start >= end){
				stop = true;
				continue;
			}
			
			pair<int,int> left = make_pair(start, mid-1);
			pair<int,int> right = make_pair(mid+1, end);
			
			nextQue.push(left);
			nextQue.push(right);
			
		}
		if(stop) break;
		
		nowQue = nextQue;
		Qclear(nextQue);
		cout << '\n';
	}
	
	
}

int main(){
	input();
	inorder();
	return 0;
}
