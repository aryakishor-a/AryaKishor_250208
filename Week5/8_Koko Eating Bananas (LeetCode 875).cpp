#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool valid(vector <int>&piles, int h, int k){
        long long sum=0;
        if (k==0) return false;
        for(int p:piles) {
            if (p%k==0)sum+=p/k;
            else sum+=(p/k)+1;
        }
        if(sum<=h)return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int x=1;
        int y=0;
        for(int k:piles)y=max(y,k);
        int z=x+(y-x)/2;;
        if(y==0)return 0;
        while(1){
            if (valid(piles,h,x)) return x;
            else{
                if (valid(piles, h, z)){
                    y=z;
                    z=x+(y-x)/2;
                }
                else {
                    x=z+1;
                    z=x+(y-x)/2;
                }
            }
        }
        return z;
    }
};