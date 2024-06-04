struct Segment {
    int node;
    int delay;
    Segment():node(0), delay(0){}
    Segment(int node, int delay){
        this -> node = node;
        this -> delay = delay;
    }
    bool operator<(const Segment &b) const{
        // priority queue by default is max heap
        // for min heap, compare >
        return this->delay > b.delay;
    }
};

// weighted adjacency list
struct Connection {
    int node;
    int delay;
    Connection *next;
};

int NetworkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
    // init array to NULL- seg fault
    Connection *graph[n+1]={NULL};
    priority_queue<Segment> delays;
    bool visited[n+1]={false};

    for(vector<int> time : times){
        Connection *c =  new(Connection);
        c -> node = time[1];
        c -> delay = time[2];
        c -> next = graph[time[0]];
        graph[time[0]] = c;
    }

    delays.push(Segment(k,0));

    int delay = 0;

    while(!delays.empty()){
        Segment s = delays.top();
        delays.pop();

        if (visited[s.node]) 
            continue;
        visited[s.node] = true;

        for(Connection *c = graph[s.node]; c != NULL; c = c -> next){
             if (!visited[c -> node]) // node already visited with least delay
                delays.push(Segment(c->node, s.delay + c->delay));
        }
        
        if (delay < s.delay)
            delay = s.delay;
        cout << s.delay << endl;
        cout << delay << endl << "----" << endl;
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i])
            return -1;
    }
    
    return delay;
}