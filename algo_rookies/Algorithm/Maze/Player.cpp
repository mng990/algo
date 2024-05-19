#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>
#include <queue>
#include <map>

void Player::Init(Board* board)
{
	_board = board;
	_pos   = _board->GetEnterPos();

	//BFS();
	AStar();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
	{
		_board->GenerateMap();
		Init(_board);
		return;
	}

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	
	return tileType != TileType::WALL;
}

void Player::RightHand()
{
	Pos pos = _pos;
	_path.clear();
	_path.reserve(_board->GetSize());
	_path.push_back(pos);

	// 목적지 도착하기 전에는 계속해서 실행
	Pos dest = _board->GetExitPos();

	Pos MoveTo[4] = {
	{-1,0}, {0,-1},
	{ 1,0}, {0, 1}
	};

	while (pos != dest)
	{
		int32 rightSide = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		Pos Straight = pos + MoveTo[_dir];
		Pos Right    = pos + MoveTo[rightSide];
		// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인
		if (CanGo(Right))
		{
			// 오른쪽 방향으로 90도 회전
			_dir = rightSide;
			// 앞으로 한 보 전진
			pos = Right;
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지를 확인
		else if (CanGo(Straight))
		{
			// 앞으로 한 보 전진
			pos = Straight;
			_path.push_back(pos);
		}
		else 
		{
			// 왼쪽 방향으로 90도 회전
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}

	stack<Pos> stk;
	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (stk.empty() == false && stk.top() == _path[i + 1])
		{
			stk.pop();
		}
		else 
		{
			stk.push(_path[i]);
		}
	}

	if (_path.empty() == false)
		stk.push(_path.back());

	vector<Pos> path;
	while (!stk.empty())
	{
		path.push_back(stk.top());
		stk.pop();
	}

	std::reverse(path.begin(), path.end());

	_path = path;
}

void Player::BFS()
{
	const int32 size = _board->GetSize();
	vector<vector<int>> visited(size, vector<int>(size, 0));

	Pos pos = _pos;
	Pos dest = _board->GetExitPos();

	Pos MoveTo[4] = {
		{-1,0}, {0,-1},
		{ 1,0}, {0, 1}
	};

	map<Pos, Pos> parent;
	queue<Pos> quePath;

	quePath.push(pos);
	visited[pos.y][pos.x] = 1;
	parent[pos] = pos;

	while (!quePath.empty())
	{
		pos = quePath.front();
		quePath.pop();

		if (pos == dest) break;

		for (int i = 0; i < 4; i++)
		{
			Pos adj = { pos.y + MoveTo[i].y, pos.x + MoveTo[i].x };
			
			if (visited[adj.y][adj.x] > 0) continue;

			TileType tile = _board->GetTileType(adj);

			if (tile == TileType::WALL) continue;
			
			visited[adj.y][adj.x] = visited[pos.y][pos.x] + 1;
			quePath.push(adj);
			parent[adj] = pos;
		}
	}

	vector<Pos> path;

	while (true)
	{
		path.push_back(pos);
		if (pos == _pos) break;
		pos = parent[pos];
	}

	std::reverse(path.begin(), path.end());

	_path = path;
}


void Player::AStar()
{
	// 점수 매기기
	// F = G + H
	// F = 최종 점수 (작을 수록 좋음, 경로에 따라 달라짐)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용(작을 수록 좋음, 경로에 따라 달라짐)
	// H = 목적지에서 얼마나 가까운지 (작을 수록 좋음, 고정)

	Pos start = _board->GetEnterPos();
	Pos dest = _board->GetExitPos();

	struct PQNode
	{
		bool operator<(const PQNode& other) const { return f < other.f; }
		bool operator>(const PQNode& other) const { return f < other.f; }

		int32 f; // f = g + h
		int32 g;
		Pos   pos;
	};

	enum 
	{
		DIR_COUNT = 4
	};

	Pos MoveTo[8] = {
		{-1, 0}, { 0,-1},
		{ 1, 0}, { 0, 1},
		{ 1,-1}, { 1, 1},
		{-1, 1}, {-1,-1}
	};
	
	int32 cost[] =
	{
		10, 10, // UP, DOWN
		10, 10, // LEFT, RIGHT
		14, 14, // UP_LEFT, UP_RIGHT
		14, 14  // DOWN_RIGHT, DOWN_LEFT 
	};

	const int32 size = _board->GetSize();
	
	// ClosedList
	// close[y][x] -> (y,x)에 방문을 했는지 여부
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// best[y][x] -> 지금까지 (y,x)에 대한 가장 좋은 비용 (작을 수록 좋음)
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	// 부모 추적
	map<Pos, Pos> parent;

	// OpenList
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
	
	// 1) 예약(발견) 시스템 구현
	// - 이미 더 좋은 경로를 찾았다면 스킵
	// 2) 뒤늦게 더 좋은 경로가 발견될 수 있음 -> 예외 처리 필수
	// - openList에서 찾아서 제거
	// - pq에서 pop한 다음 무시

	// 초기값
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));
		pq.push(PQNode{ g + h, g, start });
		best[start.y][start.x] = g + h;
		parent[start] = start;
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다
		PQNode node = pq.top();
		pq.pop();

		// 방문
		closed[node.pos.y][node.pos.x] = true;

		// 목적지에 도착했으면 바로 종료
		if (node.pos == dest) break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = node.pos + MoveTo[dir];
			// 갈 수 있는 지역이 맞는지 확인
			if (CanGo(nextPos) == false) continue;
			
			// 이미 방문한 곳이면 스킵
			if (closed[nextPos.y][nextPos.x]) continue;

			// 비용 계산
			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));
			
			// 다른 경로에서 더 빠른 길을 찾았으면 스킵
			if (best[nextPos.y][nextPos.x] <= g + h) continue;

			// 예약 진행
			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode{g+h, g, nextPos});
			parent[nextPos] = node.pos;
		}
	}

	Pos pos = dest;

	_path.clear();
	_pathIndex = 0;

	while (true)
	{
		_path.push_back(pos);
		if (pos == parent[pos]) break;

		pos = parent[pos];
	}

	::reverse(_path.begin(), _path.end());
}
