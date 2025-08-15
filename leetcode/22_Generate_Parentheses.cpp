// 22. Generate Parentheses

/*
start with one paranthesis and keep adding more paranthesis in different order. at any index, you can add an opening paren or closing paren if there was an opening paren.
keep count of number of open paren left to decide to add a closing paren
no need for dp. you are not calling the same funtion resursively multiple times

n = 4; "(())(())" is missing - ( s ): s can be incomplete and can be made complete with the last pair of parenthesis

solution:
string length  = 2 * n

    The idea is to add ')' only after valid '('
    We use two integer variables left & right to see how many '(' & ')' are in the current string
    If left < n then we can add '(' to the current string AND
    If right < left then we can add ')' to the current string

at a given index, there can be only either '(' or ')'
note, at a given index, you can add '(' or ')'. add both in 2 iterations to get all combinations if the constraints are met.
   '(' if not all n parenthesis are used. ')' if there are enough matching '(' parenthesis
*/

class Solution {
public:
    void generate(int n, int left, int right, string paren, vector<string> &result){
        if(paren.length() == 2 * n){
            result.push_back(paren);
            return;
        }

        if(left < n ){
            generate(n, left + 1, right, paren + '(', result);
        }

        // note, no return above. ')' is added irrespective of '(' was added. 
        // try adding both parenthesis to get all combinations

        // left is less than n. hence right is less than n
        if(right < left){
            generate(n, left, right + 1, paren + ')', result);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int left = 0, right = 0;
        
        generate(n, left, right, "", result);
        return result;
    }
};