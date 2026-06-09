#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        int i=0,j=0,k=0;
        while(1){
            if (k==n2 || i==n1)break;
            if(arr1[j]==arr2[k]){
                int temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
                i++;
            }
            j++;
            if (j==n1) {j=i;k++;}

            
        }
        sort(&arr1[i], &arr1[n1]);
        return arr1;
    }
};