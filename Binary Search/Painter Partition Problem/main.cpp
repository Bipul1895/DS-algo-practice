#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Very similar to page allocation problem
 */

bool is_valid(int time_req[], int n, int max_time, int painters) {
    int num_painters=1;
    int time=0;
    for(int i=0;i<n;i++) {
        if(time + time_req[i] > max_time) {
            num_painters++;
            time=time_req[i];
        } else {
            time+=time_req[i];
        }

        if(num_painters > painters) return false;
    }
    return true;
}

int painter_partition(int time_req[], int n, int painters) {
    int max_time=0, min_time=0;
    for(int i=0;i<n;i++) {
        max_time+=time_req[i];
        min_time=max(min_time, time_req[i]);
    }

    int low=min_time, high=max_time;
    int optimum_time_allocate=-1;
    while(low<=high) {
        int mid=low + (high-low)/2;
        if(is_valid(time_req,n,mid,painters)) {
            optimum_time_allocate=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    return optimum_time_allocate;
}

int main()
{
    int n=4; //number of boards to be painted
    int arr[n] = {10,20,30,40}; //time taken corresponding to each board
    int painters=2;

    cout << painter_partition(arr,n,painters) << "\n";


    cout<<endl;
    return 0;
}
