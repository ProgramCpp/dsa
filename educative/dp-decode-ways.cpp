int decode(string str, int i, unordered_map<int, int>& m){
    if (i == str.length())
        return 1;

    if(m.find(i) != m.end())
        return m[i];

    if (str[i] == '0'){
        m[i] = 0;
        return m[i]; // if digit is 0, dont check for double digits
    } else{
        m[i] = decode(str, i+1, m);
    }

    // short circuit if i is len - 1
    if (i + 1 < str.length() && stoi(str.substr(i,2)) < 26){
        m[i] = m[i] + decode(str, i + 2, m);
    }
    return m[i];
}

int NumOfDecodings(std::string decodeStr) {
    //!!!!!! why map when you can use an array!
    unordered_map<int, int> m;
    return decode(decodeStr, 0, m);
}