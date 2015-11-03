#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include "node.h"
#include <iostream>

using std::cout;
using std::ostream;

class Tree {
private:
	Node *root;
	size_t tree_size;
	static int deletion_flag;

public:
	Tree() : root(NULL), tree_size(0) { }
	~Tree() { clear(); }

	void insert(int x);
	Node* get_root();
	size_t get_size() const { return tree_size; }
	bool isEmpty() const { return (tree_size == 0); }
};

#endif //__HUFFMAN_H__