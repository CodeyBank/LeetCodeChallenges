/**
 * @file 443_StringCompression.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * 
 * Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, 
be stored in the input character array chars. Note that group lengths 
that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 * @version 0.1
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include<iostream>
#include <vector>
#include <string>

using namespace std;

// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         string ret;
//         int count=0;

//         int i=chars.size();

//         while(i>=0){
//             // add to ret
//             ret+=chars[i];
//             count =1;
//             while(chars[i] == chars[--i]){
//                 count++;
//             }
//             if(count>1) ret+=to_string(count);
            
//         }
//         // chars.clear();
//         // for(int i=ret.size(); i>=0; i--){
//         //     chars.push_back(ret[i]);
//         // }
//         for(auto v: ret){
//             cout<<v;
//         }
//         return chars.size();
//     }
// };


class Solution {
public:
    int compress(vector<char>& chars) {
        string ret;
        int count=0;
        int i=0,j=0; // two pointers to run through the array
        int n = chars.size();
        
        if (n <2){
            return chars.size();
        }

        while(i<n){
            // add to ret
            ret+=chars[i];
            count =1;
            j = i+1; // j should always start one character after the index of the current character
            while(j<n && chars[i] == chars[j]){
                j++;
            }
            count = j-i; // we will only append the number of repitions if count >1
            if(count>1) ret+=to_string(count);
            i = j;
        }
        chars.clear();
        for(auto v: ret){
            chars.push_back(v);
        }
        return chars.size();
    }
};

int main()
{
    vector<char> chars {'a', 'a'};
    Solution s;
    cout<<s.compress(chars)<<endl;

    for(auto ch :chars){
        cout<<ch;
    }

    
    return 0;
}