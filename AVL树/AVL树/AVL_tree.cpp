#include "AVL_tree.h"
AVL_tree::AVL_tree() {
	this->root = nullptr;
	this->size = 0;
}
AVL_tree::~AVL_tree() {
	if (this->root != nullptr)
		delete this->root;
	this->root = nullptr;
}
int AVL_tree::get_size() {
	return this->size;
}
//判断该树是否满足二分搜索树的条件
//即所有的父亲节点都要小于右孩子并且大于左孩子
//检验方法--》利用性质...中序遍历后该数组是有序的
bool AVL_tree::is_BST() {
	vector<int> v;
	in_order(this->root, v);
	//判断数组是否有序
	for (auto iter=v.begin()+1;iter!=v.end();++iter){
		if (*iter < *(iter - 1))
			return false;
	}
	return true;
}
//判断是否是AVL树
bool AVL_tree::is_AVL() {
	return is_AVL(this->root);
}
//递归调用，判断是否每个节点的平衡因子的绝对值都不大于1
bool AVL_tree::is_AVL(Node* node) {
	if (node == nullptr)return true;
	if (absolute(get_balanced_factor(node)) > 1)return false;
	return is_AVL(node->left) && is_AVL(node->right);
}
//中序遍历树
void AVL_tree::in_order(Node* node, vector<int>& v) {
	if (node == nullptr)return;
	in_order(node->left, v);
	v.push_back(node->key);
	in_order(node->right, v);
}
//获取目标节点的高度
int AVL_tree::get_height(Node* node) {
	if (node != nullptr)return node->height;
	else return 0;
}
//获取目标节点的平衡因子
int AVL_tree::get_balanced_factor(Node* node) {
	if (node == nullptr)return 0;
	return get_height(node->left) - get_height(node->right);
}
//求一个数的绝对值
int AVL_tree::absolute(int t) {
	int i = t < 0 ? -1 * t : t;
	return i;
}
//求两个数中的较大值
int AVL_tree::max(int i, int j) {
	return i > j ? i : j;
}
//右旋转--》当树往左偏的时候
//返回旋转后的根节点
Node* AVL_tree::right_rotate(Node* y) {
	Node* x = y->left;
	Node* T3 = x->right;
	//倒转
	x->right = y;
	y->left = T3;
	//维护height
	y->height = 1 + max(get_height(y->left), get_height(y->right));
	x->height = 1 + max(get_height(x->left), get_height(x->right));
	return x;
}
//左旋转--》当树往右偏的时候
//返回旋转后的根节点
Node* AVL_tree::left_rotate(Node* y) {
	Node* x = y->right;
	Node* T3 = x->left;
	x->left = y;
	y->right = T3;
	y->height = 1 + max(get_height(y->left), get_height(y->right));
	x->height = 1 + max(get_height(x->left), get_height(x->right));
	return x;
}
//添加的用户接口
void AVL_tree::add(int k, string v) {
	this->root = add(this->root, v, k);
}
//在以node为根节点中添加元素
//返回添加后的根节点
Node* AVL_tree::add(Node* node, string v, int k) {
	if (node == nullptr) {
		size++;
		return new Node(k, v);
	}
	if (node->key > k)
		node->left = add(node->left, v, k);
	else if (node->key < k)
		node->right = add(node->right, v, k);
	else
		node->value = v;
	//维护节点的height
	node->height = 1 + max(get_height(node->left), get_height(node->right));
	//计算一下平衡因子，看是否需要维持自平衡
	int balanced_factor = get_balanced_factor(node);
	//LL型
	if (balanced_factor > 1 && get_balanced_factor(node->left) >= 0)
		return right_rotate(node);
	//RR型
	if (balanced_factor < -1 && get_balanced_factor(node->left) <= 0)
		return left_rotate(node);
	//LR型 
	if (balanced_factor > 1 && get_balanced_factor(node->left) < 0) {
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}
	//RL型
	if (balanced_factor < -1 && get_balanced_factor(node->left) > 0) {
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}
	return node;
}
//删除树中的指定节点
string AVL_tree::remove(int k) {
	string e = get_node(this->root, k)->value;
	remove(this->root, k);
	return e;
}
//获取指定元素的节点
Node* AVL_tree::get_node(Node* node, int k) {
	if (node == nullptr)return nullptr;
	if (node->key == k)return node;
	if (node->key > k)return get_node(node->left, k);
	else return get_node(node->right, k);
}
//找寻树中以node为根节点的最小元素的节点
Node* AVL_tree::search_min(Node* node) {
	if (node->left == nullptr)return node;
	return search_min(node->left);
}
//递归调用，删除以node为根节点的目标节点
//返回删除后的根节点
Node* AVL_tree::remove(Node* node, int k) {
	Node* ret = node;
	if (node->key > k) {
		node->left = remove(node->left, k);
		ret = node;
	}
	else if (node->key < k) {
		node->right = remove(node->right, k);
		ret = node;
	}
	else {
		//目标没有右子树
		if (node->right == nullptr) {
			Node* res = node->left;
			node->left = nullptr;
			size--;
			ret = res;
		}
		//目标没有左子树
		else if (node->left == nullptr) {
			Node* res = node->right;
			node->right = nullptr;
			size--;
			ret = res;
		}
		else {
			Node* successor = search_min(node->right);
			successor->right = remove(node->right, successor->key);
			successor->left = node->left;
			node->left = node->right = nullptr;
			size--;
			ret = successor;
		}
	}
	if (ret == nullptr)return nullptr;
	//维护节点的height
	ret->height = 1 + max(get_height(ret->left), get_height(ret->right));
	//计算一下平衡因子，看是否需要维持自平衡
	int balanced_factor = get_balanced_factor(ret);
	//LL型
	if (balanced_factor > 1 && get_balanced_factor(ret->left) >= 0)
		return right_rotate(ret);
	//RR型
	if (balanced_factor < -1 && get_balanced_factor(ret->left) <= 0)
		return left_rotate(ret);
	//LR型 
	if (balanced_factor > 1 && get_balanced_factor(ret->left) < 0) {
		ret->left = left_rotate(ret->left);
		return right_rotate(ret);
	}
	//RL型
	if (balanced_factor < -1 && get_balanced_factor(ret->left) > 0) {
		ret->right = right_rotate(ret->right);
		return left_rotate(ret);
	}
	return ret;
}