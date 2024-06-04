// 205. Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"
// Output: true

// Example 2:

// Input: s = "foo", t = "bar"
// Output: false

// Example 3:

// Input: s = "paper", t = "title"
// Output: true


/*
replacement character doesnt matter - map it to target character in s2. next occurance of a character must have the same mapped character
OR
----> each character in s1 must be changed to corresponding character in s2. verify by tracking the character mappings

map each character in s1 to corresponding character in s2.
when character is seen again, check if it was mapped to the same character
keep track of characters in s2 if it was already mapped
*/

bool IsIsomorphic(std::string string1, std::string string2)
{
    map<char, char> mappings;
    // handle not assigning same char to multiple different chars in str1
    // ex: "badc" , "baba" expected: false. why? b is mapped to b. b cannot be mapped to d again
    map<char, char> taken; 
    if (string1.length() != string2.length())
        return false;

    for(int i = 0; i < string1.length(); i++){
        if(mappings.find(string1[i]) != mappings.end()){
            if(mappings[string1[i]] != string2[i])
                return false;
        } else if(taken.find(string2[i]) != taken.end())
            return false;
        mappings[string1[i]] = string2[i];
        taken[string2[i]] = string1[i];
    }
    return true;
}
