#include <iostream>
#include <vector>
using namespace std;

int count_subsets_given_sum(int arr[], int n, int target_sum, vector<vector<int> >& memo) {
    if(n==0) {
        if(target_sum==0) return 1;
        return 0;
    }

    if(memo[n][target_sum] != -1) return memo[n][target_sum];

    if(arr[n-1] <= target_sum) {
        return memo[n][target_sum]=count_subsets_given_sum(arr,n-1,target_sum-arr[n-1],memo) +
                count_subsets_given_sum(arr, n-1, target_sum,memo);
    }
    return memo[n][target_sum]=count_subsets_given_sum(arr,n-1,target_sum,memo);

}

int main()
{
    int arr[] {0,0,0,0,0,0,0,0,1};
    int n=sizeof(arr)/sizeof(int);
    int diff=1;

    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];

    if((sum+diff)%2 != 0) {
        cout << 0 << "\n";
    } else {
        int req_sum=(sum+diff)/2;
        vector<vector<int> > memo(n+1, vector<int>(req_sum+1,-1));
        cout << count_subsets_given_sum(arr,n,req_sum,memo) << "\n";
    }

    int num_subset_sum[n+1][sum+1];
    for(int i=0;i<=n;i++) {
        num_subset_sum[i][0]=1;
    }
    for(int j=1;j<=sum;j++) {
        num_subset_sum[0][j]=0;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum;j++) {
            if(arr[i-1] <= j) {
                num_subset_sum[i][j]=num_subset_sum[i-1][j-arr[i-1]] + num_subset_sum[i-1][j];
            } else {
                num_subset_sum[i][j] = num_subset_sum[i-1][j];
            }
        }
    }

    int num_subsets=0;
    for(int j=0;j<=sum;j++) {
        if(sum - 2*j == diff) {
            num_subsets += num_subset_sum[n][j];
        }
    }

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=sum;j++) {
            cout << num_subset_sum[i][j] << " ";
        }
        cout << "\n";
    }

    cout << num_subset_sum[n][1] << "\n";

    cout << num_subsets;

    cout<<endl;
    return 0;
}
