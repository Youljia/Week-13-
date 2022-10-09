#pragma once
#include<string>
using namespace std;
class Node
{
public:
	Node();
	Node(int e);
	~Node();
public:
	int e;
	Node* left;
	Node* right;
	bool color;
};
