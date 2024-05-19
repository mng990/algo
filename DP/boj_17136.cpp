#include <bits/stdc++.h>

using namespace std;

const int row = 10, col =10, INF = 9876543;

int area = 0, ret = INF;
int color[6];
bool Map[row][col];

bool rangeCheck(int y, int x)
{
	return 0 <= y && y < row && 0 <= x && x < col;
}

bool check(int y, int x, int cnt)
{
	if(!rangeCheck(y, x)) return false;
	
	for(int i = y; i < y + cnt; i++)
	{
		for(int j=x; j < x+cnt; j++)
		{
			if(Map[i][j] == 0) return false;
		}
	}
	
	return true;
}

void input()
{	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++){
			cin >> Map[i][j];
			area += Map[i][j];
		}
	}
	
	return;
}


// 색종이를 덮는 경우   (val == 1)
// 색종이를 치우는 경우 (val == 0) 
void draw(int y, int x, int size, int val)
{
	for(int i=y; i<y+size; i++)
	{
		for(int j=x; j<x+size; j++)
		{
			Map[i][j] = val;
		}
	}
}

void dfs(int y, int x, int cnt)
{
	// cnt가 이미 최솟값보다 크면 탐색 X 
	if(cnt >= ret) return ;
	
	if(x == col)
	{
		dfs(y+1, 0, cnt);
		return ;
	}
	
	if(y == row)
	{
		ret = min(cnt, ret);
		return;
	}
	
	if(Map[y][x] == 0)
	{
		dfs(y, x+1, cnt);
		return ;
	}
	
	for(int size = 5; size >=1; size--)
	{
		if(color[size] == 5) continue;
		if(check(y, x, size))
		{
			color[size]++;
			draw(y, x, size, 0);
			dfs(y, x+size, cnt+1);
			draw(y, x, size, 1);
			color[size]--;
		}
	}
}


void run()
{
	input();
	dfs(0,0,0);
	
	cout << (ret == INF ? -1 : ret);
}


int main()
{
	run();
	return 0;
}
