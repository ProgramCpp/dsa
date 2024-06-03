// 20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> processor;

        for(int i = 0; i < s.length(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                processor.push(s[i]);
            } else {
                // closing bracket. but no opening brackets in stack
                if(processor.size() == 0)
                    return false;
                char c = processor.top();
                processor.pop();
                if(s[i] == ')' && c != '('){
                    return false;
                }
                if(s[i] == '}' && c != '{'){
                    return false;
                }
                if(s[i] == ']' && c != '['){
                    return false;
                }
            }
        }

        // opening brackets still left
        if(processor.size() != 0)
            return false;
        
        return true;
    }
};