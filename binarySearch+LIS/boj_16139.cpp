#include <bits/stdc++.h>

using namespace std;


int DP[26][200004] = {0,};
int startIdx, endIdx, q;
char alpha;
string S;

void printDP(){
	for(int i=0; i<26; i++){
		for(int j=0; j<=S.size(); j++){
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}	
}

void run(){
	cin >> S >> q;
	
	for(int i=0; i<S.size(); i++){ // S.at(0) == DP[aIdx][1]
		int aIdx = S[i] - 'a';
		
		DP[aIdx][i+1]++;
		
		for(int j=0; j<26; j++){
			DP[j][i+2] += DP[j][i+1];
		}
	} // O(N)
	
	for(int i=0; i<q; i++){
		cin >> alpha >> startIdx >> endIdx;
		int aIdx = alpha - 'a';
		cout << DP[aIdx][endIdx+1] - DP[aIdx][startIdx] << "\n";
	} // O(1)
}






int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
