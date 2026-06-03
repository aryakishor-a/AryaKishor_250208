#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int size=nums.size();
        int cnt=0;
        for(int i=0;i<size;i++){
            int j=0;
            int temp=nums[i];
            while(temp>0){
                temp=temp/10;
                j++;
            }
            if(j%2==0) cnt++;
        }
        return cnt;
    }
};