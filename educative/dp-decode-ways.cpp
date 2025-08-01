int decode(string str, int i, unordered_map<int, int>& m){
    if (i == str.length()) // last character
        return 1;

    if(m.find(i) != m.end()) // already computed
        return m[i];

    if (str[i] == '0'){
        m[i] = 0;
        return m[i]; // if digit is 0, dont check further. 0 ways
    } else{
        m[i] = decode(str, i+1, m); // first character and no of ways the rest can be decoded
    }

    // short circuit if i is len - 1
    if (i + 1 < str.length() && stoi(str.substr(i,2)) < 26){
        m[i] = m[i] + decode(str, i + 2, m);
    }
    return m[i];
}

int NumOfDecodings(std::string decodeStr) {
    //!!!!!! why map when you can use an array!
    unordered_map<int, int> m; // no of ways staarting from every index
    return decode(decodeStr, 0, m); // start from index 0
}