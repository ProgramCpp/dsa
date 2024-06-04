/*
Intuition
There is a valid permutation if and only if the count of the character with the largest occurence is less than or equal to (S.size() + 1) / 2.

Approach
Count the occurences of all letters and store in count[i].
Find the letter with largest occurence.
Put this letter into even index numbers (0, 2, 4 ...) char array. // second largest occurence into even index for the rest of the array
Put the rest letters into the array.
*/
struct Frequency {
    public:
        char c;
        int f;
        Frequency(char c, int f):c(c),f(f){}
        bool operator<(const Frequency &other) const {
            return f < other.f;
        }
};

string ReorganizeString(string str)
{    
    map<char, int> freq;

    for (int i = 0; i < str.length(); i++){
        freq[str[i]]++;
    }

    priority_queue<Frequency> orderedFreq;
    for(map<char, int>::iterator i = freq.begin(); i != freq.end(); i++){
        orderedFreq.push(Frequency(i->first, i->second));
    }

    if(orderedFreq.top().f > (str.length()/2 + 1)){
        cout << "top freq";
        return "";
    }
        

    string output = "";
    Frequency prev = Frequency('.', 0);
    while(!orderedFreq.empty()){
        Frequency current = orderedFreq.top();
        orderedFreq.pop();
        if (!orderedFreq.size() && prev.f > 1){
            cout << "more than one last ele";
            return ""; // the remaining char must not repeat in the end
        }
           
        output += current.c; 
        current.f--;

        if(prev.f){
            // no 2 chars can be next to each other.
            // instead of immediately pushing. wait until appending the next element
            orderedFreq.push(prev); 
        }
        prev = current; 
    }

    if(prev.f){
        output += prev.c;
    }

    return output;
}