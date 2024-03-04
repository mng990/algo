#include <bits/stdc++.h>

using namespace std;

int N, rm;
vector<int> tree;
struct sortSet
{
	bool operator() (const int& left, const int& right)const
	{
		return left > right;
	}
};

set<int, sortSet> removed;

void removeVtx(){

	for(auto ridx: removed){
		tree.erase(tree.begin()+ridx);
	}
	
}

void makeRemoved(int idx){
	if(idx >= tree.size()) return;
	
	for(int i=0; i<tree.size(); i++){
		if(tree.at(i) == idx){
			makeRemoved(i);
			removed.insert(i);
		}
	}
	
	removed.insert(idx);
	
	return;
}

void printTree(){
	for(auto node: tree){
		cout << node << " ";
	}
	cout << endl;
}

int getLeaf(){
	set<int> parents;
	for(int i=0; i<tree.size(); i++){
		int parent = tree.at(i);
		if(parent != -1) parents.insert(parent);
	}
	
	return tree.size() - parents.size();
}

void run(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		int key;
		cin >> key;
		tree.push_back(key);
	}
	cin >> rm;
	makeRemoved(rm);
	removeVtx();
	//printTree();
	cout << getLeaf();
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    run();
	return 0;
} 
