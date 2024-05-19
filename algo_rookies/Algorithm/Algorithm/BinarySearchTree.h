#pragma once
enum class Color
{
	Red = 0,
	Black = 1,
};


struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int	  key = {};

	bool external;
	Color color = Color::Black;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	Node* GetRoot() { return _root; }
	void Print();
	void Print(Node* node, int x, int y);
	void Insert(int key);
	void InsertFixup(Node* node);

	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void Delete(int key);
	void Delete(Node* node);

	void Replace(Node* u, Node* v);

	void LeftRotate(Node* node);
	void RightRotate(Node* node);

	Node* Search(Node* node, int key);
private:
	Node* _root = nullptr;
	Node* _nil = nullptr;
};

