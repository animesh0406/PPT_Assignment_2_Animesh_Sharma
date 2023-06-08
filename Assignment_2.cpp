/*
 q1 Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

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



/*
Question 2
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3

Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.*/
#include<bits/stdc++.h>
using namespace std;
int Candies(vector<int>& candyType) {
        unordered_map<int,int> M;
        for (int i = 0; i<candyType.size(); i++)
    {
        if (M.find(candyType[i]) == M.end())
        {
            M.insert(make_pair(candyType[i], 1));
        }
 
        // Else update the frequency
        else
        {
            M[candyType[i]]++;
        }

    }
     int distinct=M.size();
     int maxi=candyType.size()/2;
     if(distinct<maxi){
        return distinct;
     }
     return maxi;
}
//Time complexity in O(n) since iterated the array only once .

int main(){
    vector<int>candyType = {1,1,2,2,3,3};
    cout<<"Maximum distinct candies that she can eat is "<<Candies(candyType);
    return 0;
}




/*
Question 3
We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5

Explanation: The longest harmonious subsequence is [3,2,2,2,3]
*/
#include<bits/stdc++.h>
using namespace std;
int harmonic(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int l = 0;
        int best = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[l]) {
                continue;
            }
            while (l < i && nums[i] - nums[l] > 1) {
                l++;
            }
            if (nums[i] - nums[l] == 1) {
                best = max(best, i - l + 1);
            }
        }
        return best;
    }
int main(){
    
    vector<int> m={1,3,2,2,5,2,3,7};
    cout<<"The required ouput is "<<harmonic(m)<<endl;
    return 0;
}




/*
Question 4
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
*/
#include<bits/stdc++.h>
using namespace std;
bool Checkflowerbed(vector<int>& flowerbed,int n){
     flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);

        for(int i=1; i<flowerbed.size()-1; i++){
           if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1]==0){
               n--;
               i++;
           }
           
           
        }
        return n <= 0;
        
    

}
// time complexity is O(n)
int main(){
   return 0; 
}




/*
Question 5
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6
*/
#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums){
    sort(nums.begin(), nums.end());
    return nums[nums.size()-1]*nums[nums.size()-2];
}
int main(){
    vector<int> n={2,4,3,6,3,8,10,34,23,9};
    cout<<"Given array is "<<endl;
    for(int i=0; i<n.size(); i++){
        cout<<n[i]<<" ";
    }
    cout<<endl<<"The maximum product is "<< maxProduct(n)<<endl;

}
//Time complexity is O(nlogn)




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




/*
Question 8
You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0

Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0
*/
#include<bits/stdc++.h>
using namespace std;
int score_of_nums(vector<int>& v ,int k){
    
int mx=*max_element(v.begin(),v.end());
        int mn=*min_element(v.begin(),v.end());

        return max(0,mx-k-mn-k);
}
int main(){
   vector<int> v={1,3,6};
   cout<<"The Array is"<<endl;
   for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
   }
   cout<<endl;
   cout<<"The score is "<<score_of_nums(v,3)<<endl;
   return 0; 
}