set<string> FindRepeatedSequences(string s, int k)
{
    // Replace this placeholder return statement with your code
    set<string> output{};
    map<int, int> found;
    map<char, int> toInt{
        {'A', 1},
        {'C', 2},
        {'G', 3},
        {'T', 4},
        };

    int base = 10;
    // ^ is a bitwise or operator
    long multiplier = pow(base, (k - 1));
    long hash = 0;
    for(int i = 0; i < k; i++){
        hash +=(toInt[s[i]]) * pow(base, i);
    }
    found[hash] = 1;

    cout << hash << endl;

    for(int i = 1; i < s.length()-k; i++) {
        // if ure using - variables. use -(variables). minus needs to be multiplied by all variables
         hash = ( (hash - toInt[s[i-1]]) / base)  + ((toInt[s[i + k -1]])* multiplier);
         if (found[hash] == 1){
             output.insert(s.substr(i, k));
         }  
        found[hash]++;
        // cout << s[i-1]-64 << endl;
        // cout << (hash - (s[i-1]-64)) << endl;
        // cout << (hash - (s[i-1]-64)) / base<< endl;
        // cout << (s[i + k -1] - 64)<< endl;
        // cout << pow(base, (k - 1))<< endl;
        // cout << ((s[i + k -1] - 64)* pow(base, (k - 1)))<< endl;
        // cout << ( (hash - (s[i-1]-64)) / base)  + ((s[i + k -1] - 64)* pow(base, (k - 1)))<< endl;
        cout << hash << endl;
    }
    return output;
}