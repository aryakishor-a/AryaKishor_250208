#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool poss(vector <int>&nums, int i){
        if (i==0)return true;
        for(int j=i-1; j>=0; j--){
            if(i-j<=nums[j]) return poss(nums, j);
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return poss(nums, nums.size()-1);
    }
};