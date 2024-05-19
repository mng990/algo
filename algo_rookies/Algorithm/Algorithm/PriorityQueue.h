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

		// ���� ����
		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			// �θ� ����� �����Ϳ� ��
			int parent = (now - 1) / 2;
			if (_predicate(_heap[now], _heap[parent])) break;

			// ������ ��ü
			::swap(_heap[now], _heap[parent]);
			now = parent;
		}
	}

	void pop()
	{
		// �ֻ��� ��� ����
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left  = 2 * now + 1;
			int right = 2 * now + 2;

			if (left >= _heap.size()) break;
			

			int next = now;
			// ���ʰ� ��
			if (_predicate(_heap[next], _heap[left])) next = left;

			// �� �� ū ���� �����ʰ� ��
			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;	
			
			// ���� / ������ �� �� ���� ������ ������ ����
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