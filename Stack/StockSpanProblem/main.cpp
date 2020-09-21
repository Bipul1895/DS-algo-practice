#include <iostream>
#include <stack>
using namespace std;

/**
 * Similar to next greater element to the right
 */

int main()
{
    int arr[] {100, 80, 60, 70, 60, 75, 85};
    int n=sizeof(arr)/sizeof(int);

    stack<int> stk;
    int stock_span[n];

    for(int i=n-1;i>=0;i--) {
        while(!stk.empty() && arr[i]>arr[stk.top()]) {
            int idx=stk.top();
            stk.pop();
            stock_span[idx]=idx-i;
        }
        stk.push(i);
    }
    while(!stk.empty()) {
        int idx=stk.top();
        stk.pop();
        stock_span[idx]=idx+1;
    }

    for(int i=0;i<n;i++) cout << stock_span[i] << " ";

    cout<<endl;
    return 0;
}
