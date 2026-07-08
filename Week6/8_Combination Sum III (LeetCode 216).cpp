#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int start, int k, int n, vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size()==k) {
            if (n==0) {
                ans.push_back(curr);
            }
            return;
        }

        for (int num=start; num<=9; num++) {
            if (num >n) break;
            curr.push_back(num);
            solve(num+1,k,n-num,curr,ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(1,k,n,curr,ans);

        return ans;
    }
};