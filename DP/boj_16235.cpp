#include <bits/stdc++.h>
#define MAXN 12

using namespace std;

using dir = pair<int,int>;

struct tree
{
	int x;
	int y;
	int age;
};


vector<dir> vecDir = 
{
	{-1, -1}, {-1,  0},
	{-1, +1}, { 0, -1},
	{ 0, +1}, {+1, -1},
	{+1,  0}, {+1, +1}
};

int N, M, K, ret = 0;
int nut[MAXN][MAXN] = {0,};
int Map[MAXN][MAXN] = {0,};

vector<tree> forest;

bool rangeCheck(int y, int x)
{
	return 1<=y && y<=N && 1<=x && x<=N;
}

void input()
{
	cin >> N >> M >> K;
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
		{
			cin >> nut[i][j];
			Map[i][j] = 5;
		}
			
	
	for(int i=0; i<M; i++)
	{
		int x, y, age;
		cin >> y >> x >> age;
		forest.push_back({x, y, age});
	}
	
	sort(forest.begin(), forest.end(), [](tree t1, tree t2){ return t1.age < t2.age;});
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	input();
	
	while(K > 0)
	{
		K--;
		// spring
		vector<tree> birth;
		vector<tree> nextYear;

		for(auto& tr: forest)
		{			
			if(Map[tr.y][tr.x] < tr.age){
				tr.age *= -1;
				continue;
			}
			
			Map[tr.y][tr.x] -= tr.age;
			tr.age++;
		}
		
		// fall
		for(auto& tr: forest)
		{	
			if(tr.age > 0)
			{
				if(tr.age % 5 == 0)
				{
					for(int i=0; i<vecDir.size(); i++)
					{
						int newY = tr.y + vecDir[i].first;
						int newX = tr.x + vecDir[i].second;
						if(!rangeCheck(newY, newX)) continue;
						
						birth.push_back({newX, newY, 1});
					}
				}
				nextYear.push_back(tr);
			}
			else
			{
				// summer
				Map[tr.y][tr.x] += abs(tr.age)/2;
			}
		}
		
		// winter
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				Map[i][j] += nut[i][j];
			}
		}
		
		forest.swap(birth);
		forest.insert(forest.end(), nextYear.begin(), nextYear.end());
	}
	
	for(auto tr: forest)
	{
		if(tr.age > 0) ret++;
	}
	
	cout << ret;

	
	return 0;
}
