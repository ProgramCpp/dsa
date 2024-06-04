vector<string> WB(string s, unordered_map<string, bool> & wd){
    if (s == ""){
        return {""};
    }

    vector<string> wb;

    for(int i =0; i < s.length(); i++){
        if(wd[s.substr(0, i + 1)]){
            vector<string> subWb = WB(s.substr(i + 1, s.length() - 1 - i), wd);
            for (string s1 : subWb) {
                if (s1 != ""){
                    s1 = " " + s1;
                }
                wb.push_back(s.substr(0, i + 1) + s1);
            }
        } 
    }

    return wb;
}


vector<string> WordBreak(string s, vector<string> wordDict)
{
    unordered_map<string, bool> wd;

    for(string w: wordDict){
        wd[w] = true;
    }

    return WB(s, wd);
}