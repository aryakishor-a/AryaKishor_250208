#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    int height(Node* root){
        if (root==nullptr) return -1;
        int lx=height(root->left);
        int rx=height(root->right);
        return max(lx,rx)+1;
    }
    
};