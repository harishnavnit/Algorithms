/* Program to implement quicksort algorithm on an array of integers */

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

/* Function prototypes */
void quicksort(int [], int, int);
int partition(int [], int, int);

/* Main method */
int main(int argc, char const* argv[])
{
    int arr[10], end, start=0;                  //initial declarations

    cout<<"\nEnter the size of the array : ";
    cin>>end;
    cout<<"\nEnter the array elements :  ";
    for(int i=0; i<end; i++) {
        cin>>arr[i];
    }

    quicksort(arr, start, end);                 //function call

    /* Print the array after applying the quicksort() algorithm */
    cout<<"\nThe array after sorting( using Quicksort() ) is as follows : \n\n";
    for(int i=0; i<end; i++) {
        cout<<" "<<arr[i];
    }

    cout<<endl<<endl;

    return EXIT_SUCCESS;
}

/* Function definitions */

/* Quicksort algorithm */
void quicksort(int a[10], int start, int end) {

    int new_index;

    if(start < end) {
        new_index = partition(a, start, end);
        quicksort(a, start, new_index - 1);
        quicksort(a, new_index + 1, end);
    }
}

/* Partitioning the array into two subsets */
int partition(int a[10], int start, int end) {

    int pivot = a[end];
    int current_index = a[start];

    for(int i=start; i < end; i++) {
        if(a[i] < pivot) {
            swap(a[current_index], a[i]);
            current_index += 1;             //increment the current index
        }
        else {
            // Do nothing
            continue;
        }
    }

    swap(a[current_index], a[end]);         // swap the current index and the pivot

    return current_index;
}
