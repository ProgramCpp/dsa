/* 5. Longest Palindromic Substring
intuition:
substring starting from any index upto any index can be the LPS
brute force every combination on start and end indices and check palindrome
=> O(n^3). n * n combinations and n character checks
say, you know a substring is a palindrome, to check if surrounding characters make a palindrome too, you can check that in O(1) instead of O(n)
for every character, check surrounding chars until its a palindrome. handle even length palindrome by cconsidering a pair of chars to begin with
=> O(n^2)
suggestion: DP soln
to begin with, every character is a palindromic substring
in first iteration, check palindrome of length 2, with every char in the middle and cache the result. in the 2nd iteration, consider sub string of length 3 and so on by using the cached values.
a n X n 2d array is filled => O(n^2)
s[i] == s[j] && palin[i+1][j-1] == true
HINT: 2D array gives combination of every pair of start and end indices
ex: babad
   b a b a d
b  1 0 1
a    1 0
b      1 0
a        1 0
d          1
note: only upper half of the matrix is filled. the reverse is not valid
another suggested soln: reverse aand find common substring with index checks

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> palin(n, vector<int>(n, 0));

        int lps = 0;
        int a;
        // palindrome of length 1
        for(int i = 0; i < n; i++){
            palin[i][i] = 1;
            lps = 1;
            a = i;
        }

        // handle string of length < 2
        // palindrome of length 2
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                palin[i][i+1] = 1;
                lps = 2;
                a = i;
            }
        }

        //cout << n << endl;
        for(int j = 3; j <= n; j++){   // j is count of chars
            for(int i = 0; i <= n-j; i++){ // upto the last character with j characters left. i.e, the last j length substr
                int start = i;
                int end = i + j - 1; // index from 0
                //cout << start << " " << end << " " << j << endl;
                if(s[start] == s[end] && palin[start+1][end-1]){
                    palin[start][end] = true;
                    if(lps < j){
                        lps = j;
                        a = start;
                    }

                }
            }
        }

        if(lps == 0) // no lps found. handle it
            return "";

        return s.substr(a, lps);
    }
};