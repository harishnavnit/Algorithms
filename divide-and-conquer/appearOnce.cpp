/* Given an array in which all elements values are repeated twice,
 * find the element which appears only once
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int appearsOnce(vector<int> , int );

int main(int argc, char *argv[])
{
    int element;
    vector<int> v;

    cout << "\nEnter elements of the array : ";
    while (cin >> element) {
        if (element == 99)      break;
        v.push_back(element);
    }

    sort(v.begin(), v.end());
    cout << "\n " << appearsOnce(v, v.size()/2) << " appears exactly once in the sequence" << endl;

    return 0;
}

int appearsOnce(vector<int> v, int mid)
{
    int val=0;
    getchar();
    cout << "\nmid = " << mid;
    /* If one number is present only once,            if (mid+mid/2 < v.size())   appearsOnce(v, mid+mid/2);
     * and if all other numbers are present twice,
     * the size of the vector has to be odd
     */
    if (v.size() % 2 == 0) {
        // All numbers repeat twice
        return -1;
    } else {
        if (v.size() % 2 == 0)      return -1;
        else {
            if (v.size() == 1)      val = v[0];
            if (mid % 2 == 0) {
                if (v[mid] != v[mid+1])     val = v[mid];
            } else {
                if (v[mid] != v[mid-1])     val = v[mid-1];
            }
            if (mid+mid/2 < v.size())   appearsOnce(v, mid+mid/2);
            if (mid-mid/2 >= 0)         appearsOnce(v, mid-mid/2);
        }
    }
    return val;
}
