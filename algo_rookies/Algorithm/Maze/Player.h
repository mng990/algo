#pragma once

class Board;

class Player
{
	enum
	{
		MOVE_TICK = 100
	};
public:
	void Init(Board* board);
	void Update(uint64 deltaTick);
	void SetPos(Pos pos) {_pos = pos;}
	Pos  GetPos() { return _pos; }
	bool CanGo(Pos pos);
	void RightHand();
	void BFS();
	void AStar();
private:
	Pos    _pos = {};
	int32  _dir = DIR_UP;
	Board* _board = nullptr;

	vector<Pos> _path;
	int32 _pathIndex = 0;
	int32 _sumTick = 0;
};

