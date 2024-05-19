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

	// ������ �����ϱ� ������ ����ؼ� ����
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
		// 1. ���� �ٶ󺸴� ������ �������� ���������� �� �� �ִ��� Ȯ��
		if (CanGo(Right))
		{
			// ������ �������� 90�� ȸ��
			_dir = rightSide;
			// ������ �� �� ����
			pos = Right;
			_path.push_back(pos);
		}
		// 2. ���� �ٶ󺸴� ������ �������� ������ �� �ִ����� Ȯ��
		else if (CanGo(Straight))
		{
			// ������ �� �� ����
			pos = Straight;
			_path.push_back(pos);
		}
		else 
		{
			// ���� �������� 90�� ȸ��
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
	// ���� �ű��
	// F = G + H
	// F = ���� ���� (���� ���� ����, ��ο� ���� �޶���)
	// G = ���������� �ش� ��ǥ���� �̵��ϴµ� ��� ���(���� ���� ����, ��ο� ���� �޶���)
	// H = ���������� �󸶳� ������� (���� ���� ����, ����)

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
	// close[y][x] -> (y,x)�� �湮�� �ߴ��� ����
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// best[y][x] -> ���ݱ��� (y,x)�� ���� ���� ���� ��� (���� ���� ����)
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	// �θ� ����
	map<Pos, Pos> parent;

	// OpenList
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
	
	// 1) ����(�߰�) �ý��� ����
	// - �̹� �� ���� ��θ� ã�Ҵٸ� ��ŵ
	// 2) �ڴʰ� �� ���� ��ΰ� �߰ߵ� �� ���� -> ���� ó�� �ʼ�
	// - openList���� ã�Ƽ� ����
	// - pq���� pop�� ���� ����

	// �ʱⰪ
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));
		pq.push(PQNode{ g + h, g, start });
		best[start.y][start.x] = g + h;
		parent[start] = start;
	}

	while (pq.empty() == false)
	{
		// ���� ���� �ĺ��� ã�´�
		PQNode node = pq.top();
		pq.pop();

		// �湮
		closed[node.pos.y][node.pos.x] = true;

		// �������� ���������� �ٷ� ����
		if (node.pos == dest) break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = node.pos + MoveTo[dir];
			// �� �� �ִ� ������ �´��� Ȯ��
			if (CanGo(nextPos) == false) continue;
			
			// �̹� �湮�� ���̸� ��ŵ
			if (closed[nextPos.y][nextPos.x]) continue;

			// ��� ���
			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));
			
			// �ٸ� ��ο��� �� ���� ���� ã������ ��ŵ
			if (best[nextPos.y][nextPos.x] <= g + h) continue;

			// ���� ����
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
