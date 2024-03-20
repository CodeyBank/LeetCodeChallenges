/**
 * @file skipnumber.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void printvec(vector<int>v){
    for(auto &val: v){
        cout<<" "<<val;
    }
    cout<<endl;
}

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> ret(n);
        int i = 0;
        prefix[0] = nums[0];
        suffix[n-1] = nums[n - 1];
        for (i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i];
            suffix[n - i - 1] = suffix[n - i] * nums[n - i - 1];

        }
        
        ret[0] = suffix[1];
        ret[n-1]=prefix[n-2];
        for (int j=1; j<n-1; j++){
            ret[j] = prefix[j-1] * suffix[j+1];
        }

        return ret;
    }
    vector<int> skipnum(vector<int>& nums){
    int n = nums.size();
    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);
    vector<int> result(n, 0);

    // Compute prefix array
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    // Compute suffix array
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + nums[i + 1];
    }
    printvec(prefix);
    // Compute result array
    for (int i = 0; i < n; ++i) {
        result[i] = prefix[i] + suffix[i];
    }
    printvec(suffix);
    return result;
    }
};




int main()
{
    Solution s;

    vector<int> test = {1,2,3,4,5};
    // auto res = s.productExceptSelf(test);
    // printvec(res);
    auto res = s.skipnum(test);
    printvec(res);
    return 0;
}