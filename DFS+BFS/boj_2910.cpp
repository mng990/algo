#include <bits/stdc++.h> 

using namespace std;

int N, C;
vector<int> message;
vector<int> justOne;
map<int, int> frequency;
map<int, int> msgIndex;


void input(){
	cin >> N >> C;
	
	for(int i=0; i<N; i++){
		int key;
		cin >> key;
		message.push_back(key);
		if(frequency[key] == 0) msgIndex[key] = i; //justOne.push_back(key);
		frequency[key]++;
	}
}

bool sortFlag(int a, int b){
	if(frequency[a] == frequency[b]){
		int aidx = find(justOne.begin(), justOne.end(), a) - justOne.begin();
		int bidx = find(justOne.begin(), justOne.end(), b) - justOne.begin();
		return aidx < bidx;
	}
	else return frequency[a] > frequency[b];
}

bool sortFlagSample(int a, int b){
	if(frequency[a] == frequency[b])
		return msgIndex[a] < msgIndex[b];
	else return frequency[a] > frequency[b];
}

void fsort(){
	sort(message.begin(), message.end(), sortFlagSample);
}

void output(){
	for(int i=0; i<message.size(); i++)
		cout << message[i] << " ";
	cout << '\n';
}

void run(){
	input();
	fsort();
	output();
}


int main(){
	run();
	return 0;
}
