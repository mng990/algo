#include<bits/stdc++.h>

using namespace std;

int N, sum = 0, ret = INT_MIN;

void run(){
	cin >> N;
	
	for(int i=1; i<=N; i++){
		int num;
		cin >> num;
		sum += num;
		ret = max(ret, sum); // ���������� ���ذ��� ret�� �Ź� ������Ʈ 
		if(sum < 0) sum = 0; // �������� ������ ��� �ʱ�ȭ 
	}
	
	cout << ret;
}




int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
