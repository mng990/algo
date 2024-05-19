#pragma once
#include "Node.h"

template <typename T>
class Queue
{
public:
	Queue() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();

		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~Queue()
	{
		while (!empty())
		{
			pop();
		}
		delete _head;
		delete _tail;
	}


	void push(T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = _tail->_prev;

		_tail->_prev = newNode;
		prevNode->_next = newNode;

		newNode->_next = _tail->_prev;
		newNode->_prev = prevNode;
		_size++;
	}

	void pop()
	{
		Node<T>* target = _head->_next;
		Node<T>* before = target->_next;

		_head->_next  = before;
		before->_prev = _head;

		delete target;
		_size--;
	}

	T front()
	{
		return _head->_next->_data;
	}

	T back()
	{
		return _tail->_prev->_data;
	}

	int size()	 { return _size;}
	bool empty() { return _size == 0; }

private:
	Node<T>* _head;
	Node<T>* _tail;
	int		 _size = 0;
};

