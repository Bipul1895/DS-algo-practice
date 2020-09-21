#include <iostream>
#include <stack>

using namespace std;

/**
 * Identification of stack : Dependent nested for loops can be optimized from O(N*N) to O(N) using stack
 */

/**
 * Problem : Next greater element on the right
 */

 void next_greater_element_naive(int nums[], int n) {
    for(int i=0;i<n;i++) {
        int bigger=-1;
        for(int j=i+1;j<n;j++) {
            if(nums[j] > nums[i]) {
                bigger=nums[j];
                break;
            }
        }
        nums[i]=bigger;
    }
 }

 void next_greater_element(int nums[], int n) {
    stack<int> stk;
    for(int i=0;i<n;i++) {
        while(!stk.empty() && nums[stk.top()] < nums[i]) {
            nums[stk.top()]=nums[i];
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()) {
        nums[stk.top()]=-1;
        stk.pop();
    }
 }

int main()
{
    int arr[] = {4, 5, 2, 25};
    int n=sizeof(arr)/sizeof(int);

    //next_greater_element_naive(arr,n);
    next_greater_element(arr,n);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout<<"\n";

    cout << endl;
    return 0;
}
