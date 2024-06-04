int LongestRepeatingCharacterReplacement(const std::string& s, int k) {
    map<char, int> freq;

    char highFreq = 0;
    int maxSubSeq = 0;
    int start = 0;
    for(int end = 0 ; end < s.length(); end++, maxSubSeq++){
        freq[s[end]]++;
        if(freq[s[end]]> highFreq)
            highFreq = freq[s[end]];
        if (end - start + 1 - highFreq > k) {
            // if (end - start > maxSubSeq){
            //     maxSubSeq = end - start;
            // }
            freq[s[start]]--;
            start++;
            maxSubSeq--;
        }
    }
    
    return maxSubSeq;
}