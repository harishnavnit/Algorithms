#ifndef __DFS_GRAPH_H__
#define __DFS_GRAPH_H__

#include "DFS_node.h"

class Graph
{
private:
    Node *root;
    int depth;

public:
    Graph() : root(NULL), depth(0) { }
    Graph(Node *r) : root(r) { ++depth; }

    Node* getRootNode( return root; );
    Node* find(int );

    bool isEmpty() { return root == NULL; }
    bool hasOneSibling(int v);
    bool hasTwoSiblings(int v);
    bool hasThreeSiblings(int v);
    bool insertNode(int );
    bool deleteNode(int );

    //Three modes of traversal display
    void preorder();
    void inorder();
    void postorder();

    // DFS method of traversal
    void DFS_visit();
}

#include "DFS_graph.cpp"

#endif //__DFS_GRAPH_H__