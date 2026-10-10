#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        std::unordered_map<char, char> mapping = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char c : s) {
            // If the character is a closing bracket
            if (mapping.find(c) != mapping.end()) {
                // Get the top element of the stack if not empty, otherwise use a dummy character
                char topElement = st.empty() ? '#' : st.top();
                if (!st.empty()) {
                    st.pop();
                }
                
                // Check if the popped opening bracket matches the expected one
                if (topElement != mapping[c]) {
                    return false;
                }
            } 
            else {
                // If it's an opening bracket, push it onto the stack
                st.push(c);
            }
        }
        
        // If the stack is empty, all brackets were matched correctly
        return st.empty();
    }
};