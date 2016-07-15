/* Given an array that represents elements of arithmetic progression in order.
 * One element is missing, find the missing element
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int missingElement(vector<int> , int );

int main(int argc, char *argv[])
{
    int in;
    char ch;
    vector<int> ap;
    cout << "\nEnter the sequence : ";
    while (cin >> in) {
        if (in == 99)   break;
        ap.push_back(in);
    }
    int missingVal = missingElement(ap, ap.size()/2);
    cout << missingVal << endl;
    return 0;
}

int missingElement(vector<int> ap, int mid)
{
    int val;

    if (mid == 0)   return 0;
    if (mid == 1)   return 1;

    if (ap[mid] - ap[mid-1] != ap[mid+1] - ap[mid]) {
        if (ap[mid] - ap[mid - 1] > ap[mid + 1] - ap[mid]) {
            val = ap[mid - 1] + (ap[mid + 1] - ap[mid]);
        } else {
            val = ap[mid] + (ap[mid] - ap[mid - 1]);
        }
    } else {
        if (mid - mid/2 > 0)            missingElement(ap, mid - mid/2);
        if (mid + mid/2 < ap.size())    missingElement(ap, mid + mid/2);
    }
    return val;
}
