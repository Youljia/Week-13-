#include "Node.h"
#define red true
#define black false
Node::Node() {
	this->e = NULL;
	this->left = this->right = nullptr;
	this->color = black;
}
Node::Node(int k) {
	this->e = k;
	this->left = this->right = nullptr;
	this->color = red;
}
Node::~Node() {
	if (this->left != nullptr)
		delete left;
	if (this->right != nullptr)
		delete right;
	left = right = nullptr;
}
