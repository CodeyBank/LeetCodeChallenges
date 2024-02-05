/**
 * @file 238_ProductOfArrayExceptSelf.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 1;
        ans[0] = 1;
        for(int i = 0; i < n; ++i){
            cout<<"Left: "<<left<<endl;
            ans[i] = left;
             cout<<"ans[i]: "<<ans[i]<<endl;
            left *= nums[i];
        }
        int right = 1;
        for(int i = n - 1; i>=0; --i){
            cout<<"right: "<<right<<endl;
            ans[i] *= right;
            cout<<"ans[i]: "<<ans[i]<<endl;
            right *= nums[i];
        }
        return ans;

    }
};


int main()
{
    Solution s;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> result = s.productExceptSelf(nums);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}