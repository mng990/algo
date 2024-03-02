#include <bits/stdc++.h>

using namespace std;

int N, M, J, ret =0;
vector<int> appleTree;

void input(){
	cin >> N >> M >> J;
	for(int i=0; i<J; i++){
		int apple;
		cin >> apple;
		appleTree.push_back(apple);
	}
}

void move(){
	int left = 1;
	
	for(int i=0; i<appleTree.size();i++){
		int right = left + M -1; // left를 기준으로 움직이기에 right를 매번 초기화 
		int apple = appleTree.at(i);
		
		if(left <= apple && apple <= right) continue;
		else{
			if(apple < left){
				ret += (left - apple);
				left = apple;
			} // 사과의 위치가 left 미만이면 그 차이만큼 이동 
			else{
				left += (apple - right);
				ret += (apple - right);
			} // 사과의 위치가 right를 초과하면 그 차이만큼 이동 
		}
		
	}
	return ;
}

void output(){
	cout << ret << '\n';
}

void run(){
	input();
	move();
	output();
}

int main(){
	run();
	return 0;
}
