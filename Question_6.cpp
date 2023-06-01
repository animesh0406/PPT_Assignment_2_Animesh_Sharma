/*
Question 6
Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise,
return -1.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

Explanation: 9 exists in nums and its index is 4

*/
# include<bits/stdc++.h>
using namespace std;
int binary_search(int *a,int si, int ei,int num){
    int mid =(si+ei)/2;
    if(ei<si){
        return -1;
    }
    if(a[mid]==num){
        return mid;
    }
    else if(a[mid]>num){
        return binary_search(a,si,mid-1,num);
    }
    else if(a[mid]<num){
        return binary_search(a,mid+1,ei,num);
    }
    return -1;
}
int main(){
    int a[]={-1,0,3,5,9,12};
    cout<<binary_search(a,0,5,12);
}