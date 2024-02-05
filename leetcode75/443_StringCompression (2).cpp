/**
 * @file 443_StringCompression.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        // loop
        int count=0;
        string compressed;
        char prev=chars[0];
        int i=0;
        if(chars.size() <= 1) return 1;
        while(i<chars.size()-1){
            compressed += chars[i];

            count = 1;
            while(chars[i] == chars[++i]){
                count++;
            }
            if(count>1) compressed += to_string(count);
        }

        cout<<compressed<<endl;
        for (int i = 0; i < compressed.length(); i++) {
            chars[i] = compressed[i];
        }
        return compressed.length();
    }
};

class Solution {
public:
    int compress(vector<char>& chars) {
        string compressed;
        int currCount = 1;
        char currChar = chars[0];

        // Iterate through the characters in the input vector
        for (int i = 1; i < chars.size(); i++) {
            // Check if the current character is the same as the previous one
            if (currChar == chars[i]) {
                currCount++;
            } else {
                // Append the current character to the compressed string
                compressed += currChar;
                // Append the count if it's greater than 1
                if (currCount > 1) {
                    compressed += to_string(currCount);
                }
                // Update the current character and reset the count
                currChar = chars[i];
                currCount = 1;
            }
        }

        // Append the last character and its count
        compressed += currChar;
        if (currCount > 1) {
            compressed += to_string(currCount);
        }

        // Copy the compressed string back to the input vector
        for (int i = 0; i < compressed.length(); i++) {
            chars[i] = compressed[i];
        }

        // Return the length of the compressed string
        return compressed.length();
    }
};

int main()
{
    Solution s;
    
    vector<char> chars {'a'};
    cout<<s.compress(chars)<<endl;

    for(auto v: chars){
        cout<<v<<" "<<endl;
    }
    return 0;
}