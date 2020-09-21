#include <iostream>
#include <vector>
using namespace std;

int floorInSortedArray(int arr[], int n, int val) {
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high) {
        int mid=low + (high-low)/2;
        if(arr[mid] == val) return val;
        else if(arr[mid] < val) {
            ans=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n,val;
    cin >> n >> val;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout << floorInSortedArray(arr,n,val) << "\n";


    return 0;
}
