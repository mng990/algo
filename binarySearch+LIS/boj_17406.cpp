#include<bits/stdc++.h>

using namespace std;

int N, M, K, ret = INT_MAX;
int initMap[54][54] = {0,};
int Map[54][54] = {0,}; 
int prevMap[54][54] = {0,};

typedef struct rotate{
	int y;
	int x;
	int size;
	
	bool operator<(struct rotate r2){
		if(size != r2.size)
			return size < r2.size;
		if(y != r2.y)
			return y < r2.y;
		if(x != r2.x)
			return x< r2.x;
	}
}ROTATE;

vector<ROTATE> vecR;


void printMap(){
	//cout << "\n";
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << "\n";
}


void spin(int rIdx){
	ROTATE r = vecR[rIdx];
	
	
	int centerY = vecR[rIdx].y;
	int centerX = vecR[rIdx].x;
	
	//cout << "center: " << prevMap[centerY][centerX] << "\n";

	
	int startY = centerY - r.size;
	int endY = centerY + r.size;

	int startX = centerX - r.size;
	int endX = centerX + r.size;
	
	
	// remain 
	for(int i=1; i<startY; i++){
		for(int j=1; j<=M; j++){
			Map[i][j] = prevMap[i][j];
		}
	}
	
	for(int i=endY+1; i<=N; i++){
		for(int j=1; j<=M; j++){
			Map[i][j] = prevMap[i][j];
		}
	}
	
	for(int j=1; j<startX; j++){
		for(int i=1;i<=N;i++){
			Map[i][j] = prevMap[i][j];
		}
	}
	
	for(int j=endX+1; j<=M; j++){
		for(int i=1;i<=N; i++){
			Map[i][j] = prevMap[i][j];
		}
	}
	
	Map[centerY][centerX] = prevMap[centerY][centerX];
	
	//printMap();
	
	
	
	// up side
	int uStartY = startY;
	int uEndY = centerY;

	int uStartX = startX;
	int uEndX = endX;
	
	for(int i=uStartY; i < uEndY; i++){
		for(int j=uStartX; j < uEndX; j++){
			Map[i][j+1] = prevMap[i][j];
		}
		uStartX++;
		uEndX--;
	}
	//printMap();
	
	// left side
	
	int lStartY = startY;
	int lEndY = endY;
	
	int lStartX = startX;
	int lEndX = centerX;
	
	for(int j=lStartX; j<lEndX; j++){
		for(int i=lStartY+1; i<=lEndY; i++){
			Map[i-1][j] = prevMap[i][j];
		}
		lStartY++;
		lEndY--;
	}
	
	//printMap();
	
	
	int rStartY = startY;
	int rEndY = endY;
	
	int rStartX = endX;
	int rEndX = centerX;
	
	
	
	for(int j=rStartX; j>rEndX; j--){
		for(int i=rStartY; i<rEndY; i++){
			Map[i+1][j] = prevMap[i][j];
		}
		rStartY++;
		rEndY--;
	}
	
	//printMap();
	
	// down side
	int dStartY = endY;
	int dEndY = centerY;

	int dStartX = startX;
	int dEndX = endX;
	
	for(int i=dStartY; i > dEndY; i--){
		for(int j=dStartX+1; j <= dEndX; j++){
			Map[i][j-1] = prevMap[i][j];
		}
		dStartX++;
		dEndX--;
	}
	//printMap();
	
	Map[centerY][centerX] = prevMap[centerY][centerX];
	
	memcpy(prevMap, Map, sizeof(Map));
}

void input(){
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> initMap[i][j];
		}
	}
	
	for(int i=0; i<K; i++){
		ROTATE r;	
		cin >> r.y >> r.x >> r.size;
		vecR.push_back(r);
	}
	
	sort(vecR.begin(), vecR.end());
	
	return;
}

void update(){
	
	for(int i=1; i<=N; i++){
		int sum = 0;
		
		for(int j=1; j<=M; j++){
			sum += Map[i][j];
		}
		
		ret = min(ret, sum);
	}
		
	return; 
}

void play(){
	do{
		memcpy(prevMap, initMap, sizeof(initMap));
		
		for(int rIdx=0; rIdx<vecR.size(); rIdx++){	
			spin(rIdx);
			//printMap();
		}
		
		update();
		
	}while(next_permutation(vecR.begin(), vecR.end()));
}

void output(){
	cout << ret << "\n";
}

void run(){
	input();
	play();
	output();
}

int main(){
	run();
	return 0;
}
