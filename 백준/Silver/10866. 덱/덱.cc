#include<bits/stdc++.h>

using namespace std;


int N, num;

deque<int> deq;
string method;

vector<string> split(string input, string delimiter){
	auto start = 0;
	auto end   = input.find(delimiter);
	vector<string> ret;
	
	while(end != string::npos){
		ret.push_back(input.substr(start, end-start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);	
	}
	
	ret.push_back(input.substr(start));	
	return ret;
}

void runMethod(string& method, int& n){
	if(method == "push_back"){
		deq.push_back(n);
	}
	
	if(method == "push_front"){
		deq.push_front(n);
	}
	
	if(method == "front"){
		if(deq.empty()) cout << -1 << "\n";
		else			cout << deq.front() << "\n";
	}
	
	if(method == "back"){
		if(deq.empty()) cout << -1 << "\n";
		else			cout << deq.back() << "\n";
	}
	
	if(method == "pop_front"){
		if(deq.empty()) cout << -1 << "\n";
		else {
			cout << deq.front() << "\n";
			deq.pop_front();	
		}
	}
	
	if(method == "pop_back"){
		if(deq.empty()) cout << -1 << "\n";
		else{
			cout << deq.back() << "\n";
			deq.pop_back();
		}
	}
	
	if(method == "empty"){
		if(deq.empty()) cout << 1 << "\n";
		else			cout << 0 << "\n";
	}
	
	if(method == "size"){
		cout << deq.size() << "\n";
	}
}


int main(){
	cin >> N;
	
	for(int i=0; i<N; i++) {
		
		cin >> method;
		if(method == "push_back" || method == "push_front"){
			cin >> num;
		}
		
		runMethod(method, num);
	}
	
	return 0;
}