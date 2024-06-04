class word {
    public:
    string w;
    int f;
    word(string w, int f):w(w), f(f){}
    bool operator<(const word &other) const{
        if (f == other.f){
            // min heap - ascending first
             return w > other.w;// w.compare(other.w) > 0
        }
        // max heap - higher freq first
        return f < other.f;
    }
};

vector<string> TopKFrequent(vector<string> words, int k)
{
    map<string, int> freq;
    for(vector<string>::iterator i = words.begin(); i != words.end(); i++){
        freq[*i]++;
    }

    priority_queue<word> topK;
    for(map<string, int>::iterator i = freq.begin(); i != freq.end(); i++){
        topK.push(word(i->first, i->second));
    }

    vector<string> result;
    for(int i = 0; i < k; i++){
        result.push_back(topK.top().w);
        topK.pop();
    }
    return result;
}