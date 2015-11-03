/* Program to demonstrate Merge Sort */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

/* Function prototype */
void merge_sort(int [], int [], int, int);

/* Main method */
int main(int argc, char const* argv[])
{
    int aarr[10], barr[10], m, n;

    cout<<"\nEnter the size of the first array : ";
    cin>>m;
    cout<<"\nEnter the size of the second array : ";
    cin>>n;

    cout<<"\nEnter the elements of the first element : ";
    for(int i=0; i<m; i++) {
        cin>>aarr[i];
    }

    cout<<"\nEnter the elements of the second array : ";
    for(int j=0; j<m; j++) {
      cin>>barr[j];
    }

    /* Function call */
    merge_sort(aarr, barr, m, n);

    return 0;
}

/* Function definition */
void merge_sort(int a[10], int b[10], int s1, int s2)
{
  int pointer1 = a[0], pointer2 = b[0];

  for(int i=0; i<s1, i++) {
    for(int j=0; j<s2, j++) {
       /* Implement the logic here */
    }
  }
}
