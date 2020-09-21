#include <iostream>

using namespace std;

void sort_array_recursion(int arr[], int n) {
    //base condition
    if(n==1) return;

    sort_array_recursion(arr,n-1);

    int curr_val=arr[n-1];

    int idx=n-2;
    while(idx>=0 && arr[idx] > curr_val) {
        arr[idx+1]=arr[idx];
        idx--;
    }
    arr[idx+1]=curr_val;

}

int main()
{
    int arr[] {4,7,1,3,5};
    int n=5;

    sort_array_recursion(arr,n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    cout<<endl;
    return 0;
}
