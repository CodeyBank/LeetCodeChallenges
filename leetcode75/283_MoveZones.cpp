/**
 * @file 283_MoveZones.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-29
 * 
 Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include <vector>
#include <stdio.h>

using namespace std;

void print_vector(vector<int> vec){
        for (auto &v: vec){
        cout<<v<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // using two pointers
        int i=0, j =0;
        int n = nums.size();

        while(i<n){
            if(nums[i] ==0){
                // find the next non-zero value
                j=i;
                while(j<n && nums[j]==0){
                    j++;
                }
                 
                if(j<n){
                    swap(nums[j], nums[i]);
                }
            }
            i++;
        } 
    }
};

int main()
{
    vector<int> arr{0,1,0,3,12};
    Solution s;
    s.moveZeroes(arr);

    for (auto &v: arr){
        cout<<v<<" ";
    }
 
    return 0;
}