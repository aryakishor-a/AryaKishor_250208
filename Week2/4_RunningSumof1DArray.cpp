#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int x=nums.size();
        vector <int> sum(x);
        sum[0]=nums[0];
        for(int i=1;i<x;i++){
            sum[i]=sum[i-1]+nums[i];
        }
        return sum;
    }
};