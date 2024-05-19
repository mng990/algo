#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

void CreateGraph()
{

	// 인접 리스트
// 	adjacent[0].push_back(1);
// 	adjacent[0].push_back(3);
// 	adjacent[1].push_back(0);
// 	adjacent[1].push_back(2);
// 	adjacent[1].push_back(3);
// 	adjacent[3].push_back(4);
// 	adjacent[5].push_back(4);

	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;

	adjacent[1][0] = 15;
	adjacent[1][3] = 10;
	adjacent[1][2] = 5;

	adjacent[3][4] = 5;
	adjacent[5][4] = 5;
}
void Dijikstra(int here)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	map<int, int> parent;
	priority_queue<VertexCost, vector<VertexCost>, greater<VertexCost>> discovered;
	vector<int> best(6, INT32_MAX);

	discovered.push(VertexCost{ here, 0 });
	best[here] = 0;
	parent[here] = here;

	while (!discovered.empty())
	{
		// 베스트 케이스를 찾음
		int bestCost = INT32_MAX;

		VertexCost bestCase = discovered.top();

		int cost = bestCase.cost;
		here = bestCase.vertex;
		discovered.pop();

		// 더 짧은 경로를 뒤늦게 찾았다면 스킵
		if (best[here] < cost) continue;

		// 방문
		for (int there = 0; there < 6; there++)
		{

			if (adjacent[here][there] == -1) continue;

			// 더 좋은 경로를 과거에 찾았으면 스킵
			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there]) continue;


			discovered.push(VertexCost{ there, nextCost });
			best[there] = nextCost;
			parent[there] = here;
		}
	}
}

// DFS
bool visited[6] = { 0, };
int weight[6] = { 0, };
void dfs(int here)
{
	visited[here] = true;
	cout << here << endl;
	for (int there : adjacent[here])
	{
		if (adjacent[here][there] && !visited[there])
			dfs(there);
	}

	return;
}
void bfs(int start)
{
	queue<int> path;

	weight[start] = 1;
	path.push(start);

	while (!path.empty())
	{
		int here = path.front();

		cout << "spot: " << here << " / weight: " << weight[here] - 1 << endl;

		for (int there : adjacent[here])
		{
			if (weight[there] != 0) continue;


			weight[there] = weight[here] + 1;
			path.push(there);
		}

		path.pop();
	}
}
