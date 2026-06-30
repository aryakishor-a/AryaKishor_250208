#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ok(vector<int>& weights, int days, int c){
        long long day=1;
        long long sum=0;
        for(int i=0 ; i<weights.size(); i++){
            if (sum+weights[i]>c){sum=0; day++;}
            sum+=weights[i];
        }
        if(day<=days)return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        for (int x : weights) l = max(l, x);
        int r=0;
        
        for(int x:weights)r+=x;
        int mid=l+(r-l)/2;
        while(1){
            if (ok(weights, days, l)) return l;
            int mid=l+(r-l)/2;
            if (ok(weights, days, mid)){
                r=mid;
                l++;
            }
            else{
                l=mid+1;
            }
        }
    }
};