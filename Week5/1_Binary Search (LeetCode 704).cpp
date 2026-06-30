#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mid=(l+r)/2;
        while(1){
            if (nums[mid]==target) return mid;
            if(l>=r) return -1;
            if (target>nums[mid]) {
                l=mid+1;
                mid=(l+r)/2;
            }
            else{
                r=mid-1;
                mid=(l+r)/2;
            }
        }
    }
};