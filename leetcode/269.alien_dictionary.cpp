/*
269. alien dictionary 
the whole ordering of all characters are given. ignore the order of characters from the 2nd position after the prefix match
how to store the order of characters? think graph
valid use cases:
disjoint set: multiple solutions
multiple paths between nodes: multiple solutions

algorithm:
traverse all words and contruct a graph with the order or characters
traverse the graph to build the result
=> O(w * n) + O(n) . n: no of chars. w: no of words

how to handle disjoint graph?
ex: what if you start at the middle of the path? pick lowest indegree?
even if the visited nodes are tracked, missing chars indicate disjoint graph or path traversed from the middle.
the later must be ignored

count indegrees. concat the result of all indegree nodes. mark the part of graph already traversed
ex:
a -> b
c -> b
result: acb or cab: (a or c can be prefixed since the indegree's are 0)

todo: check the validity of the order as well. return empty string
- check for cycles : conflicting order
- check for prefix : problem constraint

failing tc: 14/24
words=["mnop","nopq","opqr","pqrs","qrst","rstu","stuv","tuvw","uvwx","vwxy","wxyz","xyz","yz","z","mnopqr","nopqrs","opqrst","pqrstu","qrstuv","rstuvw","stuvwx","tuvwxy","uvwxyz","vwxyz","wxyza","xyzab","yzabc","zabcd"]
expected ""
aactual "abcd" 
something to do with handling nodes without edges
no. cycle detection is failing for this sample
DO NOT terminate cycle checking on THIS path even if it was already traversed
then how to de-duplicate the sub paths?
how about traverse to check cycles, without updating the result

checking cycles:
- including nodes already in the result must still be traced for cycles
- a graph with no 0 indegree nodes. trace paths from all nodes to detect cycles

todo: cleanup indegree. it was being used to start traversal from the least order character. it doesnt matter if the graph is traversed from the middle. 
the whole graph will be eventually traversed as two sub-graphs.
and the whole graph must be traversed to detect cycles. in this case, there might be no node with 0 indegrees.
*/

class Solution {
public:
    // doesnt matter if node visited in current path or connected path. skip
    string trace(char c, map<char,set<char>> &charOrder, map<char, bool> &visited, map<char, bool> &seen){
        cout << "DFS for " << c << endl;
        if(seen[c]){ // if character is currently being visited in this path, cycle detected
            cout << "cycle detected:" << c;
            return "invalid"; // cycle detected
        }

        // DO NOT terminate cycle checking on this path even if this path was already traversed
        // if(visited.find(c) != visited.end())
        //     return ""; // sub path already traversed

        // leaf node. no more neighbors. the below code takes care.visited must be updated too
        // if(charOrder.find(c) == charOrder.end())
        //     return string{c};
        
        seen[c] = true;
        string res = "";
        for(auto nei : charOrder[c]){
            cout << c << " to " << nei << ".";
            string r = trace(nei, charOrder, visited, seen); 
            if (r == "invalid") {
                return r;
            }
            res += r;
        }

        if(visited.find(c) == visited.end()){
             // string res{c}; // char to string
            string cStr{c};
            res = res + cStr; // append current node to end - post order DFS, to ensure leaf node preceeds ALL the previous nodes
        }
       
        visited[c] = true;
        seen[c] = false;
        
        return res;
    }

    string foreignDictionary(vector<string>& words) {
        map<char,set<char>> charOrder;
        map<char, int> inorder;
        int n = words.size();

        if (words.size() == 1)
            return words[0]; // any order. all node disjoint graph

        for(int i = 1; i < n; i++){
            string w1 = words[i -1];
            string w2 = words[i];

            if (w2.length() < w1.length() && w1.find(w2) == 0)
                return "";

            int m = min(w1.length(), w2.length());
            int j = 0;
            for(; j < m; j++){
                // add all chars to graph
                if(inorder.find(w1[j]) == inorder.end()){
                    inorder[w1[j]] = 0;
                    charOrder[w1[j]] = set<char>{}; // charOrder allways init'd with inorder - index not checked, beware. check its index
                }
                if(inorder.find(w2[j]) == inorder.end()){
                    inorder[w2[j]] = 0;
                    charOrder[w2[j]] = set<char>{};
                }

                if(w1[j] == w2[j])
                    continue; // implicit. not reqd. `for` continues
                else {
                    charOrder[w1[j]].insert(w2[j]);
                    inorder[w2[j]]++;
                    
                    break;// after a match, the rest of the string is not sorted
                }
            }

            // add ALL remaining chars to graph. handle disjoint graph
            // do not use j. j is required below
            for(int k = j; k < w1.length(); k++) {
                if(inorder.find(w1[k]) == inorder.end()){
                    inorder[w1[k]] = 0;
                    charOrder[w1[k]] = set<char>{};
                }
            }

            for(int k = j; k < w2.length(); k++) {
                if(inorder.find(w2[k]) == inorder.end()){
                    inorder[w2[k]] = 0;
                    charOrder[w2[k]] = set<char>{};
                }
            }
        }

        // printing map and set!!!!!
        //cout << (charOrder.begin() -> first)<< ":" << *(charOrder.begin() -> second.begin()) << endl;
        //cout << (inorder.begin() -> first)<< ":" << (inorder.begin() -> second) << endl;
        //cout << ((++inorder.begin()) -> first)<< ":" << ((++inorder.begin()) -> second) << endl;

        string res = "";
        map<char, bool> visited; // to ignore partly traversed paths from another node
        map<char, bool> seen; // to detect cycles. inp is not guaranteed to be valid
        // for all known chars
        for (auto i = inorder.begin(); i != inorder.end(); i++){
            cout << "node " << i -> first << " " << i -> second << endl;
            // if (i -> second > 0 ) detect a cycle
            //     continue;
            string r = trace(i -> first, charOrder, visited, seen);
            if (r == "invalid"){
                return "";
            }
            res = res + r; // disjoint sub-graphs
        }
        // do not reverse sub paths. reverse whole result
        reverse(res.begin(), res.end()); // end of the path first. reverse for forward

        return res;
    }
};


