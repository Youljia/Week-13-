#pragma once
#include"AVL_tree.h"
class Map
{
public:
	Map();
	~Map();
	int get_size();
	bool is_empty();
	void add(int k, string v);
	void set(int k, string v);
	string remove(int k);
	bool contains(int k);
	string get(int k);
private:
	AVL_tree* avl;
};

