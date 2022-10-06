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
//添加一个新的键值对
void Map::add(int k, string v) {
	avl->add(k, v);
}
//改变目标键所对应的值
void Map::set(int k, string v) {
	avl->add(k, v);
}
//删除操作，并返回值
string Map::remove(int k) {
	return avl->remove(k);
}
//是否包含K
bool Map::contains(int k) {
	return avl->contains(k);
}
//返回k所对应的value
string Map::get(int k) {
	return avl->get(k);
}
