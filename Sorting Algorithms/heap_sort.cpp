/**
 * Author : R. Harish Navnit <harishnavnit@gmail.com>
 * Program to implement heap sort on an array of numbers
 */

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* Function prototypes */
bool isHeap(vector<int>& );
void heapSort(vector<int>& );
int deleteRoot(vector<int>& );
void deleteNode(vector<int>&, int );
vector<int> buildHeap(vector<int>& );

/* Main method */
int main(int argc, char* argv[])
{
    int node;
    vector<int> heap;

    cout << "? ";
    while(cin >> node && node != -1) {
        heap.push_back(node);
    }

    if (!isHeap(heap))
        heap = buildHeap(heap);
    heapSort(heap);

    return 0;
}

/**
 * Check if a sequence of numbers form a heap
 * Eg : Max-Heap with
 *      nodes = [8, 7, 6, 3, 5, 4, 1]
 *      index = {0  1  2  3  4  5  6}
 *
 *              8
 *             / \
 *            /   \
 *           7     6
 *          / \   / \
 *         3   5 4   1
 */
bool isHeap(vector<int> &h)
{
    // BEGIN-DEBUG
        //cout << "isHeap(vector<int> &h)" << endl;
    // END-DEBUG

    bool propertyViolation = false;
    int i, rightChild, leftChild;
    int rightChildIndex, leftChildIndex;

    if (h.empty()) {
        cout << "\nEmpty heap. Returning";
        return false;
    }

    // BEGIN-DEBUG
        cout << "\n\tSize of heap now = " << h.size();
        cout << "\n\tElements fo heap = ";
        for (int i = 0; i < h.size(); i++) {
            cout << h[i] << " ";
        }
        cout << endl;
    // END-DEBUG

    for (i = 0; i < h.size(); i++) {
        leftChildIndex = (2*i) + 1;
        rightChildIndex= (2*i) + 2;

        if (leftChildIndex < h.size())     leftChild = h[leftChildIndex];
        if (rightChildIndex < h.size())    rightChild= h[rightChildIndex];

        if (!(h[i] >= leftChild && h[i] >= rightChild)) {
            propertyViolation = true;
            break;
        }
    }
    return propertyViolation;
}

/**
 * Build a heap from a sequence of numbers
 * Eg : Max-Heap with
 *      nodes = [5, 7, 4, 1, 8, 6, 3]
 *      index = {0  1  2  3  4  5  6}
 *
 *              5
 *             / \
 *            /   \
 *           7     4
 *          / \   / \
 *         1   8 6   3
 *  Index of last non-leaf node = floor_func(7/2)
 *                              = floor_func(3.5)
 *                              = 3 (Assuming, Indexing starts from 1)
 *  Index of last non-leaf node = 2 (Assuming, Indexing starts from 0)
 */
vector<int> buildHeap(vector<int> &h)
{
    // BEGIN-DEBUG
        //cout << "\nbuildHeap(vector<int> &h)" << endl;
    // END-DEBUG

    int i, rightChild, leftChild;
    int rightChildIndex, leftChildIndex;
    int lastNonLeafNode = (h.size()/2) - 1;

    for (i = lastNonLeafNode; i >=0; i--) {
        leftChildIndex = (2*i) + 1;
        rightChildIndex= (2*i) + 2;

        if (leftChildIndex < h.size())     leftChild = h[leftChildIndex];
        if (rightChildIndex < h.size())    rightChild= h[rightChildIndex];

        if (h[i] < leftChild || h[i] < rightChild) {
            if (leftChild > rightChild)
                swap(h[i], leftChild);
            else swap(h[i], rightChild);
        }
    }

    if (!isHeap(h)) buildHeap(h);
}

/**
 * @brief: Delete a node from the heap
 */
void deleteNode(vector<int> &h, int val)
{
    // BEGIN-DEBUG
        //cout << "deleteNode(vector<int> &h, int val)" << endl;
    // END-DEBUG

    int left= 0, mid, right = h.size()-1;

    if ( !(find(h.begin(), h.end(), val) != h.end()) ) {
        sort(h.begin(), h.end());

        // Binary-search to find the index of the node
        mid = (right-left)/2;
        while (val != mid) {
            if (val < h[mid]) {
                right = mid;
                mid = (right-left)/2;
            } else if (val > h[mid]) {
                left = mid;
                mid = (right-left)/2;
            } else {
                cout << "\nDeleting node at index " << mid
                    << "with value = " << val << endl;
            }
        }
    }

    h.erase(h.begin() + mid);
    buildHeap(h);
}

/**
 * @brief: Delete the root node from the heap.
 * Equivalent to extracting the min/max element
 * from a min/max heap.
 * Time complexity = O(logn)
 * 
 * @return value of the deleted node
 */
int deleteRoot(vector<int> &h)
{
    // BEGIN-DEBUG
        cout << "\ndeleteRoot(vector<int> &h)" << endl;
    // END-DEBUG

    int root = h.at(0);
    // BEGIN-DEBUG
        cout << "\tRoot = " << root << endl;
    // END-DEBUG
    swap(h[0], h[h.size()-1]);
    h.erase(h.begin() + h.size()-1);
    if (!(isHeap(h)))
        h = buildHeap(h);
    return root;
}

/**
 * Implementing the heap sort algorithm
 */
void heapSort(vector<int> &h)
{
    // BEGIN-DEBUG
        cout <<"heapSort(vector<int> &h)" << endl;
    // END-DEBUG

    int deletedValue;
    h = buildHeap(h);
    cout << "\nSorting nodes ... ";
    while ( !h.empty() ) {
        deletedValue = deleteRoot(h);
        cout << deletedValue << " ";
    }
    cout << endl;
}
