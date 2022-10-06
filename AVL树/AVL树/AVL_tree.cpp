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
//�жϸ����Ƿ��������������������
//�����еĸ��׽ڵ㶼ҪС���Һ��Ӳ��Ҵ�������
//���鷽��--����������...���������������������
bool AVL_tree::is_BST() {
	vector<int> v;
	in_order(this->root, v);
	//�ж������Ƿ�����
	for (auto iter=v.begin()+1;iter!=v.end();++iter){
		if (*iter < *(iter - 1))
			return false;
	}
	return true;
}
//�ж��Ƿ���AVL��
bool AVL_tree::is_AVL() {
	return is_AVL(this->root);
}
//�ݹ���ã��ж��Ƿ�ÿ���ڵ��ƽ�����ӵľ���ֵ��������1
bool AVL_tree::is_AVL(Node* node) {
	if (node == nullptr)return true;
	if (absolute(get_balanced_factor(node)) > 1)return false;
	return is_AVL(node->left) && is_AVL(node->right);
}
//���������
void AVL_tree::in_order(Node* node, vector<int>& v) {
	if (node == nullptr)return;
	in_order(node->left, v);
	v.push_back(node->key);
	in_order(node->right, v);
}
//��ȡĿ��ڵ�ĸ߶�
int AVL_tree::get_height(Node* node) {
	if (node != nullptr)return node->height;
	else return 0;
}
//��ȡĿ��ڵ��ƽ������
int AVL_tree::get_balanced_factor(Node* node) {
	if (node == nullptr)return 0;
	return get_height(node->left) - get_height(node->right);
}
//��һ�����ľ���ֵ
int AVL_tree::absolute(int t) {
	int i = t < 0 ? -1 * t : t;
	return i;
}
//���������еĽϴ�ֵ
int AVL_tree::max(int i, int j) {
	return i > j ? i : j;
}
//����ת--����������ƫ��ʱ��
//������ת��ĸ��ڵ�
Node* AVL_tree::right_rotate(Node* y) {
	Node* x = y->left;
	Node* T3 = x->right;
	//��ת
	x->right = y;
	y->left = T3;
	//ά��height
	y->height = 1 + max(get_height(y->left), get_height(y->right));
	x->height = 1 + max(get_height(x->left), get_height(x->right));
	return x;
}
//����ת--����������ƫ��ʱ��
//������ת��ĸ��ڵ�
Node* AVL_tree::left_rotate(Node* y) {
	Node* x = y->right;
	Node* T3 = x->left;
	x->left = y;
	y->right = T3;
	y->height = 1 + max(get_height(y->left), get_height(y->right));
	x->height = 1 + max(get_height(x->left), get_height(x->right));
	return x;
}
//��ӵ��û��ӿ�
void AVL_tree::add(int k, string v) {
	this->root = add(this->root, v, k);
}
//����nodeΪ���ڵ������Ԫ��
//������Ӻ�ĸ��ڵ�
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
	//ά���ڵ��height
	node->height = 1 + max(get_height(node->left), get_height(node->right));
	//����һ��ƽ�����ӣ����Ƿ���Ҫά����ƽ��
	int balanced_factor = get_balanced_factor(node);
	//LL��
	if (balanced_factor > 1 && get_balanced_factor(node->left) >= 0)
		return right_rotate(node);
	//RR��
	if (balanced_factor < -1 && get_balanced_factor(node->left) <= 0)
		return left_rotate(node);
	//LR�� 
	if (balanced_factor > 1 && get_balanced_factor(node->left) < 0) {
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}
	//RL��
	if (balanced_factor < -1 && get_balanced_factor(node->left) > 0) {
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}
	return node;
}
//ɾ�����е�ָ���ڵ�
string AVL_tree::remove(int k) {
	string e = get_node(this->root, k)->value;
	remove(this->root, k);
	return e;
}
//��ȡָ��Ԫ�صĽڵ�
Node* AVL_tree::get_node(Node* node, int k) {
	if (node == nullptr)return nullptr;
	if (node->key == k)return node;
	if (node->key > k)return get_node(node->left, k);
	else return get_node(node->right, k);
}
//��Ѱ������nodeΪ���ڵ����СԪ�صĽڵ�
Node* AVL_tree::search_min(Node* node) {
	if (node->left == nullptr)return node;
	return search_min(node->left);
}
//�ݹ���ã�ɾ����nodeΪ���ڵ��Ŀ��ڵ�
//����ɾ����ĸ��ڵ�
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
		//Ŀ��û��������
		if (node->right == nullptr) {
			Node* res = node->left;
			node->left = nullptr;
			size--;
			ret = res;
		}
		//Ŀ��û��������
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
	//ά���ڵ��height
	ret->height = 1 + max(get_height(ret->left), get_height(ret->right));
	//����һ��ƽ�����ӣ����Ƿ���Ҫά����ƽ��
	int balanced_factor = get_balanced_factor(ret);
	//LL��
	if (balanced_factor > 1 && get_balanced_factor(ret->left) >= 0)
		return right_rotate(ret);
	//RR��
	if (balanced_factor < -1 && get_balanced_factor(ret->left) <= 0)
		return left_rotate(ret);
	//LR�� 
	if (balanced_factor > 1 && get_balanced_factor(ret->left) < 0) {
		ret->left = left_rotate(ret->left);
		return right_rotate(ret);
	}
	//RL��
	if (balanced_factor < -1 && get_balanced_factor(ret->left) > 0) {
		ret->right = right_rotate(ret->right);
		return left_rotate(ret);
	}
	return ret;
}