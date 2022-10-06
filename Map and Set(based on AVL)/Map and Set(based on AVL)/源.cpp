#include<iostream>
#include"AVL_tree.h"
#include"Map.h"
#include"Set.h"
using namespace std;
int main() {
	//����AVL��
	AVL_tree avl;
	avl.add(0, "Сѧ");
	avl.add(1, "����");
	avl.add(2, "����");
	avl.add(3, "Сѧ");
	avl.add(3, "��ѧ");
	cout << avl.get(3) << endl;
	cout << avl.get(8) << endl;
	if (avl.contains(2))
		cout << "����2" << endl;
	if (avl.contains(8))
		cout << "����8" << endl;

	//���Ի���AVL����Map
	Map m;
	m.add(0, "Сѧ");
	m.add(1, "����");
	m.add(2, "����");
	m.add(3, "Сѧ");
	m.add(3, "��ѧ");
	cout << m.get_size() << endl;
	cout << m.get(3) << endl;
	cout << m.get(8) << endl;
	if (m.contains(2))
		cout << "����2" << endl;
	if (m.contains(8))
		cout << "����8" << endl;

	//���Ի���AVL����Set
	Set s;
	s.add(1);
	s.add(2);
	s.add(3);
	if (s.contains(2))
		cout << "����2" << endl;
	if (s.contains(8))
		cout << "����8" << endl;
	return 0;
}