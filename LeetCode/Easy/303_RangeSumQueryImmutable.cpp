/**
 * Problem Link : https://leetcode.com/problems/range-sum-query-immutable/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
vector<int> seg;
int n;// glabally declare kr denge

// segment tree build krenge 
void build(int i, int l, int r,vector<int>&nums){
    if(l==r){
         seg[i]=nums[l];
         return ;
    }

    int mid = l+(r-l)/2;
    //build tree call marenge left and right ke liye 
    build(2*i +1,l, mid, nums);
    build(2*i +2,mid+1, r, nums);
    seg[i]=seg[2*i +1]+seg[2*i +2];
    

}
int query(int i, int l, int r,int start, int end){
    // case 1 : no overlap
    if( l>end || r < start){
        return 0;
    }
    // case2 : completely overlap
    if(l >=start && r <=end){
        return seg[i];
    }
    //case3 : partially overlap
    int mid = l+(r-l)/2;
    return query(2*i+1,l, mid,start, end) + query(2*i+2,mid +1, r, start, end);
}
    NumArray(vector<int>& nums) {
        // contructor hai 
         n=nums.size();
        // segment tree ke size ka array bna denge
        seg.resize(4*n);
        if(n >0){
            build(0,0,n-1,nums);
        }
        
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left, right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
