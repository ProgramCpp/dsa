int Calculator(string expression) {
    int number = 0;
    int sign = 1;
    int result = 0;
    stack<int> partialResults;
    stack<int> partialSign;
    // traverse past the length. evaluate the last number
    for(int i = 0; i <= expression.length(); i++){
        if (i == expression.length() && expression[i-1] != ')'){
            result += (sign * number);
        } else if(expression[i] >= '0' && expression[i] <= '9'){
            number = number * 10 + expression[i] - '0';
        } else if (expression[i] == '+' || expression[i] == '-'){
            result += (sign * number);
            sign = expression[i] == '+' ? 1 : -1;
            number = 0;
        } else if (expression[i] == '('){
            partialResults.push(result);
            partialSign.push(sign);
            result = 0;
            sign = 1;
        } else if (expression[i] == ')'){ 
            result += (sign * number);
            number = 0;
            number = partialResults.top();
            partialResults.pop();
            sign = partialSign.top();
            partialSign.pop();
            result = number + (sign * result); // saved sign is for the current result and add it to the result fo far - number from stack
            sign = 1; // not required. nect chartacter will be a sign
            number = 0;
        }
    }
    return result;
}