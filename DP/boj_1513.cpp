#include <bits/stdc++.h>
#define ROW 54
#define COL 54
#define MAXC 54
#define MOD 1000007

using namespace std;

int N, M, C;

using Arcade = pair<int,int>;

int DP[MAXC][MAXC][ROW][COL];
int Map[ROW][COL] ={0,};

bool rangeCheck(int y, int x)
{
	return 1 <= y && y<=N && 1<=x && x <= M;
}

void input()
{
	cin >> N >> M >> C;
	
	for(int i=1; i<=C; i++)
	{
		Arcade arc;
		cin >> arc.first >> arc.second;
		Map[arc.first][arc.second] = i;
	}
	memset(DP, -1, sizeof(DP));
}


int Search(int nowY, int nowX, int visited, int cnt)
{	
	if(cnt < 0) return 0;
	
	if(!rangeCheck(nowY, nowX)) return 0;
	
	int arcNum = Map[nowY][nowX];

	if(nowY == N && nowX == M)
	{
		if(cnt == 0 && arcNum == 0) 	 return 1;
		if(cnt == 1 && arcNum > visited) return 1;
		
		return 0;
	}
	
	int& ret = DP[cnt][visited][nowY][nowX];
	if(~ret) return ret;

	ret = 0;
	
	if(arcNum == 0)
	{
		ret = (Search(nowY+1, nowX, visited, cnt) + Search(nowY, nowX+1, visited, cnt))%MOD;
	}
	else if(arcNum > visited)
	{
		ret = (Search(nowY+1, nowX, arcNum, cnt-1) + Search(nowY, nowX+1, arcNum, cnt-1))%MOD;
	}
	
	
	return ret;
}

int main()
{
	input();
	for(int cnt=0; cnt<=C; cnt++)
	{
		cout << Search(1,1,0,cnt) << " ";
	}
	
	return 0;
}
