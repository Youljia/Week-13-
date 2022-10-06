#pragma once
#include<string>
using namespace std;
class Node
{
public:
	Node();
	Node(int k, string v);
	~Node();
public:
	int key;
	string value;
	Node* left;
	Node* right;
	int height;
};

