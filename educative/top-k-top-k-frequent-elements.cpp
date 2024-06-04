struct Number{
    int x;
    int f;
    Number(int x, int f): x(x), f(f){}
    bool operator<(const Number &n) const {
        // min heap. remove smaller elements
        return f > n.f;
    }
};

vector<int> TopKFrequent(vector<int> lists, int k)
{
    map<int, int> freq;

    for(vector<int>::iterator i = lists.begin(); i != lists.end(); i++){
        freq[*i]++;
    }
    
    priority_queue<Number> topK;
    for(map<int, int>::iterator i = freq.begin(); i != freq.end(); i++) {
        topK.push(Number(i->first, i -> second));
        if(topK.size() > k)
            topK.pop();
    }

    vector<int> result;
    while(!topK.empty()){
        result.push_back(topK.top().x);
        topK.pop();
    }

    return result;
}