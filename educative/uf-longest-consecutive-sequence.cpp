    #include "UnionFind.cpp"
    #include <map>
    #include <algorithm>

    void unionf(map<int, int> & parent, map<int, int>& rank, int a, int b){
        if(rank[parent[a]] > rank[parent[b]]){
            rank[parent[a]] += rank[parent[b]];
            parent[b] = parent[a];
        }else{
            rank[parent[b]] += rank[parent[a]];
            parent[a] = parent[b];
        }
    }

    int LongestConsecutiveSequence(std::vector<int>& nums) {
        map<int, int> parent;
        map<int, int> rank;

        for(int i = 0; i < nums.size(); i++){
            if(parent.find(nums[i]) == parent.end()){
                parent[nums[i]] = nums[i];
                rank[nums[i]] =1;
            }
            if(parent.find(nums[i]+1) != parent.end()){
                unionf(parent, rank, nums[i], nums[i] + 1);
            }
            if(parent.find(nums[i]-1) != parent.end()){
                unionf(parent, rank, nums[i], nums[i] - 1);
            }
        }

        int lcs = 0;
        for(auto i = rank.begin(); i != rank.end(); i++){
            lcs = lcs > i -> second ? lcs : i -> second;
        }
        return lcs; 
    }