#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>number(nums.begin(), nums.end());
        if (number.size()==nums.size()) return false;
        else return true;
    }
};