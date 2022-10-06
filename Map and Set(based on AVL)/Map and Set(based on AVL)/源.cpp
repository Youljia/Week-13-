#include<iostream>
#include"AVL_tree.h"
#include"Map.h"
#include"Set.h"
using namespace std;
int main() {
	//测试AVL树
	AVL_tree avl;
	avl.add(0, "小学");
	avl.add(1, "初中");
	avl.add(2, "高中");
	avl.add(3, "小学");
	avl.add(3, "大学");
	cout << avl.get(3) << endl;
	cout << avl.get(8) << endl;
	if (avl.contains(2))
		cout << "包括2" << endl;
	if (avl.contains(8))
		cout << "包括8" << endl;

	//测试基于AVL树的Map
	Map m;
	m.add(0, "小学");
	m.add(1, "初中");
	m.add(2, "高中");
	m.add(3, "小学");
	m.add(3, "大学");
	cout << m.get_size() << endl;
	cout << m.get(3) << endl;
	cout << m.get(8) << endl;
	if (m.contains(2))
		cout << "包括2" << endl;
	if (m.contains(8))
		cout << "包括8" << endl;

	//测试基于AVL树的Set
	Set s;
	s.add(1);
	s.add(2);
	s.add(3);
	if (s.contains(2))
		cout << "包括2" << endl;
	if (s.contains(8))
		cout << "包括8" << endl;
	return 0;
}