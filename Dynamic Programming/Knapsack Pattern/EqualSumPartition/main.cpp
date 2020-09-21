#include <iostream>
#include <vector>
using namespace std;

bool equal_sum_partition(int arr[],int n,int target_sum,vector<vector<int> >& memo) {
    if(n==0) return target_sum==0;
    if(target_sum==0) return true;

    if(memo[n][target_sum] != -1) return memo[n][target_sum];

    if(arr[n-1] <= target_sum) {
        return memo[n][target_sum]=equal_sum_partition(arr,n-1,target_sum-arr[n-1],memo)
                    || equal_sum_partition(arr,n-1,target_sum,memo);
    }
    else {
        return memo[n][target_sum]=equal_sum_partition(arr,n-1,target_sum,memo);
    }

}

int main()
{
    int n,target_sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        target_sum+=arr[i];
    }

    if(target_sum%2 != 0) {
        cout << "Partition is not possible\n";
        return 0;
    }

    vector<vector<int> > memo(n+1,vector<int>(target_sum/2 + 1, -1));

    if(equal_sum_partition(arr,n,target_sum/2,memo)) {
        cout << "Partition is possible\n";
    } else {
        cout << "Partition is NOT possible\n";
    }

    cout<<endl;
    return 0;
}
