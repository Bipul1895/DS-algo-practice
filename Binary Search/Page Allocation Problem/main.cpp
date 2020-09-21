#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Last question in binary search playlist
 * Each student must be allocated atleast 1 book
 * Book cannot be divided, the allocated student should read all pages of the book
 * Book distribution should be continuous
 */

bool is_valid(int arr[], int n, int max_pages, int given_students) {
    int req_students=1;
    int pages=0;
    for(int i=0;i<n;i++) {
        if(pages+arr[i] > max_pages) {
            req_students++;
            pages=arr[i];
        } else {
            pages += arr[i];
        }

        if(req_students > given_students) return false;

    }
    return true;
}

int allocate_books(int arr[], int n, int given_students) {
    if(n<given_students) return -1;
    int low=0,high=0;
    for(int i=0;i<n;i++) {
        high+=arr[i];
        low=max(low,arr[i]);
    }

    int min_pages=-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(is_valid(arr,n,mid,given_students)) {
            min_pages=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }

    return min_pages;
}

int main()
{
    int n=4;
    int arr[] {10,20,30,40};
    int k=2;

    int max_pages_read_best = allocate_books(arr,n,k);
    if(max_pages_read_best == -1) {
        cout << "Books cannot be ditributed\n";
    } else {
        cout << "Min value of maximum pages read by one student : " << max_pages_read_best << "\n";
    }

    cout<<endl;
    return 0;
}
