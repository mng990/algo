#include<bits/stdc++.h>

using namespace std;

int N, maxInt = INT_MIN, minInt = INT_MAX;

vector<char> vecOp;
vector<int> number = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<string> ans({"0", "999999999"});

bool operator<(string str1, string str2){
	if(str1.size() != str2.size())
		return str1.size() < str2.size();
	else{
		for(int i=0; i<str1.size(); i++){
			if(str1.at(i) != str2.at(i))
				return str1.at(i) < str2.at(i);
		}
		
		return false;
	}
}

bool oper(int idx){
	char nowOp = vecOp.at(idx);
	
	if(nowOp == '<') return number.at(idx) < number.at(idx+1);
	else			 return number.at(idx) > number.at(idx+1);
}

void getAns(){
	do{
		bool update = true;
		
		string now = "";
		for(int i=0; i<vecOp.size(); i++){
			update = update && oper(i);
			now += (char)(number.at(i)+'0');
			if(!update) break;	
		}
		
		now += (char)(number.at(N)+'0');
		
		
		
		if(update){
			if(ans[0] < now){
				ans[0] = now;
			}
			if(ans[1] > now){
				ans[1] = now;
			}
		}
		
	}while(next_permutation(number.begin(), number.end()));
}

void input(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		char op;
		cin >> op;
		vecOp.push_back(op);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	input();
	getAns();
	cout << ans[0] << '\n';
	cout << ans[1] << '\n';
	 return 0;
}
