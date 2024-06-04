int LongestPalindrome(std::string s)
{   
    map<char, int> count;

    for(int i = 0; i < s.length(); i++){
        count[s[i]]++;
    }

    int len = 0;
    int max = 0;

   
    for(auto i = count.begin(); i != count.end(); i++){
        if(i -> second % 2 == 0){
            len += i-> second;
        }
        // pick even numbers of characters(excluding one occurence in odd count) from all odd counts except for the max odd count
        // pick all characters of max odd count
        // ex: d: 3, f:5. palindrome can have 2 count of 'd' and 5 count of 'f'
        // 1. max has an odd count, which is no more max. add it to length
        // 2. max is still not initialized. this could be the max odd. init max, to add later
        // 3. found an odd, but its not max. add it to len
        else if(max == 0){ // first check for max is zero before other cases    
            max = i -> second;
        } else if(i->second > max){
            len += max - 1;
            max = i -> second;
        }
        else
            len += i -> second - 1;
    }

    len += max;

    return len;
}
