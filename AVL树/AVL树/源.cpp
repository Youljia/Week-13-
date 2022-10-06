#include<iostream>
#include"AVL_tree.h"
using namespace std;
int main() {
	AVL_tree avl;
	avl.add(2, "����");
	avl.add(1, "����");
	avl.add(0, "Сѧ");
	avl.add(3, "��ѧ");
	cout << avl.get_size() << endl;
	if (avl.is_AVL())
		cout << "��ƽ����" << endl;
	else
		cout << "����ƽ����" << endl;
	if (avl.is_BST())
		cout << "�Ƕ���������" << endl;
	else
		cout << "���Ƕ���������" << endl;
	avl.remove(3);
	if (avl.is_AVL())
		cout << "��ƽ����" << endl;
	else
		cout << "����ƽ����" << endl;
	if (avl.is_BST())
		cout << "�Ƕ���������" << endl;
	else
		cout << "���Ƕ���������" << endl;
	return 0;
}