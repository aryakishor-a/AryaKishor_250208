#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s, int l, int r){
            while(l<r){
                if (s[l]!=s[r])return false;
                l++;
                r--;
            }
            return true;
        }
    void solve(int index, string&s, vector<string>&curr, vector<vector<string>>&ans) {
        if (index==s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int end= index; end<s.size(); end++) {
            if (isPalindrome(s,index,end)) {
                curr.push_back(s.substr(index, end - index + 1));
                solve(end + 1, s, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        solve(0,s,curr,ans);

        return ans;
    }
};