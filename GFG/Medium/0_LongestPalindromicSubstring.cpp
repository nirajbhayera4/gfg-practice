/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  
    string getLongestPal(string &s) {
        // code here
        int n=s.size();
        int start=0, maxlen=1;
        for(int i=0;i<n;i++){
            // odd length ke liye 
            expandaroundcenter(s, i, i, start,maxlen);
            
            // even length ke liye 
            expandaroundcenter(s, i , i+1, start, maxlen);
            
        }
        return s.substr(start, maxlen);
    }
    private : void expandaroundcenter(const string &s, int l ,int r, int &start, int &maxlen){
        int n=s.size();
        
        while(l >=0 && r< n && s[l]==s[r]){
            l--;
            r++;
            
        }
        int len=r -l -1;
        
        if(len > maxlen){
            maxlen=len;
            start=l+1;
        }
    }
};
