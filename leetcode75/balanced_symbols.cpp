/**
 * @file balanced_symbols.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-03-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{

public:
    bool balanced_symbols(std::string &str)
    {
        int cnt = 0;

        for (auto &s : str)
        {
            if (s == '(')
            {
                cnt++;
            }
            else if (s == ')')
            {
                cnt--;
            }
        }

        return cnt == 0;
    }

    bool balanced_parenthesis(string &str)
    {
        // first get a map of all parenthesis types
        unordered_map<char, char> mp{
            pair<char, char>('(', ')'),
            pair<char, char>('{', '}'),
            {'[', ']'},
            {'"', '"'},
            {'\'', '\''}
        };

        stack<char> st;

        for (auto &s : str)
        {

            if (mp.find(s) != mp.end())
            {
                // we have an opening bracket
                st.push(s);
                // cout<<"Pushing "<<st.top()<<endl;
                continue;
            }
            if (!st.empty() && s == mp[st.top()])
            {
                // cout<<"Popping "<<st.top()<<endl;

                st.pop();
                // cout<<"new top "<<st.top()<<endl;
            }
            else
            {
                // cout<<"got a "<<s<<endl;
                return false;
            }
        }
        return st.empty();
    }

    bool areParenthesesMatched(const string &str)
    {
        stack<char> stk;
        unordered_map<char, char> matchingParentheses = {
            {'(', ')'}, {'[', ']'}, {'{', '}'}, {'\'', '\''}, {'"', '"'}, {'`', '`'}};

        for (char ch : str)
        {
            if (matchingParentheses.count(ch))
            {
                stk.push(ch);
            }
            else if (matchingParentheses.count(stk.top()) && ch == matchingParentheses[stk.top()])
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }

        return stk.empty();
    }
};

int main()
{
    string v{"((((ajdjjak)))"};
    string bad{"{[[((()))]]})"};
    std::cout << boolalpha;
    Solution s;
    string str1 = "(()())()";
    string str2 = "(()";
    string str3 = "[(){}]";
    string str4 = "[()}";
    string str5 = "['\"";
    string str6 = "['`\"";
    string str7 = "`['`\"";

    cout << "String 1 is " << (s.balanced_parenthesis(str1) ? "matched" : "not matched") << endl;
    cout << "String 2 is " << (s.balanced_parenthesis(str2) ? "matched" : "not matched") << endl;
    cout << "String 3 is " << (s.balanced_parenthesis(str3) ? "matched" : "not matched") << endl;
    cout << "String 4 is " << (s.balanced_parenthesis(str4) ? "matched" : "not matched") << endl;
    cout << "String 5 is " << (s.balanced_parenthesis(str5) ? "matched" : "not matched") << endl;
    cout << "String 6 is " << (s.balanced_parenthesis(str6) ? "matched" : "not matched") << endl;
    cout << "String 7 is " << (s.balanced_parenthesis(str7) ? "matched" : "not matched") << endl;
    return 0;
}