/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/range-minimum-query/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<int> seg;
  int n;
  void build(int i, int l, int r, vector<int> &arr){
      if(l==r){
          seg[i]=arr[l]; // 0 indexed hai  isliye 
          return ;
      }
      
      int mid= l+ (r-l)/2;
      build(2*i+1,l,mid,arr);
       build(2*i+2,mid+1,r,arr);
       seg[i]=min(seg[2*i+1] ,seg[2*i+2]);
  }
  int query(int i, int l, int r, int start, int end){
      // case 1: out of bound
      if(l > end || r <  start){
          return INT_MAX;
          
      }
       // case 2 : completely in bound
       if(l >=start && r <=end){
           return seg[i]; 
       }
       
       //if partially range ke andar hai toh 
       // left subtree + right subtree 
       int mid=l + (r-l)/2;
       return min(query(2*i+1,l,mid,start, end), query(2*i+2, mid+1, r, start, end));
       
       
      
  }
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
         n=arr.size();
        
        seg.resize(4*n);
       if(n >0){
            build(0,0,n-1,arr);
       }
        
       vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            
                int l=queries[i][0];  // 0
                int r=queries[i][1]; //2
            
            ans[i]=query(0,0,n-1,l,r);
        }
        return ans;
        
    }
};
