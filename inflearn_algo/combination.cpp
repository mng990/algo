#include<bits/stdc++.h>

using namespace std;

vector<int> vec = {1, 2, 3, 4, 5};
vector<int> combi;
int n= vec.size();
int r = 3;

void printCombi(){
	for(int i=0; i<combi.size(); i++){
		//cout << vec.at(combi.at(i)) << " ";
		cout << combi.at(i) << " ";
	}
	cout << endl;
	return ;
}

void recursiveCombi(int start){
	if(combi.size() == r){
		printCombi();
		return;
	} // r개 뽑힐 때까지 반복 
	
	for(int i=start+1; i<n; i++){
		combi.push_back(i);
		recursiveCombi(i); // combi(0) -> push_back(1) -> combi(1) -> push_back(2) -> combi(2) -> push_back(3)
							// 		   							   -> push_back(3) -> combi(3) -> push_back(4)
		combi.pop_back();
	}
} // nCr (index를 선택, initStart = -1)

void repeatCombi(){
	for(int i=0; i<n; i++){
		for(int j= i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				cout << i << " "<< j << " "<< k << endl;
			}
		}
	}
	printCombi();
} 

int main(){
	recursiveCombi(-1);
	cout << endl;
	repeatCombi();
	return 0;
}
