/* 647. Palindromic Substrings
intuition: brute force => O(n^3)
DP: O(n^2)
each character is a palindrome. start with individual characters to find palindrome and then UF/ track start and end of every palindrome
i.e, how to avoid overlapping palindromes? should you?
ex:  abcdcbadabc
2 palindromes, abcdcba & cbadabc, with cba overlapping
when checking palindrome, keep count, no need for UF.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> palin(n, vector<bool>(n, false));

        int palinCount = 0;

        for (int i = 0; i < n ;  i++){
            palin[i][i] = true;
            palinCount++;
        }

        for (int i = 0; i < n - 1 ;  i++){
            if(s[i] == s[i +1]){
                palin[i][i + 1] = true;
                palinCount++;
            }
        }


        for(int i = 3; i <= n; i ++){ // length of the palindrome
            for(int j = 0; j <= n - i; j++){
                int start = j;
                int end = j + i - 1;
                if(s[start] == s[end] && palin[start + 1][end - 1]){
                    palin[start][end] = true;
                    palinCount++;
                }
            }
        }

        return palinCount;
    }
};