#include <bits/stdc++.h>
using namespace std;

bool partitionKsubsets(vector<int>& nums, vector<int>& bucket, int idx, int target_sum) {
    //base condition
    if(idx<0) {

        for(int val:bucket) cout << val << " ";
        cout << endl;

        for(int i=0;i<bucket.size();i++) {
            if(bucket[i]!=target_sum) return false;
        }
        return true;
    }

    for(int i=0;i<bucket.size();i++) {
        if(bucket[i] + nums[idx] <= target_sum) {
            bucket[i]+=nums[idx];
            if(partitionKsubsets(nums,bucket,idx-1,target_sum)) {
                return true;
            }
            bucket[i]-=nums[idx];
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int target_sum=0;
    for(int num:nums) target_sum+=num;

    if(target_sum % k != 0) return false;

    vector<int> bucket(k,0);

    int sz=nums.size();
    return partitionKsubsets(nums,bucket,sz-1,target_sum/k);

}

int main()
{
    vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    canPartitionKSubsets(nums, 4);

    return 0;
}
