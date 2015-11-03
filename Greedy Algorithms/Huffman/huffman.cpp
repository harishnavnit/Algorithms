#include "huffman.h"

using namespace std;

/* Function prototypes 					*/
void huffman_encode(map<char, int> );



/* Function definition 						*/
int huffman_encode(map<int, char> data) {
	/* Steps to be followed : 
	 * 1. Sort the values(chars) according to their frequencies
	 * 2. In each iteration, combine the least frequent elements.
	 * 3. In the final tree obtained, assign values 0 and 1 to the left and right edges uniformly
	 */

	typedef pair<int, char> combine_pair;
	queue<combine_pair> q;
	map<int, char> :: iterator itr;

	/* Insert pairs of chars and frequency into the queue
	 * in order to combine the least frequent elements
	 * Populating the queue with the data elements.
	 */
	for(itr = data.begin(); itr != data.end(); itr++) {
		combine_pair combine(itr->first, itr->second);
		q.push_back(combine);
	}

	queue<combine_pair> :: iterator i = q.end();
	while(i != q.begin()) {
		pair<int, char> combine;
	}
}