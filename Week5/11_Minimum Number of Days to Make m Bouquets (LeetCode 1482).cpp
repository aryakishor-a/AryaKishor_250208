#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ok(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int cnt = 0;

        for (int x : bloomDay) {
            if (x<= day) {
                cnt++;
                if (cnt== k) {
                    bouquets++;
                    cnt =0;
                }
            } 
            else {
                cnt =0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL * m * k > n) return -1;
        int l= bloomDay[0];
        int r=bloomDay[0];
        for(int x:bloomDay) {
            l=min(l,x);
            r=max(r,x);
        }
        while (l< r) {
            int mid = l + (r - l) / 2;
            if (ok(bloomDay, m, k, mid)) {
                r=mid;    
            } 
            else{
                l=mid + 1; 
            }
        }
        return l;
    }
};