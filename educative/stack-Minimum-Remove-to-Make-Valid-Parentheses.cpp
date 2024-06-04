string MinRemoveParentheses(string s) {
    stack<int> openParan;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == ')'){
            if(openParan.empty()){
                s[i] = '#';
            } else {
                openParan.pop();
            }
        }else if(s[i] == '('){
            openParan.push(i);
        }
    }

    while(!openParan.empty()){
        s[openParan.top()] = '#';
        openParan.pop();
    }

    int count = 0;
    for(int i = 0, j = 0; i < s.length(); i++)
        if(s[i] != '#'){
            s[j++] = s[i]; 
            count++;
        } 

    cout << count;
    return s.substr(0,count);
}