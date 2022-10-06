#include<iostream>
#include"AVL_tree.h"
using namespace std;
int main() {
	AVL_tree avl;
	avl.add(2, "高中");
	avl.add(1, "初中");
	avl.add(0, "小学");
	avl.add(3, "大学");
	cout << avl.get_size() << endl;
	if (avl.is_AVL())
		cout << "是平衡树" << endl;
	else
		cout << "不是平衡树" << endl;
	if (avl.is_BST())
		cout << "是二分搜索树" << endl;
	else
		cout << "不是二分搜索树" << endl;
	avl.remove(3);
	if (avl.is_AVL())
		cout << "是平衡树" << endl;
	else
		cout << "不是平衡树" << endl;
	if (avl.is_BST())
		cout << "是二分搜索树" << endl;
	else
		cout << "不是二分搜索树" << endl;
	return 0;
}