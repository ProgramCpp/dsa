class TrieNode {
   public:
       std::map<char, TrieNode*> children;
       bool endOfWord = false;
};




#include "TrieNode.cpp"

class Trie {
  TrieNode * root;
  public:
    Trie() {
      this -> root = new TrieNode();
    }

  void PrintKeys(std::map < char, TrieNode * > children) {
    int count = 1;
    for (auto itr = children.begin(); itr != children.end(); ++itr) {
      if (count == children.size()) {
      } else {
      }
      count++;
    }
  }

  // inserting string in trie
  void Insert(std::string word) {
    TrieNode * curr = this -> root;
    // adding string characters in the tree
    for (auto c: word) {
      // Create a new node if char does not exist in children dictionary
      if (curr -> children.find(c) == curr -> children.end()) {
        curr -> children[c] = new TrieNode();
      }
      curr = curr -> children[c]; // update the node as we move to the next character
    }
    curr -> endOfWord = true;
  }

  // this function replaces each word in the sentence with
  // the smallest word from the dictionary
  std::string Replace(std::string word) {
    TrieNode * curr = this -> root;
    // iterate over each dictionary word along
    // with the index of that character
    int i = 0;
    for (auto c: word) {
      // if the character doesn't belong to the current node's children,
      // then return the word
      if (curr -> children.find(c) == curr -> children.end()) {
        return word;
      }

      // move to the child of the current node
      // corresponding to the current character
      curr = curr -> children[c];
      // when the flag end_of_word becomes TRUE, this means
      // we've reached the end of word in the trie. If this is the
      // case, then return this word
      if (curr -> endOfWord) {
        return word.substr(0, i + 1);
      }
      i++;
    }
    return word;
  }
};









// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include "Trie.cpp"
#include "PrependCode.cpp"

string ReplaceWords(string sentence, vector <string> dictionary) 
{
    Trie lookup;

    for(auto i = dictionary.begin(); i != dictionary.end(); i++){
        lookup.Insert(*i);
    }

    stringstream sentenceStream(sentence);
    stringstream result;
    string word;
    while(sentenceStream >> word){
        word = lookup.Replace(word);
        result << word;
        if(!sentenceStream.eof())
            result << " ";
    }

    return result.str();
}