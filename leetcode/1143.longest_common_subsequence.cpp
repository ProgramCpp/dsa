/* 1143. Longest Common Subsequence
brute force: find combination of strings from str 1 and compare with every combination of strings in str2.
=> O(m ^ m * n ^ n)// for each char selection, u can pick every other char

process the strings from the 1st char. when theres a match, theres no reason to not include it in the subsequence. repeat for every char. if theres a mismatch, the current char in either string is not part of the sub sequence. try both possibilities of including the char from each string.
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> lcs(text1.size(), vector<int>(text2.size(), 0));

        // first column
        for (int i = 0; i < text1.size(); i++)
            lcs[i][0] = (text1[i] == text2[0] || (i > 0 && lcs[i - 1][0] == 1)) ? 1 : 0;

        // first row
        for (int j = 0; j < text2.size(); j++)
            lcs[0][j] = (text1[0] == text2[j] || (j > 0 && lcs[0][j - 1] == 1)) ? 1 : 0;

        for (int i = 1; i < text1.size(); i++)
        {
            for (int j = 1; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        return lcs[text1.size() - 1][text2.size() - 1];
    }
};