#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool valid(string part) {
        if (part.size()>1 && part[0] =='0') return false;
        if (part.size()>3) return false;

        int num = stoi(part);
        return num>=0&& num<=255;
    }

    void solve(int index, string& s, vector<string>& curr, vector<string>& ans) {
        if (curr.size()==4) {
            if (index==s.size()) {
                string ip=curr[0]+"."+curr[1]+ "."+curr[2]+"."+curr[3];
                ans.push_back(ip);
            }
            return;
        }

        for (int len=1; len<=3; len++) {
            if (index+len>s.size()) break;

            string part =s.substr(index,len);

            if (valid(part)) {
                curr.push_back(part);
                solve(index+len,s,curr,ans);
                curr.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        vector<string>curr;
        solve(0,s,curr,ans);
        return ans;
    }
};