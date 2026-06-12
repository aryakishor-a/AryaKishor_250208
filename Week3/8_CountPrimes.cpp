#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
            vector<bool> is_prime(n, true);
            is_prime[0] = is_prime[1] = false;
            for (int i = 2; i < n; i++) {
                if (is_prime[i] && (long long)i * i <= n) {
                    for (int j = i * i; j < n; j += i)
                        is_prime[j] = false;
            }
        }
        int c=0;
        for(int i=0; i<n; i++){
            c+= (is_prime[i]);
        }
        return c;
    }
};