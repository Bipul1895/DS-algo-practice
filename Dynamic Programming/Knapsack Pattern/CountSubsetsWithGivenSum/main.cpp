#include <iostream>
#include <vector>
using namespace std;

int count_subset_recursive(int arr[], int n, int target) {
    //base condition
    if(target==0) return 1;
    if(n==0) {
        return target==0;
    }

    //choice
    if(arr[n-1] <= target) {
        return count_subset_recursive(arr,n-1,target-arr[n-1]) + count_subset_recursive(arr,n-1,target);
    } else {
        return count_subset_recursive(arr,n-1,target);
    }
}

int count_subset_iterative(int arr[], int n, int target) {
    int memo[n+1][target+1];

    for(int i=0;i<=n;i++) memo[i][0]=1;
    for(int j=1;j<=target;j++) memo[0][j]=0;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=target;j++) {
            if(arr[i-1] <= j) {
                memo[i][j] = memo[i-1][j-arr[i-1]] + memo[i-1][j];
            } else {
                memo[i][j] = memo[i-1][j];
            }
        }
    }

    return memo[n][target];

}

int main()
{
    int arr[] {2,3,5,6,8,10};
    int n=sizeof(arr)/sizeof(int);
    int target=10;

    cout << count_subset_recursive(arr,n,target) << "\n";
    cout << count_subset_iterative(arr,n,target) << "\n";

    cout << endl;
    return 0;
}
