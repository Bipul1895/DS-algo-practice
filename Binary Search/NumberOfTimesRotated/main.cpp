#include <iostream>
#include <vector>
using namespace std;

int rotations(int arr[], int n) {
    int low=0,high=n-1;
    if(arr[low] < arr[high]) return 0;

    while(low<=high) {
        int mid=low + (high-low)/2;
        if(arr[mid] >= arr[0]) {
            low=mid+1;
        }
        else {
            if(arr[mid-1] > arr[mid]) return mid;
            else high=mid-1;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout << rotations(arr,n);

    cout<<endl;
    return 0;
}
