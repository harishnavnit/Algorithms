#ifndef __DFS_NODE_H__
#define __DFS_NODE_H__

#include <iostream>

class Node
{
private:
    int val;
    Node *left, *right, *mid;

public:
    Node() { }
    Node(int v) : val(v) { }

    /* Getter functions */
    int getValue() { return val; }
    Node* getLeftNode() { return left; }
    Node* getRightNode(){ return right;}
    Node* getMidNode() { return mid;}

    /* Setter functions */
    void setValue(int v) { val = v; }
    void setLeftNode(Node *p) { left = p; }
    void setRightNode(Node *p){ right = p;}
    void setMidNode(Node *p)  { mid = p; }
}

#endif //__DFS_NODE_H__