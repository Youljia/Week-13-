#include "Set.h"
Set::Set() {
	this->avl = new AVL_tree();
}
Set::~Set() {
	if (this->avl != nullptr)
		delete avl;
	avl = nullptr;
}
void Set::add(int e) {
	avl->add(e, "none");
}
void Set::remove(int e) {
	avl->remove(e);
}
bool Set::contains(int e) {
	return avl->contains(e);
}
int Set::get_size() {
	return avl->get_size();
}
bool Set::is_empty() {
	return avl->is_empty();
}
