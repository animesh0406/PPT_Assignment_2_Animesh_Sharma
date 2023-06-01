/*
 Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

**Example 1:**
Input: nums = [1,4,3,2]
Output: 4

**Explanation:** All possible pairings (ignoring the ordering of elements) are:

1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4
*/
#include<bits/stdc++.h>
using   namespace std;
int arrayPairsum(vector<int>& a){
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i=0; i<a.size();i+=2){
        sum+=a[i];
    }
    return sum;

} 
int main(){
    vector<int> v={2,4,7,3,6,8,2,54,5};
    cout<<"The given array is"<<endl;
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"The maximum value from the pair sum is "<<arrayPairsum(v)<<endl;
    return 0;
}