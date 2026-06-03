#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        long long rev=0;
        long long original=x;
        if(x<0) return false;
        while(x>0){
            rev=rev*10 + x%10;
            x=x/10;
        }
        if (original==rev) return true;
        else return false;
    }
};