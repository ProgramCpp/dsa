int lcs(const std::string& str1, const std::string& str2, int i, int j, vector<vector<int>>& lcss){
    if (i >= str1.length() || j >= str2.length()){
        return 0;
    }

    if (lcss[i][j] != -1)
        return lcss[i][j];

    if (str1[i] == str2[j]){
        lcss[i][j] = 1 + lcs(str1, str2, i + 1, j+1, lcss);
    }else{
        lcss[i][j]= max(lcs(str1, str2, i, j+1, lcss), lcs(str1, str2, i + 1, j, lcss));
    }
    return lcss[i][j];
}

int LongestCommonSubsequence(const std::string& str1, const std::string& str2) {
    vector<vector<int>> lcss(str1.length(), vector<int>(str2.length(), -1));
    return lcs(str1, str2, 0 , 0, lcss);
}