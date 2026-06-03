#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.size()!=t.size()) return false;
       sort(&s[0], &s[s.size()]);
       sort(&t[0], &t[t.size()]);
       if(s==t) return true;
       else return false; 
    }
};