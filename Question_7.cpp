/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true
*/
#include<bits/stdc++.h>
using namespace std;
bool check_mono_inc(int *a,int n){
    if(n==1){
        return true;
    }
    bool inc_flag=(a[0]>=a[1])&&check_mono_inc(a+1,n-1);
    
    return inc_flag;
}
bool check_mono_dec(int *a,int n){
    if(n==1){
        return true;}
        bool dec_flag=((a[0]<=a[1])&&check_mono_dec(a+1,n-1));
        return dec_flag;
    }
bool check_mono(int *a,int n){
    return check_mono_dec(a,n)||check_mono_inc(a,n);
}


int main(){
    int a[4]={1,2,2,3};
    cout<< check_mono(a,4)<<endl;
}