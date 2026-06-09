#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot=0;
        int n= nums.size();
        int lsum=0;
        int rsum=0;
        for(int i=1; i<n; i++) rsum+=nums[i];
        int i=1;
        for (; i<n; i++){
            if (lsum==rsum) break;
            else{
                lsum+=nums[i-1];
                rsum-=nums[i];
            }
        }
        if (lsum==rsum) return i-1;
        else return -1;
    }
};