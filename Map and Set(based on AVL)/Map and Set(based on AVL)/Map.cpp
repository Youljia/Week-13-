#include "Map.h"
Map::Map() {
	this->avl = new AVL_tree();
}
Map::~Map() {
	if (this->avl != nullptr)
		delete avl;
	avl = nullptr;
}
int Map::get_size() {
	return avl->get_size();
}
bool Map::is_empty() {
	return avl->is_empty();
}
//���һ���µļ�ֵ��
void Map::add(int k, string v) {
	avl->add(k, v);
}
//�ı�Ŀ�������Ӧ��ֵ
void Map::set(int k, string v) {
	avl->add(k, v);
}
//ɾ��������������ֵ
string Map::remove(int k) {
	return avl->remove(k);
}
//�Ƿ����K
bool Map::contains(int k) {
	return avl->contains(k);
}
//����k����Ӧ��value
string Map::get(int k) {
	return avl->get(k);
}
