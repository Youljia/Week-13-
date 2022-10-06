#pragma once
#include"AVL_tree.h"
class Set
{
public:
	Set();
	~Set();
	void add(int e);
	void remove(int e);
	bool contains(int e);
	int get_size();
	bool is_empty();
private:
	AVL_tree* avl;
};

