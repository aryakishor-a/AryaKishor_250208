#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> arr(2);
        int i;
        for(i=0; i<nums.size(); i++){
            if (nums[i]==target) {arr[0]=i;break;}
        }
        if (i==nums.size()) return {-1,-1};
        for(i=nums.size()-1; i>=0; i--){
            if (nums[i]==target) {arr[1]=i;break;}
        }
        return arr;
    }
};