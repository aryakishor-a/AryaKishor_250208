#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        long long a=0;
        long long b=1;
        if(n==0)return 0;
        int k=n-1;
        while(k--){
            long long temp=b;
            b=a+b;a=temp;
        }
        return b;
    }
};