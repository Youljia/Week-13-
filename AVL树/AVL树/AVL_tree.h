#pragma once
#include"Node.h"
#include<vector>
using namespace std;
class AVL_tree
{
public:
	AVL_tree();
	~AVL_tree();
	bool is_BST();
	bool is_AVL();
	void add(int k, string v);
	string remove(int k);
	int get_size();
private:
	void in_order(Node* node, vector<int>& v);
	int get_height(Node* node);
	int get_balanced_factor(Node* node);
	int absolute(int t);
	int max(int i, int j);
	bool is_AVL(Node* node);
	Node* right_rotate(Node* y);
	Node* left_rotate(Node* y);
	Node* add(Node* node, string v, int k);
	Node* get_node(Node* node, int k);
	Node* search_min(Node* node);
	Node* remove(Node* node, int k);
private:
	Node* root;
	int size;
};

