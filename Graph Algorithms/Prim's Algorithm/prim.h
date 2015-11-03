/** Implementing the Prim's algorithm */

#ifndef __PRIM_H__
#define __PRIM_H__

#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <algorithm>
#include <climits>

/* Class for implemnting the graph algorithm */
class prim_graph {
private:
    /* Mapping between vertex 1, vertex 2 and weight of vertex 1 and vertex 2 */
    multimap<string, set<string>, int> data;

public:
    // Constructor
    prim_graph() : g_name(gname), e_weight(weight) { }

    // Utility functions
    void insert(string, string);
    void delete_vertex(string);
    void delete_edge(string);
    int MST_using_PRIMS();
    void print();
    void print_MST();
};

#include "prim.cpp"

#endif //__PRIM_H__
