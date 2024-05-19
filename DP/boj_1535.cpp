#include <bits/stdc++.h>
#define MAXN 21


using namespace std;

int N, mask, ret=0;

int life[MAXN] = {0,}, joy[MAXN] = {0,}; 

void input()
{
	cin >> N;
	mask = 1 << N;
	for(int i=0; i<N; i++) cin >> life[i];
	for(int i=0; i<N; i++) cin >> joy[i];
}	


int main()
{
	input();
	
	for(int m=1; m < mask; m++)
	{
		int l = 100, j = 0;
		
		for(int i=0; i<N; i++)
		{
			if(m & (1<<i))
			{
				l -= life[i];
				j += joy[i];	
			}
		}
		
		if(l > 0) ret = max(ret, j);
	}
	
	cout << ret;
	
	return 0;
}
