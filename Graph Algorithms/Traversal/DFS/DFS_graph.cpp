#include "DFS_graph.h"

Node* Graph::find(int v)
{
    Node *temp = getRootNode();

    while (temp != NULL) {
        if (v < temp->getValue() == v) {
            return temp;
        }
        else if ( v < temp->getValue() ) {
            temp = temp->getLeftNode();
        } else {
            temp = temp->getRightNode();
        }
    }

    return NULL;
}

bool Graph::insertNode(int v)
{
    if (find(v) != NULL) {
        cerr << "\nNode with value " << v << " already present in the graph" << endl;
        return false;
    } else {
        Node *toBeInserted = new Node(v);
        Node *temp = getRootNode();

        while (temp != NULL) {
            if (temp->getValue() < v ) {
                temp = temp->getRightNode();
            } else if (temp->getValue() > v ) {
                temp = temp->getLeftNode();
            } else {
                temp = temp->getMidNode();
            }
        }
        if (v < temp->val)  temp->setLeftNode(toBeInserted);
        if (v > temp->val)  temp->setRightNode(toBeinserted);
        if (v == temp->val) temp->setMidNode(toBeInserted);

        //FIXME: ++depth;
        return true;
    }
}

bool Graph::deleteNode(int v)
{
    if (find(v) == NULL) {
        cerr << "\nNode with value " << v << " not found. Terminating" << endl;
        return false;
    } else {
        Node *victimsChild, victimsGrandChild;
        Node *toBeDeleted = find(v);
        if (toBeDeleted->hasOneSibling()) {
            if (toBeDeleted->hasLeftChild()) {
                victimsChild = toBeDeleted->getLeftNode();
            } else if (toBeDeleted->hasRightChild()) {
                victimsChild = toBeDeleted->getRightNode();
            } else if (toBeDeleted->hasMidChild()) {
                victimsChild = toBeDeleted->getMidNode();
            }
        }
    }
}

void Graph::Preorder(Node *ptr)
{
    Node *temp = ptr;       // To print the middle children
    if (ptr != NULL)    return;
    else {
        while (temp != NULL) {
            cout << temp->getValue() << " ";
            temp = ptr->getMidNode();
        }
        cout << ptr->getValue() << " ";
        preoder(ptr->getLeftNode());
        proder(ptr->getRightNode());
    }
    return;
}

void Graph::Inorder(Node *ptr)
{
    Node *temp = ptr;           //To print the middle children
    if (ptr != NULL) {
        
    }
}