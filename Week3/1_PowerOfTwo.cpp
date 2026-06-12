#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int numberof1=0;
        
        while (n>0){
            if (n & 1) {numberof1+=1;}
            n=n>>1;
        }
        if(numberof1==1)return true;
        else return false;
    }
};