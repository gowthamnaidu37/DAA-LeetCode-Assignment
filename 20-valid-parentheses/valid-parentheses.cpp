#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Stack to store opening brackets
        stack<char> st;
        
        // Mapping of closing brackets to their corresponding opening brackets
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        // Traverse the string
        for (char ch : s) {
            // If it's a closing bracket
            if (bracketMap.count(ch)) {
                // Check the top of the stack (or use a dummy value if stack is empty)
                char top = st.empty() ? '#' : st.top();
                
                // If it matches the corresponding opening bracket, pop the stack
                if (top == bracketMap[ch]) {
                    st.pop();
                } else {
                    return false; // Invalid if no match
                }
            } else {
                // Push opening brackets onto the stack
                st.push(ch);
            }
        }

        // If the stack is empty, the string is valid
        return st.empty();
    }
};
