#include <bits/stdc++.h>
#define N 10


using namespace std;

vector<int> biTree;


void makeBiTree(){	
	biTree.push_back(-1);
	
	for(int i=1; i<N;i++){
		biTree.push_back(i);
	} // 1->2,3  2->4,5	 3->6,7  4->8,9 
}

void preOrder(int nowIdx){
	if(nowIdx >= biTree.size()) return;
	
	cout << biTree.at(nowIdx) << endl;
	for(int i=0; i<2; i++){
		preOrder(nowIdx*2+i);
	}
	return ;
}

void postOrder(int nowIdx){
	if(nowIdx >= biTree.size()) return;
	
	for(int i=0; i<2; i++){
		postOrder(nowIdx*2+i);
	}
	cout << biTree.at(nowIdx) << endl;
}

void inOrder(int nowIdx){
	if(nowIdx >= biTree.size()) return;

	inOrder(nowIdx*2);
	cout << biTree.at(nowIdx) << endl;
	inOrder(nowIdx*2+1);
}

void run(){
	makeBiTree();
	
	cout << "pre-order" << endl;
	preOrder(1);
	cout << "post-order" << endl;
	postOrder(1);
	cout << "in-order" << endl;
	inOrder(1);
	
	return ;
}

int main(){
	run();
	return 0;
}
