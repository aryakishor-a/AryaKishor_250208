#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ok(int s,  vector<int>& p, long long success){
        int l=0;
        if (1LL*p[p.size()-1]*s<success)return 0;

        int r= p.size();
        long long mid=l+(r-l)/2;
        while(1){
            mid=l+(r-l)/2;
            if (1LL*p[l]*s>=success)break;
            if (1LL*p[mid]*s>=success){
                r=mid;
                l++;
            }
            else{
                l=mid+1;
            }
        }
        return (p.size()-l);
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector <int> ans;
        sort(potions.begin(), potions.end());
        for(int i=0; i<spells.size(); i++){
            ans.push_back(ok(spells[i],potions,success));
        }
        return ans;
    }
};