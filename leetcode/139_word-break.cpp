/*139. Word Break
intuition: optimize word dict lookup by building a ordered map whose lookup time is log n
split the sentence (assuming sent is separated by spaces!!!) and lookup dict 
=> dictionary lookup O(log n * k * l) . n, no of dict words; k, len of dict words; l, len of sentence/ no of words in a sent
NOTE: space separated seq of dict words. not space separated words in a sent.
ex: [bee, bees, stings], s = "beestings"
both bee and bees match dict, but spitting into bees + tings doesnt form a valid sentence
brute force: every substring must be lookedup the dict to find a valid sent
=> O(n ^ n), number of words/ possibilities in the sent => length of the sentence
so, starting from 0th index, split sentence into words of different lengths, and recursively solve for remaining length of the sentence.
parts of the sentences will be repeatedly solved, which can be cached
=> O(n ^ 2) // every combination of start and end is solved for only once
dict lookup can be done with hash map or trie
*/
class Solution {
public:
    bool wb(string s, int start, map<string, bool> &wd, vector<int> &sent){
        if(start == s.size())
            return 0;

        // **whole word found**
        if(wd[s.substr(start)]){
            return true;
        }

        // already computed
        if(sent[start] != -1)
            return sent[start] == 1;

        for(int i = 1; i < s.size() - start; i++){
            if(wd[s.substr(start, i)] && wb(s, start + i, wd, sent)){
                sent[start] = 1;
                return true; // the sentence starting from start to the rest of the sentence form a valid sent
            }
        }
        
        // if an index cannot be formed into a sentence, it is repeatedly computed. do not use bool type
        sent[start] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> wd;

        for(auto i : wordDict){
            wd[i] = true;
        }

        // no part of the sent can be formed with dict, to begin with
        // gives if the sentence from ith index to the end of string can be formed by dict
        // -1, not computed, 1, valid sent, 0, invalid sent
        vector<int> sent(s.size(), -1);

        return wb(s, 0, wd, sent);
    }
};