#include <iostream>
#include <algorithm>
#define MAXN 12
#define MAXK 10


using namespace std;
 
using Move = pair<int,int>;

vector<Move> moveTo = 
{
	{0, 1}, { 0,-1},
	{1, 0}, {-1, 0}
}; // idx+=2 -> reverse

//  0, 01
// 10, 11

struct Tile
{
	int color;
	vector<int> placed;	
};

struct Horse
{
	int y;
	int x;
	int dir;	
};


int N, K, ret = 0;

Tile  Board[MAXN][MAXN];
Horse horses[MAXK];

// white = 위치해 있는 말들을 쌓음 
// red = 모든 말의 순서를 뒤집음
// blue = 이동 방향을 뒤집고 한 칸 이동 

void transfer(int nowY, int nowX, int nextY, int nextX, int hIdx);

void input()
{
	cin >> N >> K;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> Board[i][j].color;
		}
	}
	
	for(int i=0; i<K; i++)
	{
		int y, x, dir;
		
		cin >> y >> x >> dir;
		
		horses[i].x = x;
		horses[i].y = y;
		horses[i].dir = dir;
		
		Board[y][x].placed.push_back(i);	
	}
}

bool rangeCheck(int y, int x)
{
	return 0 <= y && y < N && 0 <= x && x < N;
}

bool finished(int bY, int bX)
{
	return Board[bY][bX].placed.size() >= 4;
}

void isRed(int bY, int bX, vector<int>& placed, vector<int>& arrived)
{	
	reverse(arrived.begin(), arrived.end());
	
	placed.insert(placed.end(), arrived.begin(), arrived.end());
}

void isBlue(vector<int>& arrived)
{
	for(auto& hIdx: arrived)
	{
		int nowY = horses[hIdx].y;
		int nowX = horses[hIdx].x;
		
		horses[hIdx].dir ^= 1;
		Move mv = moveTo[horses[hIdx].dir];
		
		int nextY = nowY + mv.first;
		int nextX = nowX + mv.second;
		
		if(!rangeCheck(nextY, nextX) || Board[nextY][nextX].color == 2) continue;
		
		horses[hIdx].y = nextY;
		horses[hIdx].x = nextX;
		transfer(nowY, nowX, nextY, nextX, hIdx);
	}
}

void isWhite(int bY, int bX, vector<int>& placed, vector<int>& arrived)
{
	placed.insert(placed.end(), arrived.begin(), arrived.end());
}

void transfer(int nowY, int nowX, int nextY, int nextX, int hIdx)
{
	vector<int> arrived;
	vector<int>& placed = Board[nowY][nowX].placed;
	int color = Board[nextY][nextX].color;
	
	cout << "before: " << nowY << " / " << nowX << " / " << placed.size() <<endl;
	
	
	auto fIter = find(placed.begin(), placed.end(), hIdx);
	arrived.assign(fIter, placed.end());
	placed = vector<int>(placed.begin(), fIter);
	
	if(!rangeCheck(nextY, nextX) || color == 2)
	{
		isBlue(arrived);
		return;
	}

	switch(color)
	{
	case 0:
		isWhite(nextY, nextX, placed, arrived);	
		break;
	case 1:
		isRed(nextY, nextX, placed, arrived);
		break;	
	}
	
	cout << "after: " << nextY << " / " << nextX << " / " << Board[nextY][nextX].placed.size() <<endl;

	
	return ;
} 

int turn()
{
	int ret = 1;
	
	while(ret <= 1000)
	{
		for(int i=0; i<K; i++)
		{
			
			int nowY = horses[i].y;
			int nowX = horses[i].x;
			int dir = horses[i].dir;
			
			cout << nowY << " / " <<nowX << " / " << Board[nowY][nowX].placed.size()<<endl; 
			if(finished(nowY, nowX))
			{
				cout << ret;
				exit(0);
			}
			
			int nextY = nowY + moveTo[dir].first;
			int nextX = nowX + moveTo[dir].second;
			
			transfer(nowY, nowX, nextY, nextX, i);
		}	
		
		ret++;
	}
	
	if(ret > 1000) ret = -1;
	
	return ret;
}

int main()
{
	input();
	cout << turn();
	
	return 0;
}
