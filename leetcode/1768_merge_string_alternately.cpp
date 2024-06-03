// 1768. Merge Strings Alternately


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output = "";
        for(int i = 0, j = 0; i < word1.length() || j < word2.length();){
            if(i < word1.length()){
                output += word1[i];
                i++;
            }
            if(j < word2.length()){
                output += word2[j];
                j++;
            }
        }
        return output;
    }
};