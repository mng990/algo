#include <bits/stdc++.h>

using namespace std;

char data;
int row, col;
char sky[104][104];
int caster[104][104] = {0,};

void input(){
	cin >>  row >>  col;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			char data;
			cin >> data;
			sky[i][j] = data;
			caster[i][j] = -1;
		}
	}
}

void hours(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(sky[i][j] == 'c'){
				caster[i][j] = 0;
			}
			else if(j > 0 && caster[i][j-1] != -1){
				caster[i][j] = caster[i][j-1]+1;
			}
		}
	}
}

void printCaster(){
	for(int i=0;i<row;i++){
		for(int j=0; j<col;j++){
			cout << caster[i][j] << " ";
		}
		cout << endl;
	}
}

void run(){
	input();
	hours();
	printCaster();
}

int main(){
	run();
	return 0;
}
