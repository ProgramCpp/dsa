// 56. Merge Intervals
// brute force/ greedy
// sort by start time, keep merging with the last item in the result, if overlaps. else append.

struct Interval {
    int start;
    int end;
    Interval(int s, int e): start(s), end(e){}
    bool operator< (Interval const & other) const{
        if(start == other.start){
            return end < other.end;
        }
        return start < other.start;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort modifies the inp vector
        vector<Interval> sortedIntervals;
        for(auto i : intervals){
            sortedIntervals.push_back(Interval(i[0], i[1]));
        }
        sort(sortedIntervals.begin(), sortedIntervals.end());
        
        vector<vector<int>> output;
        int start = sortedIntervals[0].start, end = sortedIntervals[0].end;
        for(auto i = sortedIntervals.begin() + 1; i != sortedIntervals.end(); i++){
            if(i->start <= end){
                if(i->end > end)
                    end = i->end;
            } else {
                output.push_back({start, end});
                start = i->start;
                end = i->end;
            }
        }

        output.push_back({start, end});

        return output;
    }
};