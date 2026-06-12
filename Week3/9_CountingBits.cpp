#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n+1);
        for(int i=0; i<=n; i++){
            int k=i;
            int j=i;
            answer[i]=0;
            int pow2=2;
            while(k>0){
                answer[i]+=(i%pow2 >= pow2/2);
                k=k/2;
                pow2=pow2*2;
            }
        }
        return answer;

    }
};