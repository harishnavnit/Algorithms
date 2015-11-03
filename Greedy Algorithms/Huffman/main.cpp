#include "huffman.h"

using namespace std;

/* Begining of the main method 			*/
int main(int argc, char const *argv[])
{
	/* Create a map with the frequency as the key.
	 * Since in a map, the key is always sorted
	 * and that is what we wish to do
	 */
	map<int, char> values;

	int val = huffman_encode(data);
	cout<<"\nThe encoded value = "<<val<<endl;

	return 0;
}