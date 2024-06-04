bool IsValid(string s) {
    // map<char,char> validParen= {
    //     {'}','{'},
    //     {']','['},
    //     {')','('},
    // };
    stack<char> allParenthesis;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            allParenthesis.push(s[i]);
        }else if (s[i] == ')' ){
            if(allParenthesis.empty())
                return false;
            if (allParenthesis.top()== '('){
                allParenthesis.pop();
            } else{
                return false;
            }
        }else if (s[i] == ']' ){
            if(allParenthesis.empty())
                return false;
            if (allParenthesis.top()== '['){
                allParenthesis.pop();
            } else{
                return false;
            }
        }else if (s[i] == '}' ){
            if(allParenthesis.empty())
                return false;
            if (allParenthesis.top()== '{'){
                allParenthesis.pop();
            } else{
                return false;
            }
        }
    }
    if(!allParenthesis.empty())
        return false;
    return true;
}