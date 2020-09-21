#include <iostream>
#include <vector>
using namespace std;

bool subset_sum(int arr[],int n,int target_sum,vector<vector<int> >& memo) {
    if(n==0) return target_sum==0;
    if(target_sum==0) return true;

    if(memo[n][target_sum] != -1) return memo[n][target_sum];

    if(arr[n-1] <= target_sum) {
        return memo[n][target_sum]=subset_sum(arr,n-1,target_sum-arr[n-1],memo) || subset_sum(arr,n-1,target_sum,memo);
    }
    else {
        return memo[n][target_sum]=subset_sum(arr,n-1,target_sum,memo);
    }

}

int main()
{
    int n;
    int target_sum;
    cin>> n >> target_sum;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<int> > memo(n+1, vector<int>(target_sum+1,-1));

    if(subset_sum(arr,n,target_sum,memo)) {
        cout << "Yes! subset exists\n";
        cout << "One of the subsets is : ";
        int row=n,col=target_sum;
        while(row>0 && col>0) {
            if(memo[row-1][col] != memo[row][col]) {
                cout << arr[row-1] << " ";
                col-=arr[row-1];
            }
            row--;
        }
    } else {
        cout << "No! subset does not exist\n";
    }

    cout << endl;
    return 0;
}
