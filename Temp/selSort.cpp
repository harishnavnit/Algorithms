#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int> );

int main(int argc, char *argv[])
{
    int el;
    vector<int> a;

    cout << "\nArray : ";
    while (cin.get()) {
        cin >> el;
        if (el == 99)   break;
        a.push_back(el);
    }

    selectionSort(a);
}

void selectionSort(vector<int> v)
{
    // 5 4 3 2 1
    // min = 5
    // 5 < 5 ? No  : { min = 5, v[0] = 5}
    // 4 < 5 ? Yes : { min = 4, v[1] = 5}
    // 3 < 4 ? Yes : { min = 3, v[2] = 4}
    // 2 < 3 ? Yes : { min = 2, v[3] = 3}
    // 1 < 2 ? Yes : { min = 1, v[4] = 2}

    // Sorted array : 5 5 4 3 2
    int min = v[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < min)
            swap(v[i], min);
    }

    cout << "Sorted array : ";
    for (int i = 0; i < v.size(); i++)  cout << " " << v[i];
}