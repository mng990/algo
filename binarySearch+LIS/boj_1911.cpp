#include<bits/stdc++.h>


using namespace std;

int N, L, ret, woodEnd;
vector<pair<int,int>> vecHole;

bool sortFlag(pair<int,int> h1, pair<int,int> h2){
	if(h1.first != h2.first)
		return h1.first < h2.first;
	if(h1.second != h2.second)
		return h1.second < h2.second;
}


void input(){
	cin >> N >> L;
	
	for(int i=0; i<N; i++){
		int start, end;
		cin >> start >> end;
		
		vecHole.push_back({start, end});
	}
	
	sort(vecHole.begin(), vecHole.end(), sortFlag);
}

void setWood(pair<int,int> hole){
	int hstart = hole.first;
	int hend = hole.second;
	int hlen = hend - hstart;
	
	int remain = hlen%L;
	int wCnt = hlen/L;
	woodEnd = hstart+(wCnt*L) -1;
	
	ret += wCnt;
		
	if(hlen%L > 0){
		ret++;
		woodEnd += L;
	}
}

void makeBridge(){
	setWood(vecHole[0]);
		
	for(int i=1; i<vecHole.size(); i++){
		
		if(vecHole[i].first <= woodEnd+1){
			vecHole[i].first = woodEnd+1;
			
			if(vecHole[i].first >= vecHole[i].second){
				continue;
			}
		}
		
		setWood(vecHole[i]);
				
	}
	
	return;
}

void output(){
	cout << ret << "\n";
}

void run(){
	input();
	makeBridge();
	output();
}

int main(){
	run();
	return 0;
}
