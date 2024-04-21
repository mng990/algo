#include<bits/stdc++.h>

using namespace std;

string S, ans;
int alphaDic[100] = {0,};
int oddCnt = 0;

void input(){
	cin >> S;
}

bool canPalin(){
	for(int i=0; i<S.size(); i++){
		alphaDic[S.at(i)]++;	
	}
	
	for(int i='A'; i <= 'Z'; i++){
		if(alphaDic[i] % 2){
			oddCnt++;
		} 
		if(oddCnt > 1) return false;
	}
	
	return true;
}

void makePalin(){
	if(!canPalin()){
		ans = "I'm Sorry Hansoo\n";
		return;
	}
	
	for(int i = 'Z'; i >= 'A'; i--){
		int cnt = alphaDic[i];
		
		if(cnt == 0) continue;
				
		if(cnt % 2){
			int mid = ans.size()/2;
			ans.insert(mid, 1, (char)i);
		}
		
		cnt /= 2;
		
		for(int j=0; j < cnt; j++){
			ans.insert(0, 1, (char)i);
			ans.push_back((char)i);
		}
	}
	
	return;
}

void output(){
	cout << ans;
}

void run(){
	input();
	makePalin();
	output();
}

int main(){
	run();
	return 0;
}
