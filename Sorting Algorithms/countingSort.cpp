/* Sort a list numbers using the counting sort technique.
 * Counting sort, counts the number of elements less than the current
 * and hences determines or predicts it's position in the list
 */

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void countingSort(vector<int> );

int main(int argc, char *argv[])
{
    int el;
    vector<int> v;

    cout << "\nEnter elements : ";
    while (cin >> el) {
        if (el == 99)   break;
        v.push_back(el);
    }
    countingSort(v);
    return 0;
}

void countingSort(vector<int> v)
{
    vector<int> v_new;
    map<int, int> pos;
    int compare = 0, lesserCount = 0;

    for (int i = 0; i < v.size(); i++) {
        compare = v[i];
        for (int j = 0; j < v.size(); j++) {
            if (v[j] < compare) ++lesserCount;
        }
        pos[lesserCount+1] = compare;
        lesserCount = 0;
    }

    for (int i =0; i < pos.size(); i++) {
        v_new.push_back(pos[i]);
    }

    cout << "\nApplying counting sort ... " << endl;
    for (int i = 0; i < v_new.size(); i++)
        cout << " " << v_new[i];
    cout << endl;
}