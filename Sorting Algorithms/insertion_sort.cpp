/* Program to implement the insertion sort algorithm */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void insertion_sort(int [], int);

int main(int argc, char const* argv[])
{
    int arr[10], size;

    cout<<"\nEnter the size of the array : ";
    cin>>size;
    cout<<"\nEnter the elements of the array : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    insertion_sort(arr, size);      //function call

    cout<<endl<<endl;

    return 0;
}

void insertion_sort(int a[10], int size) {

    int key;

    for(int j=1; j<size; j++) {

        int i  = j-1;
        key = a[j];

        while((i>0) and (a[i] > a[i+1])) {
            swap(a[i], a[i+1]);
            i -= 1;
        }

        a[i+1] = key;
    }

    /* Display the array after sorting */
    cout<<"\nThe array after sorting is as follows : ";
    for(int k = 0; k< size; k++) {
        cout<<" "<<a[k];
    }
}
