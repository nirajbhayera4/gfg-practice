/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1
 * Platform     : GFG
 * Difficulty   : Basic
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int t[32];
  
  int solve(int n){
      if(n<=1)return n;
      if(t[n]!=-1){
          return t[n];
      }
      t[n]=solve(n-1) + solve(n-2);
      return t[n];
  }
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        // code here
        memset(t, -1, sizeof(t));
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            ans.push_back(solve(i));
            
        }
        return ans;
    }
};
