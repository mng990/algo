#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr){}

	Iterator(Node<T>* node) : _node(node) {};

	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	Iterator& operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	Iterator& operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*() 
	{
		return _node->_data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node<T>* _node;
};

template <typename T>
class LinkedList
{
public:
	LinkedList() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~LinkedList()
	{
		while (_size > 0)
		{
			pop_back();
		}
		delete _head;
		delete _tail;
	}

	void push_back(T& value);
	void push_front(T& value);
	void pop_back();
	int  size();

public:
	using iterator = Iterator<T>;
	iterator begin() { return iterator(_head->_next); }
	iterator end()	 { return iterator(_tail); }

	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

private:
	Node<T>* AddNode(Node<T>* before, const T& value);
	Node<T>* RemoveNode(Node<T>* node);

private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
	int		 _size = 0;
};


template <typename T>
int LinkedList<T>::size()
{
	return _size;
}

template<typename T>
Node<T>* LinkedList<T>::AddNode(Node<T>* before, const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	Node<T>* prevNode = before->_prev;

	prevNode->_next = newNode;
	newNode->_next = before;

	newNode->_prev = prevNode;
	before->_prev = newNode;

	_size++;

	return newNode;
}

template<typename T>
Node<T>* LinkedList<T>::RemoveNode(Node<T>* node)
{	
	Node<T>* nextNode = node->_next;
	Node<T>* prevNode = node->_prev;

	prevNode->_next = nextNode;
	nextNode->_prev = prevNode;

	delete node;

	_size--;

	return nextNode;
}

template <typename T>
void LinkedList<T>::pop_back()
{
	RemoveNode(_tail->_prev);
}

template <typename T>
void LinkedList<T>::push_front(T& value)
{
	AddNode(_head->_next, value);
}

template <typename T>
void LinkedList<T>::push_back(T& value)
{
	AddNode(_tail, value);
}

