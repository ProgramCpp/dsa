string RemoveDuplicates(string toCleanUp) {
    stack<char> uniqueChars;

    for(int i = 0; i < toCleanUp.length(); i++){
        if(uniqueChars.empty() || uniqueChars.top() != toCleanUp[i]){
            uniqueChars.push(toCleanUp[i]);
        }else{
            uniqueChars.pop();
        }
    }

    string result = "";
    while(! uniqueChars.empty()){
        result = uniqueChars.top() + result;
        uniqueChars.pop();
    }
    
    return result;
}