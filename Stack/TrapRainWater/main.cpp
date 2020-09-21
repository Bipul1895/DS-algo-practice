#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int enclosedArea(int l, int r, vector<int>& heights) {
    int h=min(heights[l],heights[r]);
    int area=0;
    for(int i=l+1;i<r;i++) {
        area+=h-heights[i];
    }
    return area;
}

int trap(vector<int>& heights) {
    int sz=heights.size();
    int left[sz],right[sz];
    left[0]=heights[0];
    for(int i=1;i<sz;i++) {
        left[i]=max(left[i-1], heights[i]);
    }

    right[sz-1]=heights[sz-1];
    for(int i=sz-2;i>=0;i--) {
        right[i]=max(right[i+1], heights[i]);
    }

    int trapped_area=0;
    for(int i=1;i<sz-1;i++) {
        int area=min(left[i-1],right[i+1]) - heights[i];
        if(area>0) trapped_area+=area;
    }
    return trapped_area;
}

int main()
{
    vector<int> heights {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(heights);

    cout<<endl;
    return 0;
}
