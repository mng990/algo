#include <bits/stdc++.h>

using namespace std;

vector<string> fruit= {"���", "����", "����", "��"};

void combi(){
	for(int i=0; i<(1 << fruit.size()); i++){
		for(int j=0; j<fruit.size();j++){
			if(i &(1<<j)){
				cout << fruit.at(j) << ' ';
			}
		}
		cout << '\n';
	}	
} // for(int r=0; r<n; i++) cout << nC(r+1);

void appleCombi(int mask){
	string ret = "";
	for(int i=0; i<fruit.size();i++){
		if(mask & (1<<i)) ret += fruit[i] + " "; // i��° ���Ұ� ���ԵǾ��ٸ� ��� 
	}
	cout << ret << '\n';
}


int main(){
	cout << "combi 1" << '\n';
	combi();
	cout << '\n'<< "combi 2" << '\n';
	for(int i=1; i<fruit.size(); i++){
		appleCombi(1 | (1<<i)); // ����� �ݵ�� �����ϴ� �� ���� ���(ex. 1001-> ���, ��) 
	}
	return 0;
}
// n <= 31������ ����(-2^31 <= int <= 2^31) 
