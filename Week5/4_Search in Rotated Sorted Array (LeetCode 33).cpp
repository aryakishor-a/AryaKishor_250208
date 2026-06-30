#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bisearch(vector<int>& nums, int target, int i, int j) {
        int l=i, r=j;
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
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid=(l+r)/2;
        if(nums.size()==1 || nums.size()==2){
            if(target==nums[l]||target==nums[r])return (nums[l]==target?l:r);
            else return -1;
        }
        if(nums.size()==3){
            if (target==nums[0])return 0;
            if (target==nums[1])return 1;
            if (target==nums[2])return 2;
            return -1;
        }
        while(1){
            if ((mid==0&&nums[mid]<=nums[mid+1])||(mid==nums.size()-1 && nums[mid]<=nums[mid-1])||nums[mid]<=nums[mid+1]&&nums[mid]<=nums[mid-1] ) break;
            if (nums[l]>=nums[r]){
                if(nums[mid]>=nums[r]){
                    l=mid+1;
                    mid=(l+r)/2;
                }
                else{
                    r=mid-1;
                    mid=(l+r)/2;
                }
            }
            else if(nums[l]<=nums[r]){
                mid=l;
                break;
            }
        }
        if(target<=nums[nums.size()-1])return bisearch(nums,target,mid,nums.size()-1);
        else if(target>=nums[0])
            return bisearch(nums,target,0,mid);
        return -1;
    }
};