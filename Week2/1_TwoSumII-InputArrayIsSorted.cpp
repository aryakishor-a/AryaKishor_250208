#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>arr(2);
        int n=numbers.size();
        int i=0; int j=n-1;
        while(1){
            if (numbers[i]+numbers[j]==target) {
                arr[0]=i+1;
                arr[1]=j+1;
                break;
            }
            else if (numbers[i]+numbers[j]<target) i++;
            else j--;
        }
        return arr;
    }
};