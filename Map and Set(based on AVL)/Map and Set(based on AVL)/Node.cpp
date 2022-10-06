#include "Node.h"
Node::Node() {
	this->key = NULL;
	this->left = this->right = nullptr;
	this->value = nullptr;
	this->height = 0;
}
Node::Node(int k, string v) {
	this->value = v;
	this->key = k;
	this->left = this->right = nullptr;
	this->height = 1;
}
Node::~Node() {
	if (this->left != nullptr)
		delete left;
	if (this->right != nullptr)
		delete right;
	left = right = nullptr;
}
