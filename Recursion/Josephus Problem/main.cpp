#include <iostream>
#include <vector>
using namespace std;

int solve_circle(int n, int k, int idx, vector<int>& peo_num) {
    //base condition
    if(n==1) {
        return peo_num[0];
    }

    //induction
    int remove_idx = (idx+k-1)%n;
    peo_num.erase(peo_num.begin() + remove_idx);

    //hypothesis
    return solve_circle(n-1,k,remove_idx,peo_num);

}

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> peo;
    for(int i=1;i<=n;i++) peo.push_back(i);

    cout << "Safe place : " << solve_circle(n,k,0,peo) << "\n";

    return 0;
}
