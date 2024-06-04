// #include<unordered_set>


// // https://www.youtube.com/watch?v=hLQYQ4zj0qg
// bool isvalid(string s, unordered_map<string, bool>& wordDict){
//     if (s == "")
//         return true;

//     for(int i = 0; i < s.length(); i++) {
//         if (wordDict[s.substr(0, i + 1)] && isvalid(s.substr( i + 1, s.length() - 1 - i ), wordDict))
//             return true;
//     }

//     return false;
// }


// bool WordBreak(string s, vector<string>& wordDict)
// {
//     unordered_map<string, bool> d(wordDict.size());

//     for (string w: wordDict){
//         d[w] = true;
//     }

//     return isvalid(s, d);
// }



#include<unordered_set>


// https://www.youtube.com/watch?v=hLQYQ4zj0qg
bool isvalid(string s, unordered_map<string, bool>& wordDict){
    if (s == "")
        return true;

    if (wordDict[s])
        return true;

    for(int i = 0; i < s.length(); i++) {
        if (wordDict[s.substr(0, i + 1)] && isvalid(s.substr( i + 1, s.length() - 1 - i ), wordDict)){
            wordDict[s] = true;
            return true;
        }
    }

    return false;
}


bool WordBreak(string s, vector<string>& wordDict)
{
    unordered_map<string, bool> d(wordDict.size());

    for (string w: wordDict){
        d[w] = true;
    }

    return isvalid(s, d);
}