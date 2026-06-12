#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int x=0;
        for(int i=0; i<s.size();i++){
            x=x^s[i]^t[i];
        }
        x=x^t[s.size()];
        return (char)x;
    }
};