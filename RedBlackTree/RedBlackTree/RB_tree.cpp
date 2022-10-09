#include "RB_tree.h"
#define red true
#define black false
RB_tree::RB_tree() {
	this->root = new Node;
	this->size = 0;
}
int RB_tree::get_size() {
	return this->size;
}
bool RB_tree::is_empty() {
	if (this->size == 0)return true;
	else return false;
}
//翻转颜色
void RB_tree::flap_colors(Node* node) {
	node->color = red;
	node->left = node->right = black;
}
//左旋转
Node* RB_tree::left_rotate(Node* node) {
	Node* x = node->right;
	node->right = x->left;
	x->left = node;
	x->color = node->color;
	node->color = red;
	return x;
}
//右旋
Node* RB_tree::right_rotate(Node* node) {
	Node* x = node->left;
	node->left = x->right;
	x->right = node;
	x->color = node->color;
	node->color = red;
	return x;
}
//用以规定叶子节点是黑色
bool RB_tree::is_red(Node* node) {
	if (node == nullptr)return black;
	else return node->color;
}
//添加操作，并维持红黑树特有的“黑平衡”性质
void RB_tree::add(int e) {
	this->root = add(root, e);
}
Node* RB_tree::add(Node* node, int e) {
	if (node == nullptr){
		this->size++;
		return new Node(e);
	}

	else if (node->e > e)
		node->left = add(node->left, e);
	else if (node->e < e)
		node->right = add(node->right, e);

	//维护一下红黑树的“黑平衡”
	if (is_red(node->right) && !is_red(node->left))
		node = left_rotate(node);
	if (is_red(node->left) && is_red(node->left->left))
		node = right_rotate(node);
	if (is_red(node->left) && is_red(node->right))
		flap_colors(node);

	return node;
}
//查询树中是否包含某个元素
bool RB_tree::contains(int e) {
	return contains(this->root, e);
}
bool RB_tree::contains(Node* node, int e) {
	if (node == nullptr)
		return false;
	if (node->e == e)
		return true;
	else if (node->e > e)
		contains(node->left, e);
	else
		contains(node->right, e);
}
