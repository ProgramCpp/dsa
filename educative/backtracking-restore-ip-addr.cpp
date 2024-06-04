bool isValid(string segment) {
    int m = segment.length(); 
    if (m > 3 || m < 1) 
        return false;

    if (segment[0] == '0' && m != 1)
        return false;

    return  stoi(segment) <= 255;
}

vector<string> getAddresses(string s, int start, int n, string ip){
    string seg = s.substr(start, string::npos);
    if (n==4 && isValid(seg)){
        ip.append("." + seg);
        cout << "segment " << n << ":" << seg<< "is " << isValid(seg) << endl;
        cout << "found ip " << ip << endl;
        return vector<string> {ip};
    } else if (n == 4)
        return vector<string>{};

    vector<string> addresses;
    for(int i = 0; i <3;){
        string iIp = ip;
        if (start >= s.length()|| start + i >= s.length())
            break;
        string seg = s.substr(start, i + 1);
        cout << "segment " << n << ":" << seg << " is " << isValid(seg) << endl;
        if (isValid(seg)){
            if (n != 1)
                iIp.append(".");
            iIp.append(seg);
            vector<string> addrs = getAddresses(s, start + i + 1, n + 1, iIp);
            addresses.insert(addresses.end(), addrs.begin(), addrs.end());
        }
        if (s[start] == '0'){
                break;
        }
        i++;
    }

    return addresses;
}

vector<string> RestoreIpAddresses(string s){
    return getAddresses(s, 0, 1, "");
}
