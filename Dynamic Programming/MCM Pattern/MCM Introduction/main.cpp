#include <bits/stdc++.h>
using namespace std;

/**
 * Identification of MCM : Break at several places k for a sub-problem b/w idx i and j
 */

/**
 * Format code
 */
int solve(int arr[] , int i, int j) {
    if(i>j) return 0;

    //i is near left end index
    //j is near right end index

    int ans=INT_MIN;

    for(int k=i;k<j;k++) {
        int temp_ans = solve(arr,i,k) + solve(arr,k+1,j);
        ans = max(ans, temp_ans);
    }

    return ans;

}

int main()
{



    cout<<endl;
    return 0;
}
