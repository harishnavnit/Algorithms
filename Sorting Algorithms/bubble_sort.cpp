/* Program to implement selection sort */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

/* Function prototype */
void selection_sort(int [], int );

/* Main method */
int main(int argc, char const* argv[])
{
    int arr[10], n;

    cout<<"\nEnter the size of the array : ";
    cin>>n;

    cout<<"\nEnter the elements of the array : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    /* Function call */
    selection_sort(arr, n);

    return 0;
}

/* Function definition */
void selection_sort(int a[10], int size) {

    for(int i=0; i<size; i++) {
        for(int j=0; j<size-1; j++) {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }

    cout<<"\nThe array after sorting is : ";

    for(int i=0; i<size; i++) {
        cout<<a[i]<<" ";
    }
}
