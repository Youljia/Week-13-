#pragma once
#include"Node.h"
class RB_tree
{
public:
	RB_tree();
	int get_size();
	bool is_empty();
	void add(int e);
	bool contains(int e);
private:
	Node* add(Node* node, int e);
	bool contains(Node* node, int e);
	void flap_colors(Node* node);
	Node* left_rotate(Node* node);
	Node* right_rotate(Node* node);
	bool is_red(Node* node);
private:
	Node* root;
	int size;
};
