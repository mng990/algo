#include<bits/stdc++.h>

using namespace std;


vector<int> A;
vector<int> B;
vector<int> ret;
string strA, strB;

vector<int> normalize(vector<int>& vecA){
	vecA.push_back(0);
	
	for(int i=0; i<vecA.size()-1;i++){
		vecA[i+1] += vecA[i]/10;
		vecA[i] %= 10;
	}
	
	if(vecA[vecA.size()-1] == 0)
		vecA.pop_back();
	
	while(vecA.size() > 1 && vecA.back() == 0) vecA.pop_back();
	
	return vecA;
}


vector<int> sum(vector<int>& vecA, vector<int>& vecB){
	if(vecA.size() > vecB.size()){
		return sum(vecB, vecA);
	} // A로 전달되는 벡터가 무조건 작게
	
	for(int i=vecA.size(); i<vecB.size(); i++){
		vecA.push_back(0);
	} 
	vecA.push_back(0);
	
	for(int i=0; i<vecB.size(); i++){
		vecA[i] += vecB[i];
	}

	return normalize(vecA);
}


int main(){
	string strRet = "";
	cin >> strA >> strB;
	
	for(int i = strA.size()-1; i>=0; i--){
		A.push_back(strA[i] - '0');
	}
	
	for(int i = strB.size()-1; i>=0; i--){
		B.push_back(strB[i] - '0');
	}
	
	ret = sum(A, B);
	
	for(int i=ret.size()-1; i>=0; i--){
		strRet += to_string(ret[i]);
	}
	
	cout << strRet;
	
	return 0;
}
