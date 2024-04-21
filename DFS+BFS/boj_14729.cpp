#include<bits/stdc++.h>

using namespace std;


int N;
double score;

priority_queue<double> chillMuHae;
vector<double> ret;


void run(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> score;
		chillMuHae.push(score);
		
		if(chillMuHae.size() > 7){
			chillMuHae.pop(); // 가장 큰 값을 pop 
		}
	}
	
	while(!chillMuHae.empty()){
		ret.push_back(chillMuHae.top());
		//cout << chillMuHae.top() << "\n";
		chillMuHae.pop();
	}
	
	
	
	for(int i=ret.size()-1; i>=0; i--){
		printf("%.3lf\n", ret[i]);
		//cout << ret[i] << "\n";
	}
}

int main(){
	run();
	return 0;
}
