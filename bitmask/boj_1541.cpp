#include<bits/stdc++.h>

using namespace std;

vector<char> oper;
vector<int> param;
vector<string> vFormula;

string formula;
int ret = INT_MAX;


vector<string> split(const string& input, string delimiter){
	vector<string> result;
	auto start = 0;
	auto end = input.find(delimiter);
	
	while(end != string::npos){
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	result.push_back(input.substr(start));
	return result;
}

void calPlus(){
	
	for(int i=0; i<vFormula.size(); i++){
		string fstr = vFormula[i];
		
		if(fstr.find("+") == string::npos) continue;
		
		vector<string> ptemp = split(fstr, "+");
		
		int sum = stoi(ptemp[0]);
		for(int i=1; i<ptemp.size(); i++){
			int now = stoi(ptemp.at(i));
			sum += now;
		}
		
		vFormula[i] = to_string(sum);
	}
	
	return ;
}

void calMinus(){
	int sum = stoi(vFormula[0]);
	for(int i=1; i<vFormula.size(); i++){
		int now = stoi(vFormula[i]);
		sum -= now;
	}
	
	ret = sum;
}


void input(){
	cin >> formula;
	vFormula = split(formula, "-");
}


int main(){
	input();
	calPlus();
	calMinus();
	cout << ret;
	//DFS(param[0], 0);
	//bracket();
	//cout << ret;
	//printParam();
	return 0;
}
