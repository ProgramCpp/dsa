/* 127. word ladder
brute force: for every word, find the next word in the dictionary. 
parse the constructed list to skip past unnecessary transformation. repeat for other possibilities
O(n! * n)
suggested solution:
the relationship between transformations are intertwined in a specific order like a graph,
where the undirected edge connects two words that differ by a character.
start traversal from begin to end in BFS (for shortest path)

how to build the graph?
for every pair of words, check and build the edges
=> O(n^2 * l). l:length of words
a map from wild char/ placeholder character words to actual words gives all the edges connected, including itself
     hot-dot-dog
    / |   /   /|
hit   |  /   / |
      | /   /  |
     lot-log-cog
ex: for src hot, 
*it: 
h*t: hit, hot
*ot: lot, dot, hot
3 edges from hot, excluding itself
*/

struct wordCount {
    string word;
    int depth;
    wordCount(string w, int d) : word(w), depth(d){}
};

class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> wordmap;

        for(auto w : wordList){
            for(int i=0; i< w.size(); i++){
                string t = w;
                t[i] = '*';
                wordmap[t].push_back(w);
            }
        }

        // add src to graph
        for(int i=0; i< beginWord.size(); i++){
            string t = beginWord;
            t[i] = '*';
            wordmap[t].push_back(beginWord);
        }

        map<string, bool> visited;// bfs. but undirected graph
        queue<wordCount> words;
        words.push(wordCount(beginWord, 1));
        visited[beginWord] = true;

        while(!words.empty()){
            wordCount node = words.front();
            words.pop();
            if(node.word == endWord)
                return node.depth;

            for(int i = 0; i < node.word.size(); i++){
                string t = node.word;
                t[i] = '*';
                for(auto nxt :  wordmap[t]){
                    if (nxt != node.word && !visited[nxt]){
                        words.push(wordCount(nxt, node.depth+1));
                        visited[nxt] = true;
                    }
                }
            }
        }

        return 0;
    }
};