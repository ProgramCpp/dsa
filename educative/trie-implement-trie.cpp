#include "TrieNode.cpp"

class TrieNode {
   public:
       std::map<char, TrieNode*> children;
       bool isWord;
 
       TrieNode(){
           this->isWord = false;
       }
};

class Trie {
    TrieNode *root;

    public:
        Trie(){
            root = new TrieNode();
        }

        // inserting string in trie
        void Insert(string word){
            TrieNode *cur = root;
            for(int i = 0; i < word.length(); i++){
                if(!cur->children[word[i]]){
                    cur->children[word[i]] = new TrieNode();
                }
                cur = cur->children[word[i]];
            }
            cur->isWord=true;
        }

        // searching for a string
        bool Search(string word){
            TrieNode *cur = root;
            for(int i = 0; i < word.length(); i++){
                if(!cur->children[word[i]])
                    return false;
                cur = cur->children[word[i]];
            }
            if(cur->isWord)
                return true;
            return false;
        }

        // searching for a prefix
        bool SearchPrefix(string prefix){
            TrieNode *cur = root;
            for(int i = 0; i < prefix.length(); i++){
                if(!cur->children[prefix[i]])
                    return false;
                cur = cur->children[prefix[i]];
            }
            return true;
        }
};
