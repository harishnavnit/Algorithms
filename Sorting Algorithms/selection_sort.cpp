/* Program to implement selection sort */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

/* Function prototype */
void selection_sort(int [], int);

/* Main method */
int main(int argc, char const* argv[])
{
    int arr[10], n;

    cout<<"\nEnter the size of the array : ";
    cin>>n;

    cout<<"\nEnter the elements of the array : ";
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"\nThe array after sorting is as follows \n";
    /* Function call */
    selection_sort(arr, n);

    cout<<endl<<endl;

    return 0;
}

/* Function definition */
void selection_sort(int a[10], int size) {

    int smallest;

    for(int j=0; j<size-1; j++) {
        smallest = j;
        for(int i = j+1; i<size; i++) {
            if(a[i] < a[smallest]) {
                smallest = i;
            }
        }

        swap(a[j],a[smallest]);
    }

    /* Display the array after sorting */
    for(int i=0; i<size; i++) {
        cout<<" "<<a[i];
    }
}
