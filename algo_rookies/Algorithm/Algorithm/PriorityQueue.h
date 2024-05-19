#pragma once
#include <vector>

template<typename T, typename Container = std::vector<T>, typename Predicate = std::less<T>>
class PriorityQueue
{
public:
	PriorityQueue() = default;
	~PriorityQueue() = default;


	void push(const T& data)
	{
		_heap.push_back(data);

		// 정렬 시작
		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			// 부모 노드의 데이터와 비교
			int parent = (now - 1) / 2;
			if (_predicate(_heap[now], _heap[parent])) break;

			// 데이터 교체
			::swap(_heap[now], _heap[parent]);
			now = parent;
		}
	}

	void pop()
	{
		// 최상위 노드 삭제
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left  = 2 * now + 1;
			int right = 2 * now + 2;

			if (left >= _heap.size()) break;
			

			int next = now;
			// 왼쪽과 비교
			if (_predicate(_heap[next], _heap[left])) next = left;

			// 둘 중 큰 값을 오른쪽과 비교
			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;	
			
			// 왼쪽 / 오른쪽 둘 다 현재 값보다 작으면 종료
			if (next == now) break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.size() == 0;
	}

private:
	Container _heap = {};
	Predicate _predicate;
};