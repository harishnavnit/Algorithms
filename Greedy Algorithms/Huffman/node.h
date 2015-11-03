#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>

class Iterator_Node;

class Node {
private:
	int data;
	Node *right;
	Node *left;

public:
	Node() : data(), right(NULL), left(NULL) { }
	Node(int num) : data(num), right(NULL), left(NULL) { }

	/* Getter Functions */
	int get_data() const { return data;}
	Node* get_right_ptr() const { return right; }
	Node* get_left_ptr() const { return left; }

	/* Setter Functions */
	void set_data(int d) { data = d; return; }
	void set_right_ptr(Node *ptr) { right = ptr; return; }
	void set_left_ptr(Node *ptr) { left = ptr; return; } 

	friend class Iterator_Node;
};

#endif //__NODE_H__