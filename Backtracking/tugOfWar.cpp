/* Given set of 'n' integers, divide the set in two subsets of 'n/2' sizes each.
 * Such that difference of the sum of the two subsets is as minimum as possible.
 */

#include <vector>
#include <iostream>
#include <algorithm>

void minimumDivide(vector<int> );

int main(int argc, char *argv[])
{
    int el = 0;
    vector<int> v;
    cout << "\nEnter elements:  ";
    while (cin >> el) {
        v.push_back(el);
    }
    minimumDivide(v);
    return 0;
}

/* Divides the vector into two subsets,
 * such that the difference of the sum of the two
 * subsets is minimum
 */
void minimumDivide(vector<int> v)
{
    
}