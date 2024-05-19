#pragma once
template<typename T>
class Node
{
public:
	Node(): _data(T()), _prev(nullptr), _next(nullptr) {}
	Node(const T& value) : _data(value), _prev(nullptr), _next(nullptr) {};
	
public:
	T	  _data;
	Node* _prev;
	Node* _next;
};

