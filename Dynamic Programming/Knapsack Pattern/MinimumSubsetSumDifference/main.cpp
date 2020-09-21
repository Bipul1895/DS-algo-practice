#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int arr[] {1,6,5,11};
    int n=sizeof(arr)/sizeof(int);

    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];

    bool subset_sum[n+1][sum+1];
    for(int i=0;i<=n;i++) {
        subset_sum[i][0]=true;
    }
    for(int j=1;j<=sum;j++) {
        subset_sum[0][j]=false;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum;j++) {
            if(arr[i-1] <= j) {
                subset_sum[i][j] = subset_sum[i-1][j-arr[i-1]] || subset_sum[i-1][j];
            } else {
                subset_sum[i][j] = subset_sum[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++) cout << subset_sum[i][j] << " ";
        cout<<"\n";
    }

    int min_subset_sum_diff = sum;
    for(int j=1;j<sum;j++) {
        if(subset_sum[n][j]) {
            min_subset_sum_diff = min(min_subset_sum_diff, abs(sum-2*j));
        }
    }

    cout << min_subset_sum_diff << endl;
    return 0;
}
