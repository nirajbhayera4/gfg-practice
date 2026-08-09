/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/sum-of-query-ii5310/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<int> seg;
  
  
  int n;
  // build seg tree
  void build(int i, int l, int r, int arr[]){
      if(l==r){
          seg[i]=arr[l-1]; // 1 indexed hai isliye l-1
          return ;
      }
      
       int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, arr);
        build(2 * i + 2, mid + 1, r, arr);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
  }
  
  int query(int i, int l, int r, int start, int end){
      //case 1 : out of bound
      
      if( l >end || r <start){
          return 0;
      }
      
      //case 2: completely range ke andar hoga 
      if( l>=start && r <=end){
          return seg[i];
      }
      int mid = l +(r-l)/2;
      
      //case 3 : if partially range ke andar hoga
      return query( 2 * i+ 1,l,mid,start, end  ) + query(2*i +2, mid+1, r, start , end);
      
  }
  
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        
        seg.resize(4 *n);
        
          build(0, 1, n, arr);
        vector<int> ans;
        // code here
        for(int i=0;i<q;i++){
            int start=queries[2*i];
            int end=queries[2*i +1];
            ans.push_back(query(0,1,n,start, end));
        }
        return ans;
        
    }
};
