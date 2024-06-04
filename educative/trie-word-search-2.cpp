#include <iostream>
#include <vector>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isString;

    TrieNode() {
        isString = false;
    }
};








#include "TrieNode.cpp"

enum wordType{
    NOT_FOUND,
    PREFIX,
    WORD
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(std::string stringToInsert) {
        TrieNode* node = root;
        for (char c : stringToInsert) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isString = true;
    }

    void removeCharacters(std::string stringToDelete) {
        TrieNode* node = root;
        std::vector<TrieNode*> childList;

        for (char c : stringToDelete) {
            childList.push_back(node);
            node = node->children[c];
        }

        for (int i = childList.size() - 1; i >= 0; i--) {
            TrieNode* parent = childList[i];
            char childChar = stringToDelete[i];
            TrieNode* target = parent->children[childChar];

            if (!target->children.empty()) {
                return;
            }
            parent->children.erase(childChar);
        }
    }

    // Function to search a string from the trie
    bool search(std::string stringToSearch) {
        TrieNode* node = root;
        for (char c : stringToSearch) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isString;
    }

    // Function to search prefix of strings
    bool startsWith(std::string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    wordType searchStr(string prefix){
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return NOT_FOUND;
            }
            node = node->children[c];
        }
        if (node -> isString)
            return WORD;
        return PREFIX;
    }
};








// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include "Trie.cpp"
#include <set>

bool isValid(vector<vector<char>>& grid, int i, int j){
    return i >= 0 && i < grid.size() &&
        j >= 0 && j < grid[0].size();
}

// handle deduplication of anagrams
void FindStrings (
    vector<vector<char>>& grid, 
    int i, int j,
    vector<vector<bool>>& visited,
    Trie &words,
    string match,
    set<string>& result) {
    if(!isValid(grid, i, j))
        return;
    if(visited[i][j])
        return;
    auto isFound = words.searchStr(match + grid[i][j]);
    //cout<< match + grid[i][j] << " is " << isFound << endl;
    if(isFound == WORD){
        result.insert(match + grid[i][j]);
        // do not return. some words might be prefixes of other
    }else if(isFound == NOT_FOUND){
        return;
    }
    // PREFIX found
    visited[i][j] = true;
    FindStrings(grid, i - 1, j, visited, words, match + grid[i][j], result);
    FindStrings(grid, i + 1, j, visited, words, match + grid[i][j], result);
    FindStrings(grid, i, j - 1, visited, words, match + grid[i][j], result);
    FindStrings(grid, i, j + 1, visited, words, match + grid[i][j], result);

    visited[i][j] = false;
}

vector<string> FindStrings (
    vector<vector<char>>& grid, 
    vector<string> words) 
{
    Trie trieWords;

    for(auto i = words.begin(); i != words.end(); i++)
        trieWords.insert(*i);
        
    set<string> result;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for(int i = 0; i< grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            FindStrings(grid, i, j, visited, trieWords, "", result);
        }
    }
    
    vector<string> resultVec;
    for(auto i : result){
        resultVec.push_back(i);
    }

    return resultVec;
}

