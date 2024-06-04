// times out
// first save all wildcard patterns of all input words.
// from src, change each char by char and check if wildcard pattern is found.

/*
n: no of words
m: max length of words
time complexity: m*n + m*n
space complexity: m*n + 2n
*/ 


// #include <iostream>
// #include <vector>
// #include <set>
// #include <map>

// int WordLadder(std::string src, std::string dest, const std::vector<std::string>& words) {
//     unordered_map<string,vector<string>> diff;

//     for(vector<string>::const_iterator i = words.begin(); i != words.end(); i++){
//         for(int index = 0; index < i->length(); index++){
//             string s = *i;
           
//             s[index] = '*';
//             // if (diff.find(s) == diff.end())
//             //     diff[s]= vector<string>();
//             diff[s].push_back(*i);
//         }
//     }

//     queue<string> transitions;
//     transitions.push(src);
//     set<string> traversed;
//     int changes = 0;

//     while(!transitions.empty()){
//         int len = transitions.size();
//         changes++;
//         for(int i = 0; i < len; i++){
//             string s = transitions.front();
//             transitions.pop();
//             traversed.insert(s);
//             for(int index = 0; index != s.length(); index++){
//                 string match = s;
//                 match[index] = '*';
//                 for(vector<string>::iterator it = diff[match].begin(); it != diff[match].end(); it++){
//                     if(s == dest)
//                         return changes;
//                     if (traversed.find(match) == traversed.end()){
//                         transitions.push(*it);
//                     }
//                 }
//             }
//         }
//     }

//     return -1;
// }



/*
n: no of words
m: max length of words
time complexity: n + 26*n
space complexity: n + n + n
*/ 


#include <iostream>
#include <vector>
#include <set>
#include <map>

int WordLadder(std::string src, std::string dest, const std::vector<std::string>& words) {
    set<string> wrds;

    for(vector<string>::const_iterator i = words.begin(); i != words.end(); i++){
        wrds.insert(*i);
    }

    queue<string> transitions;
    transitions.push(src);
    int changes = 0;

    while(!transitions.empty()){
        changes++;
        int len = transitions.size();
        for(int i = 0; i < len; i++){
            string front = transitions.front();
            transitions.pop();
            for (int index = 0; index < front.length(); index++){
                for( char c = 'a'; c <= 'z'; c++){
                    string match = front; // alternatively u can put back the original char. saving additional string copy
                    match[index] = c;
                    set<string>::iterator it = wrds.find(match);
                    if(it != wrds.end()){
                        if(match == dest)
                            return changes + 1;
                        transitions.push(match);
                        wrds.erase(it);
                    }    
                }
            }
        }
    }

    return 0;
}