// without input validation, solution changes drastically
// class Solution {
// public:
//     // doesnt matter if node visited in current path or connected path. skip
//     string trace(char c, map<char,set<char>> &charOrder, map<char, bool> &visited){
//         if(visited.find(c) != visited.end())
//             return "";

//         // leaf node. no more neighbors. the below code takes care.visited must be updated too
//         // if(charOrder.find(c) == charOrder.end())
//         //     return string{c};
        
//         string res = "";
//         for(auto nei : charOrder[c]){
//             res += trace(nei, charOrder, visited); // assumption: there are no cycles
//         }

//         // string res{c}; // char to string
//         string cStr{c};
//         res = res + cStr; // append current node to end - post order DFS, to ensure leaf node preceeds ALL the previous nodes
//         visited[c] = true;
        
//         return res;
//     }

//     string foreignDictionary(vector<string>& words) {
//         map<char,set<char>> charOrder;
//         map<char, int> inorder;
//         int n = words.size();

//         for(int i = 1; i < n; i++){
//             string w1 = words[i -1];
            
//             string w2 = words[i];
//             int m = min(w1.length(), w2.length());

//             int j = 0;
//             for(; j < m; j++){
//                 // add all chars to graph
//                 if(inorder.find(w1[j]) == inorder.end()){
//                     inorder[w1[j]] = 0;
//                     charOrder[w1[j]] = set<char>{}; // charOrder allways init'd with inorder - index not checked, beware. check its index
//                 }
//                 if(inorder.find(w2[j]) == inorder.end()){
//                     inorder[w2[j]] = 0;
//                     charOrder[w2[j]] = set<char>{};
//                 }

//                 if(w1[j] == w2[j])
//                     continue; // implicit. not reqd. `for` continues
//                 else {
//                     charOrder[w1[j]].insert(w2[j]);
//                     inorder[w2[j]]++;
                    
//                     break;// after a match, the rest of the string is not sorted
//                 }
//             }

//             // add all remaining chars to graph
//             // do not use j. j is required below
//             for(int k = j; k < w1.length(); k++) {
//                 if(inorder.find(w1[k]) == inorder.end()){
//                     inorder[w1[k]] = 0;
//                     charOrder[w1[k]] = set<char>{};
//                 }
//             }

//             for(int k = j; k < w2.length(); k++) {
//                 if(inorder.find(w2[k]) == inorder.end()){
//                     inorder[w2[k]] = 0;
//                     charOrder[w2[k]] = set<char>{};
//                 }
//             }
//         }

//         // printing map and set!!!!!
//         //cout << (charOrder.begin() -> first)<< ":" << *(charOrder.begin() -> second.begin()) << endl;
//         //cout << (inorder.begin() -> first)<< ":" << (inorder.begin() -> second) << endl;
//         //cout << ((++inorder.begin()) -> first)<< ":" << ((++inorder.begin()) -> second) << endl;

//         string res = "";
//         map<char, bool> visited;
//         // for all known chars
//         for (auto i = inorder.begin(); i != inorder.end(); i++){
//             if (i -> second > 0 )
//                 continue;
//             string r = trace(i -> first, charOrder, visited);
//             reverse(r.begin(), r.end()); // end of the path first. reverse for forward
//             res = res + r; // disjoint graphs
//         }

//         return res;
//     }
// };
