/*
naive approach:
- for i to n, convert to string and add to set (set maintains a weak ordering)
    for each string, convert back to int and return
- convert nos to string and sort: n + n^2 / n + nlog n
- insert nos into hashmap by the first digits. iterate all the nos: 2n
- using tries: n * l + n * l
*/





// #include <iostream>
// #include <list>

// int firstDigit(int n)
// {
//     // Remove last digit from number
//     // till only one digit is left
//     while (n >= 10) 
//         n /= 10;
     
//     // return the first digit
//     return n;
// }

// vector<int> LexicographicalOrder(int n)
// {
//     map<int, list<int>> order;

//     for(int i = 1; i <= n; i++){
//         order[firstDigit(i)].push_back(i);
//     }

//     vector<int> result;
//     for(auto i = order.begin(); i != order.end(); i++){
//         for(auto j = i->second.begin(); j != i-> second.end(); j++){
//             result.push_back(*j);
//         }
//     }

//     return result;
// }


/*
the above solution doesnt work for below case,
Input
n =
100

Use Testcase
Output
[1,10,11,12,13,14,15,16,17,18,19,100,2,20,21,22,23,24,25,26,27,28,29,3,30,31,32,33,34,35,36,37,38,39,4,40,41,42,43,44,45,46,47,48,49,5,50,51,52,53,54,55,56,57,58,59,6,60,61,62,63,64,65,66,67,68,69,7,70,71,72,73,74,75,76,77,78,79,8,80,81,82,83,84,85,86,87,88,89,9,90,91,92,93,94,95,96,97,98,99]
Expected
[1,10,100,11,12,13,14,15,16,17,18,19,2,20,21,22,23,24,25,26,27,28,29,3,30,31,32,33,34,35,36,37,38,39,4,40,41,42,43,44,45,46,47,48,49,5,50,51,52,53,54,55,56,57,58,59,6,60,61,62,63,64,65,66,67,68,69,7,70,71,72,73,74,75,76,77,78,79,8,80,81,82,83,84,85,86,87,88,89,9,90,91,92,93,94,95,96,97,98,99]
*/

#include <iostream>
#include <list>
#include "Trie.cpp"

int getbase(int n){
    int b = 1;

    if (n == 0){
        return b * 10; // handle 0 unit's place
    }
    
    while( n > 0){
        b *= 10;
        n /= 10;
    }

    return b;
}

vector<int> prefix(char c, vector<int>& nos){
    // if (!nos.size()){
    //     return {c- '0'};
    // }
    for(auto i = nos.begin(); i != nos.end(); i++){
        int b = getbase(*i);
        // handle 0 unit's place. dont multiply base with 0. retain 10
        if(c - '0')
            b *= c - '0';
        *i = *i + b;
    }
    return nos;
}

void append(vector<int> &first, vector<int> second){
    first.insert(first.end(), second.begin(), second.end());
}

vector<int> print(TrieNode *root){
    vector<int> result;
    for(auto c = root->children.begin(); c != root->children.end(); c++){
        // base case: for units place. insert the first digit
        if(c->second->isWord)
            result.push_back(c->first - '0');
        vector<int> nos = print(c->second);
        append(result, prefix(c->first, nos));
    }
    return result;
}

vector<int> LexicographicalOrder(int n)
{
    Trie nStrs;

    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        nStrs.Insert(s);
    }

    auto result = print(nStrs.root);
    return result;
}