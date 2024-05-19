#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <thread>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree bst;

	bst.Insert(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(10);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(30);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(25);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(40);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(50);
	bst.Print();
//	this_thread::sleep_for(1s);


	return 0;
}