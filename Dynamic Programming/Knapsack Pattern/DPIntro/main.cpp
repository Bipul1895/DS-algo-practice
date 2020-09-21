#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/**
 * 0/1 Knapsack problem
 * Two things in DP recognition :
 * 1) Optimal : maximum or minimum
 * 2) Choice will be there => recursion. If there if overlapping during recursion => DP
 */

int knapsack_recursive(int n, int weight[], int profit[], int W, vector<vector<int> >& memo) {
    //base condition
    if(n==0) return 0;
    if(W==0) return 0;

    //DP step
    if(memo[n][W] != -1) return memo[n][W];

    //choice diagram
    if(weight[n-1] <= W) {
        return memo[n][W]=max(profit[n-1] + knapsack_recursive(n-1,weight,profit,W-weight[n-1],memo),
                    knapsack_recursive(n-1,weight,profit,W,memo));
    } else {
        return memo[n][W]=knapsack_recursive(n-1,weight,profit,W,memo);
    }
}

int knapsack_iterative(int n, int weight[], int profit[], int W) {
    int memo[n+1][W+1];
    memset(memo, -1, sizeof(memo));

    for(int i=0;i<=W;i++) memo[0][i]=0;//there are no items
    for(int i=0;i<=n;i++) memo[i][0]=0;//capacity of bag=0

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=W;j++) {
            if(weight[i] > j) {
                memo[i][j] = memo[i-1][j];
            }
            else {
                memo[i][j] = max(profit[i] + memo[i-1][j-weight[i]], memo[i-1][j]);
            }
        }
    }
    return memo[n][W];
}

int main()
{

    int n;
    cin>>n;

    int W;
    cin>>W;

    int weight[n], profit[n];
    for(int i=0;i<n;i++) cin>>profit[i];
    for(int i=0;i<n;i++) cin>>weight[i];

    vector< vector<int> > memo(n+1, vector<int>(W+1,-1));

    cout << knapsack_recursive(n,weight,profit,W,memo) << "\n";

    cout << knapsack_iterative(n,weight,profit,W) << "\n";

    cout  << endl;
    return 0;
}
