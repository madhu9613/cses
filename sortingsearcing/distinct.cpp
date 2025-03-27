// // You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        s.insert(data);
    }
    cout<<s.size()<<endl;

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100000 // Adjust as per the expected range of integers

// int main() {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int *arr = (int *)malloc(n * sizeof(int));
//     int *hash = (int *)calloc(MAX, sizeof(int)); // Hash array for tracking
//     int distinct_count = 0;

//     printf("Enter %d elements:\n", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//         if (hash[arr[i]] == 0) { // If number is not yet encountered
//             hash[arr[i]] = 1;
//             distinct_count++;
//         }
//     }

//     printf("Number of distinct elements: %d\n", distinct_count);

//     // Free allocated memory
//     free(arr);
//     free(hash);

//     return 0;
// }


