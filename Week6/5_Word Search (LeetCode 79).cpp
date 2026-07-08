#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ist(vector<vector<char>>& board, string&word, int i, int j, int index){
        if(index==word.size()-1 && board[i][j]==word[index])return true;
        if (i<0||j<0||i>=board.size()||j>=board[0].size()) return false;
        if(board[i][j]!=word[index])return false;
        char temp=board[i][j];
        board[i][j]='.';
        int maxi=board.size();
        int maxj=board[0].size();
        if (i+1<maxi && ist(board,word,i+1,j,index+1))return true;
        if(i-1>=0 && ist(board,word,i-1,j,index+1)) return true;
        if(j+1<maxj && ist(board, word, i, j+1, index+1)) return true;
        if(j-1>=0 && ist(board, word, i, j-1, index+1)) return true;
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int f=0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if (board[i][j]==word[0]){
                    if (ist(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};