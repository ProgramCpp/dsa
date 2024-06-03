// 5. Longest Palindromic Substring

/*
O(n^3): find combinations of substrings => n^2. for each combination check if palidrome

=> 
O(n ^2): find combinations of substrings => n^2. check if palidrome in O(1) by checking if the substring is already a palindrome

solution:
all single characters are palindrome
iterate over all characters, move in either directions until the substring is a palindrome.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n == 0)
            return "";

        if(n == 1)
            return s;

        // no need. you are contiguously iterating
        //vector<vector<bool>> isPalindrome(s.length(), vector<bool>(n, false));
        int max = 1;
        int start = 0, end = 0;

        // for(int i = 0; i < n; i++){
        //     isPalindrome[i][i] = true;
        // }

        
        for(int i = 0; i < n; i ++){
            int len = 0;
            // even length palindrome
            for(int j = i + 1, k = i; j < n && k >= 0; j ++, k--){
                if(s[k] == s[j] ){
                    len+= 2;
                    if (max < len){
                        max = len;
                        start = k;
                        end = j;
                    }
                    // isPalindrome[k][j] = true;
                }
                // else if(s[k] == s[j] && isPalindrome[k + 1][j - 1]){
                //     len+= 2;
                //     isPalindrome[k][j] = true;
                // }
                else
                    break;
            }

            len = 1;
            // odd length palindrome
            for(int j = i + 1, k = i - 1; j < n && k >= 0; j ++, k--){
                if(s[k] == s[j]){
                    len+= 2;
                    if (max < len){
                        max = len;
                        start = k ;
                        end = j;
                    }
                    // isPalindrome[k][j] = true;
                }
                // else if(s[k] == s[j] && isPalindrome[k + 1][j - 1]){
                //     len++;
                //     isPalindrome[k][j] = true;
                // } 
                else{
                    break;
                }
            }
        }

        return s.substr(start, end - start + 1);

    }
};


