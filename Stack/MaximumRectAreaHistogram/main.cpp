#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

/**
 * This problem is involves finding next smaller element on both left and right side
 */

 vector<int> next_smaller_left_side(vector<int>& heights) {
    int n=heights.size();
    vector<int> dist_next_smaller_left(n);
    stack<int> stk;

    for(int i=n-1;i>=0;i--) {
        while(!stk.empty() && heights[i]<heights[stk.top()]) {
            int idx=stk.top();
            stk.pop();
            dist_next_smaller_left[idx]=idx-i;
        }
        stk.push(i);
    }
    while(!stk.empty()) {
        int idx=stk.top();
        stk.pop();
        dist_next_smaller_left[idx]=idx+1;
    }
    return dist_next_smaller_left;
 }

 vector<int> next_smaller_right_side(vector<int>& heights) {
    int n=heights.size();
    vector<int> dist_next_smaller_right(n);
    stack<int> stk;

    for(int i=0;i<n;i++) {
        while(!stk.empty() && heights[i]<heights[stk.top()]) {
            int idx=stk.top();
            stk.pop();
            dist_next_smaller_right[idx]=i-idx;
        }
        stk.push(i);
    }
    while(!stk.empty()) {
        int idx=stk.top();
        stk.pop();
        dist_next_smaller_right[idx]=n-idx;
    }
    return dist_next_smaller_right;

 }

int main()
{
    vector<int> heights {6, 2, 5, 4, 5, 1, 6};
    int n=heights.size();

    vector<int> dist_next_smaller_left = next_smaller_left_side(heights);
    for(auto it=dist_next_smaller_left.begin();it!=dist_next_smaller_left.end();it++) {
        cout << *it << " ";
    }
    cout<<"\n";

    vector<int> dist_next_smaller_right = next_smaller_right_side(heights);
    for(auto it=dist_next_smaller_right.begin();it!=dist_next_smaller_right.end();it++) {
        cout << *it << " ";
    }
    cout<<"\n";

    int max_area=0;
    for(int i=0;i<n;i++) {
        int width=dist_next_smaller_left[i]+dist_next_smaller_right[i]-1;
        int height=heights[i];
        max_area=max(max_area, height*width);
    }

    cout << max_area;

    cout<<endl;
    return 0;
}
