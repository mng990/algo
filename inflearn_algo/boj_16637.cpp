#include<bits/stdc++.h>

using namespace std;

int N, ret = INT_MIN;
string formula;
vector<char> operators;
vector<int> parameter;


bool opCheck(char c){
	return c == '+' || c == '*' || c == '-';
}

int getSum(int left, int right, char nowOp){
	
	if(nowOp == '+'){
		return left+right;
	}
	if(nowOp == '*'){
		return left*right;
	}
	if(nowOp == '-'){
		return left-right;
	}
}

void cal(int nowIdx, int sum){
	if(nowIdx == parameter.size() -1){
		ret = max(ret, sum);
		return;
	}

	cal(nowIdx+1, getSum(sum, parameter[nowIdx+1], operators[nowIdx])); 
	// 3*8 -> 다음 절차로 
	
	if(nowIdx+2 < parameter.size()){
		int updateSum = getSum(parameter[nowIdx+1], parameter[nowIdx+2], operators[nowIdx+1]); // (8+5)

		sum = getSum(sum, updateSum, operators[nowIdx]); // 3*(8+5)

		cal(nowIdx+2,sum);
	} 
	
	return;
}

void input(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	cin >> formula;
	
	for(int i=0; i<N; i++){
		char now = formula.at(i);
		
		if(opCheck(now)) operators.push_back(now);
		else 			 parameter.push_back(now-'0');
	}
}

void printOperators(){
	for(char op: operators){
		cout << op << endl;
	}
}

int main(){
	input();
	cal(0, parameter[0]);
	cout << ret;
	return 0;
}
