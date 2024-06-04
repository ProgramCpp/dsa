int CountPalindromicSubstrings(const std::string& s){
    int c = 0;

    // odd length palindromes
    for(int i = 0; i <= s.length() - 1; i ++) {
        for(int j = i, k = i; j >= 0 && k <= s.length() - 1; j--, k++){
            if (s[j]==s[k])
                c++;
            else
                break;
        }
    }

    // even length palindromes
    for(int i = 0; i <= s.length() - 1; i ++) {
        for(int j = i, k = i + 1; j >= 0 && k <= s.length() - 1; j--, k++){
            if (s[j]==s[k])
                c++;
            else
                break;
        }
    }

    return c;
}