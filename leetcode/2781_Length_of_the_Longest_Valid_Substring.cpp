// 2781. Length of the Longest Valid Substring
/*
there are upto 10^5 forbidden words. at every position, you have to search through all of them. all you need to know is if the string at index i is present in forbidden list.you can optimize the search using trie - you will lookup all the words at once!
- build trie
- at every index, lookup forbidden words and track max valid substring
O(n * m). n is length of word. m is max length of forbidden words

in this case, you are matching the whole forbidden word. you could even use BST.
hash the word to be checked and see if the hash is present in a BST - build BST with hashes of forbidden words
*/


// TRIE: match a string with any of the strings in a set

// NOT accepted, some edge case in calculating the length correctly!
// Wrong Answer
// 450 / 763 testcases passed


class TrieNode {
    TrieNode *children[26] = {NULL};
    bool isEndOfWord = false;
    public: // not public by default;
    void insert(string w, int i){
        // cout << "insert " << w.substr(i, w.length()-i) << endl;
        if(i == w.length()){ // not length - 1 because root node cannot not have any character! 
            isEndOfWord = true;
            return;
        }
        int c = w[i] - 97;
        if(!children[c])
            children[c] = new TrieNode();
        children[c]->insert(w, i+1);
    }
   
    int find(string w, int i){
        // OPTIMIZED: if w has a forbidden word prefixed, return the index of w at which forbidden word matches
        if(isEndOfWord){
            return i;
        }

        if(i == w.length())
            return -1; // not found

        int c = w[i] - 97;
        if(!children[c])
            return -1; // not found

        return children[c]->find(w, i + 1);
    }
};


class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        TrieNode *trie = new TrieNode();
        for(auto i : forbidden){
            trie->insert(i, 0);
        }

        int maxSubstring = 0;
        int curMaxSubstring = 0;
        for(int i = 0; i < word.length(); i++) {
                // if not for trie, you would have searched through all forbidden words!
                string sstr = word.substr(i, word.length()-i);
                int found = trie->find(sstr, 0);
                if (found == -1 && i == word.length()-1){
                    // i++;
                    maxSubstring = max(maxSubstring, i + 1 - curMaxSubstring);
                    cout << i << " " << i + 1 - curMaxSubstring << " " << maxSubstring << endl;
                }
                // else if (found == -1)
                //     i++; // find at next position
                else if (found != -1){
                    int len = i + 1 - curMaxSubstring; // order matters. find length before updating i
                    // i += found;
                    curMaxSubstring = i + 1;
                    maxSubstring = max(maxSubstring, len);
                    cout << i << " " << len << " " << maxSubstring << endl;
                }
                // cout << i << " " << found   << " " << curMaxSubstring << " " << maxSubstring << endl;
        }

        return maxSubstring;
    }
};