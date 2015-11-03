#include "prim.h"

using namespace std;

/* Insert and edge between two vertices */
void prim_graph :: insert(string from_a, string to_b) {

    multimap<string, set<string>, int > :: iterator from_temp_a, to_temp_b;

    from_temp_a = data.find(from_a);
    to_temp_b   = data.find(to_b  );

    if(from_temp_a == data.end()) {
        // Edge from_a not found, so insert it
        set<string> temp_set;
        temp_set.insert(to_b);
        pair<string, set<string> > temp_pair(from_a, temp_set);
        data.insert(temp_pair);
    }
    else if(from_temp_a != data.end()) {
        from_temp_a->second.insert(to_b);
    }
    else {
        cerr<<"\nOops ! That's awkward :( "<<endl;
    }

    if(to_temp_b = data.end()) {
        // Edge from b not found
        set<string> temp_set;
        temp_set.clear();
        temp_set.insert(from_a);
        pair<string, set<string> > temp_pair(to_b, temp_set);
        data.insert(temp_pair);
    }
    else if(to_temp_b != data.end()) {
        to_temp_b->second.insert(from_a);
    }
    else {
        cerr<<"\nOops ! That's awkward :( "<<endl;
    }
}

/* Delete a vertex and all edges containing it */
void prim_graph :: delete_vertex(string a) {
    multimap<string, set<string>, int > temp_iter = data.find(a);

    if(temp_iter == data.end()) {
        cout<<"\nVertex not found"<<endl;
    }
    else {
        map<string, set<string>, int > iterator new_iter;

        for(new_iter = data.begin(); new_iter != data.end(); ++new_iter) {
            new_iter->second.erase(a);
        }

        data.erase(temp_iter);
    }
}

/* Delete an edge from the graph */
void prim_graph :: delete_edge(string from_a, string to_b) {
    multimap<string, set<string>, int > :: iterator x, y;

    x = data.find(from_a);
    y = data.find(to_b  );

    if(x != data.end() and y != data.end() ) {
        x->second.erase(to_b  );
        y->second.erase(from_a);
    }
    else {
        cerr<<"\nEdge not present"<<endl;
    }
 }

/* Find the MST using Prim's algorithm
 * and return the weight of the resulting
 * MST
 */
int prim_graph :: MST_using_PRIMS(string start_vertex) {
    vector<string> vertices;
    vector<int>    weight;
    multimap<string, set<string>, int > :: iterator v_iter;
    int small, rev_small;

    v_iter = data.find(start_vertex);
    vertices.push_back(v_iter->first);
    weight.push_back(v_iter->third);

    for(multimap<string, set<string>, int> :: iterator i = v_iter; i != data.end(); ++i) {
        if(i->third < small) {
            small = i->third;
        }
    }

    for(multimap<string, set<string>, int> :: iterator i = v_iter; i != data.begin(); --i) {
        if(i->third < small) {
            rev_small = i->third;
        }
    }

    if(rev_small < small) {
        v_iter = data.find(rev_small);
        vertices.push_back(v_iter->first);
        weight.push_back(v_iter->third);
    }
    else if(small < rev_small) {
        v_iter = data.find(small);
        vertices.push_back(v_iter->first);
        weight.push_back(v_iter->third);
    }
    else {
        /* Equal Weights */
        multimap<string, set<string>, int > :: iterator temp_small, temp_rev_small;
        temp_small = data.find(small);
        temp_rev_small = data.find(rev_small);

        for(int i = 0; i < vertices.size(); i++ ) {
            if(vertices[i] != temp_small->first &&
                    vertices[i] != temp_rev_smal->first) {
                vertices.push_back(small);
            }
            else if(vertices[i] != temp_small->first) {
                vertices[i].push_back(small);
            }
            else if(vertices[i] != temp_rev_small->first) {
                vertices[i].push_back(rev_small);
            }
        }
   }

}

/* Print the MST obtained from Prim's algorithm */
void prim_graph :: print_MST() {

}

/* Print the Graph structure */
void prim_graph :: print() {
    cout<<"\nPrinting the edges and vertices in the graph"<<endl;

    multimap<string, set<string>, int > :: iterator iter;

    for(iter=data.begin(); iter != data.end(); ++iter) {
        cout<<iter->first;

        for(set<string> :: iterator i = iter->second.begin(); i != iter->second.end(); i++) {
            cout <<" --> "<< *i;
        }

        cout<<";"<<endl;
    }
}
