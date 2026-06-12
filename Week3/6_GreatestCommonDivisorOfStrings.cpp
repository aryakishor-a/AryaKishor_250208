#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        int l1=str1.size(), l2=str2.size();
        int gcd;
        while(1){
            if (l2==0){gcd= l1; break;}
            int temp=l2;
            l2=l1%l2;
            l1=temp;
        }
        string s1;;
        for(int i=0; i<gcd; i++){
            s1.push_back(str1[i]);
        }
       return s1; 
    }
};