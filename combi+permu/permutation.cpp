#include<bits/stdc++.h>

using namespace std;

vector<int> vec;
vector<int> test = {1,2,3};


void printVector(vector<int>& v){
	for(int i=0; i<v.size();i++){
		cout << v.at(i) << endl;
	}
	cout << endl;
}

void recursivePermutation(int n, int r, int depth){
	cout << n << " / " << r << " / " << depth << endl;
	
	if(r == depth){
		printVector(test); // logic
		return ;
	}
	
	for(int i = depth; i<n; i++){
		swap(test.at(i), test.at(depth)); //  swap(0,0) -> rPermutation(3, 3, 1) -> swap(1, 1) ... -> swap(r-1, r-1)
										 //									   -> swap(2, 1) ... -> swap(r-1, r-1)
										// swap(0, 1) -> rPermutation(3, 3, 1) -> swap(1, 1) .. -> swap(r-1, r-1)..
		recursivePermutation(n, r, depth+1);
		swap(test.at(i), test.at(depth)); // 기존 배열로 복구 
	}
} // nPr

void useNextPermutation(vector<int>& v){
	do{
		for(int t: test) cout << t << " ";
		cout << '\n';
		
	}while(next_permutation(test.begin(), test.end()));
	
	return ;
} 

int main(){
	
	recursivePermutation(3, 3, 0);
	
	return 0;
}
