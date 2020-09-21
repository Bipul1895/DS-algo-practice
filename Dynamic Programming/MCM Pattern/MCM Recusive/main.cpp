#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

int memo[1000][1000];

int MCM_Recusrive(int arr[], int st, int ed) {
    //base condition
    if(ed-st == 1) return 0;

    if(memo[st][ed] != -1) return memo[st][ed];

    int min_cost=INT_MAX;
    //dividing matrices
    for(int k=st+1;k<ed;k++) {
        int cost_l = MCM_Recusrive(arr,st,k);
        int cost_r = MCM_Recusrive(arr,k,ed);
        int cost_mat_mul = arr[st]*arr[k]*arr[ed];
        int curr_cost = cost_l + cost_r + cost_mat_mul;

        if(st==0 && ed==4) {
            cout << cost_l << " " << cost_r << " " << cost_mat_mul << "\n";
            cout << "dimen : " << arr[st] << "*" << arr[k] << "  ,  " << arr[k] << "*" << arr[ed] << "\n";
        }

        min_cost = min(curr_cost,  min_cost);
    }

    memo[st][ed]=min_cost;

    return min_cost;

}

int main()
{
    int matrices[] {10, 20, 30};
    int n=sizeof(matrices)/sizeof(int);

    memset(memo,-1,sizeof(memo));
    cout << MCM_Recusrive(matrices,0,n-1) << "\n";

    cout<<endl;
    return 0;
}
