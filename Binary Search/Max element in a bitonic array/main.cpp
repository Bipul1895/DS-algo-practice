#include <iostream>

using namespace std;

int max_bitonic_array(int arr[], int n) {//finding peak element
    int low=0, high=n-1;
    while(low<high) {
        int mid=(low+high)/2;
        if(mid+1<=high && arr[mid]<arr[mid+1]) {
            low=mid+1;
        }
        else if(mid-1>=low && arr[mid-1]>arr[mid]){
            high=mid-1;
        }
        else return arr[mid];
    }
    return arr[low];
}

int idx_max_bitonic_array(int arr[], int n) {//finding index of peak element
    int low=0, high=n-1;
    while(low<high) {
        int mid=(low+high)/2;
        if(mid+1<=high && arr[mid]<arr[mid+1]) {
            low=mid+1;
        }
        else if(mid-1>=low && arr[mid-1]>arr[mid]){
            high=mid-1;
        }
        else return mid;
    }
    return low;
}

int b_rev_search(int arr[], int n, int key, int st, int ed) {
    while(st<=ed) {
        int mid=(st+ed)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid] > key) {
            st=mid+1;
        }
        else {
            ed=mid-1;
        }
    }
    return -1;
}


int b_search(int arr[], int n, int key, int st, int ed) {
    while(st<=ed) {
        int mid=(st+ed)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid] > key) {
            ed=mid-1;
        }
        else {
            st=mid+1;
        }
    }
    return -1;
}

int search_bitonic_array(int arr[], int n, int key) {
    int idx_max=idx_max_bitonic_array(arr,n);
    if(arr[idx_max] == key) {
        return idx_max;
    }
    int idx_r=b_rev_search(arr,n,key,idx_max+1,n-1);
    int idx_l=b_search(arr,n,key,0,idx_max-1);

    if(idx_r != -1) return idx_r;
    if(idx_l != -1) return idx_l;
    return -1;

}

int main()
{
    int arr[] {1,3,8,12,4,2};
    int n=sizeof(arr)/sizeof(int);

    cout << max_bitonic_array(arr,n) << "\n";
    cout << search_bitonic_array(arr,n,4) << "\n";

    cout << endl;
    return 0;
}
