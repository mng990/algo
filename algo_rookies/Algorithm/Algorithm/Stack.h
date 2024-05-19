#pragma once
#include "Node.h"

template <typename T>
class Stack
{
public:
	Stack() : _size(0) 
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}
	~Stack() 
	{
		while (!empty())
		{
			pop();
		}

		delete _head;
		delete _tail;
	}

	T    top()   { return _tail->_prev->_data; }
	int  size()  { return _size; }
	bool empty() { return _size == 0; }

	void push(T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = _tail->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = _tail;
		_tail->_prev = newNode;

		_size++;
	}
	void pop()
	{
		Node<T>* target = _tail->_prev;
		Node<T>* prevNode = target->_prev;

		prevNode->_next = _tail;
		_tail->_prev = prevNode;

		delete target;

		_size--;
	}

private:
	Node<T>* _head;
	Node<T>* _tail;
	int _size;
};

