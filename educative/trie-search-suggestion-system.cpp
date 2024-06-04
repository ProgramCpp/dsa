#include<algorithm>

class TrieNode {
  public:
    std::map < char, TrieNode * > children;
  std::vector < std::string > searchWords;
};

vector<vector<string>> SuggestedProducts(vector<string> products, string searchWord){
    TrieNode *root = new TrieNode();
    for(vector<string>::iterator i = products.begin(); i != products.end(); i++){
        TrieNode *cur = root;
        for(int j = 0; j < i -> length(); j++){
            if(!cur->children[(*i)[j]])
                cur->children[(*i)[j]] = new TrieNode();
            cur -> children[(*i)[j]] -> searchWords.push_back(*i);
            sort(cur -> children[(*i)[j]] -> searchWords.begin(),
            cur -> children[(*i)[j]] -> searchWords.end());
            cur = cur->children[(*i)[j]];
        }
    }

    vector<vector<string>> result(searchWord.length(), vector<string>());
    TrieNode *cur = root;
    for(int i = 0; i < searchWord.length(); i++){
        if(!cur || !cur->children[searchWord[i]])
            continue;
        for(int j = 0; j < 3 && j < cur->children[searchWord[i]]->searchWords.size();j++){
            result[i].push_back(cur->children[searchWord[i]]->searchWords[j]);
        }
        cur = cur->children[searchWord[i]];
    }

    return result;
}
