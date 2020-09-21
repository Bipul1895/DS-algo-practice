#include <iostream>

using namespace std;

int bs_ceil(int arr[], int n, int key) {
    int low=0,high=n-1;
    int ans_idx=-1;
    while(low<=high) {
        int mid=low + (high-low)/2;
        if(arr[mid] < key) {
            low=mid+1;
        }
        else {
            ans_idx=mid;
            high=mid-1;
        }
    }
    return ans_idx;
}

int bs_floor(int arr[], int n, int key) {
    int low=0,high=n-1;
    int ans_idx=-1;
    while(low<=high) {
        int mid=low + (high-low)/2;
        if(arr[mid] <= key) {
            ans_idx=mid;
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return ans_idx;
}

int main()
{
    int arr[] {15};
    int n=sizeof(arr)/sizeof(int);
    int key=12;

    int ceil_element_idx=bs_ceil(arr,n,key);
    int floor_element_idx=bs_floor(arr,n,key);

    int ans_element;
    if(ceil_element_idx!=-1 && floor_element_idx!=-1) {
        int diff_ceil=arr[ceil_element_idx] - key;
        int diff_floor=key - arr[floor_element_idx];

        if(diff_ceil < diff_floor) {
            ans_element=arr[ceil_element_idx];
        } else {
            ans_element=arr[floor_element_idx];
        }
    }
    else if(ceil_element_idx!=-1) {
        ans_element=arr[ceil_element_idx];
    }
    else {
        ans_element=arr[floor_element_idx];
    }

    cout << ans_element << "\n";

    return 0;
}
