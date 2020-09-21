#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerLeft(vector<int>& heights) {
    int sz=heights.size();
    vector<int> dist_next_smaller_left(sz);
    stack<int> stk;
    for(int i=sz-1;i>=0;i--) {
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

vector<int> nextSmallerRight(vector<int>& heights) {
    int sz=heights.size();
    vector<int> dist_next_smaller_right(sz);
    stack<int> stk;
    for(int i=0;i<sz;i++) {
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
        dist_next_smaller_right[idx]=sz-idx;
    }
    return dist_next_smaller_right;
}

int largestHistogramArea(vector<int>& heights) {
    vector<int> dist_next_smaller_left=nextSmallerLeft(heights);
    vector<int> dist_next_smaller_right=nextSmallerRight(heights);
    int max_area=0;
    for(int i=0;i<heights.size();i++) {
        int height=heights[i];
        int width=dist_next_smaller_left[i]+dist_next_smaller_right[i]-1;
        max_area=max(max_area, height*width);
    }
    return max_area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int n=matrix.size(),m=matrix[0].size();
    vector<int> heights(m,0);

    int max_area=0;

    for(int i=0;i<n;i++) {
        if(i==0) {
            for(int j=0;j<m;j++) {
                heights[j]=matrix[i][j]-'0';
            }
        }
        else {
            for(int j=0;j<m;j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j]+1:0;
            }
        }
        max_area=max(max_area, largestHistogramArea(heights));
    }
    return max_area;
}


int main()
{
    vector<vector<char>> matrix {{'1','0','1','1','1'},{'1','1','1','1','0'}};
    cout << maximalRectangle(matrix) << "\n";

    vector<int> v{1,0,1,1,1};
    vector<int> v1=nextSmallerLeft(v);
    vector<int> v2=nextSmallerRight(v);

    for(int i:v1) cout << i << " ";
    cout<<"\n";

    for(int i:v2) cout << i << " ";
    cout<<"\n";

    cout << largestHistogramArea(v1) << "\n";

    cout<<endl;
    return 0;
}
