#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(&nums[0], &nums[n]);
        if (nums[0] != 0) return 0;
        for(int i=0; i<n-1;i++){
            if (nums[i]!=nums[i+1]-1) return(nums[i]+1); 
        }
        return n;
    }
};