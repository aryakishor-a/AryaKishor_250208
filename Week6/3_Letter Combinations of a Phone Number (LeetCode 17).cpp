#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int i, string &digits, vector<string>&l, string&curr, vector<string>& ans) {
        if (i ==digits.size()) {
            ans.push_back(curr);
            return;
        }
        int digit=digits[i]-'2';

        for (int j = 0; j<l[digit].size(); j++) {
            curr.push_back(l[digit][j]);
            solve(i + 1, digits, l, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>l(8);
        vector<string> ans;
        if (digits.size() == 0) return ans;
        l[0]="abc";
        l[1]="def";
        l[2]="ghi";
        l[3]="jkl";
        l[4]="mno";
        l[5]="pqrs";
        l[6]="tuv";
        l[7]="wxyz";
        string curr = "";
        solve(0, digits, l, curr, ans);
        return ans;
    }
};