/**
 * Problem Link : https://leetcode.com/problems/word-search/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int n, m;
vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
bool find(vector<vector<char>>& board,int i, int j, int idx, string &word){
    if(idx==word.length())return true;// idx agar last element tak pahuch gya hai to true krdo means element mil chuka h
    if(i <0 || j<0 || j>=m || i>=n || board[i][j]=='$'){
        return false;
    }

    if(board[i][j]!=word[idx])return false; // means element ka index board of i and j ke equal nahi hai 
    char temp=board[i][j];
    board[i][j]='$';

    for(auto &dir : directions){
        int i_=i + dir[0];
        int j_=j+ dir[1];

        if(find(board, i_, j_, idx+1,word)){
            return true;
        }

    }
    board[i][j]=temp;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=word[0] && find(board,i, j, 0,word)){
                    return true;
                }
            }
        }
        return false;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
