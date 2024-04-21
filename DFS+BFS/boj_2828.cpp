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
		int right = left + M -1; // left�� �������� �����̱⿡ right�� �Ź� �ʱ�ȭ 
		int apple = appleTree.at(i);
		
		if(left <= apple && apple <= right) continue;
		else{
			if(apple < left){
				ret += (left - apple);
				left = apple;
			} // ����� ��ġ�� left �̸��̸� �� ���̸�ŭ �̵� 
			else{
				left += (apple - right);
				ret += (apple - right);
			} // ����� ��ġ�� right�� �ʰ��ϸ� �� ���̸�ŭ �̵� 
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
