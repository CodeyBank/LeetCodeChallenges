/**
 * @file 11_ContainerWithMostWater.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // use sliding window approach

        int i = 0, j = 0;
        int n = height.size();
        int area = INT32_MIN;
        for (i = 1; i < n; ++i)
        {
            int h = min(height[i], height[j]);
            
            int w = i - j;
            cout<<"height: "<<h<<" width: "<<w<<endl;
            
            if(h*w < area){
                
            }

        }
        return area;
    }
};

int main()
{

    Solution s;
    vector<int> height {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height);
    return 0;
}
