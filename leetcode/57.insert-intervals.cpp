/* 57. Insert Interval
intuition: iterate over intervals and insert new interval at the appropriate place.
O(n)
hints: binary search to find the start of the interval. O(log n)
see 2nd example, the new interval can merge existing 3 intervals. new interval overlaps all 3 intervals
implementation complexity with all the edge cases.
insert first and then merge intervals
Hint: whats the point of doing all the hard work with binary search to find insertion point only to proceed with O(n) pass to merge intervals.
*/

// 30 / 158
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int low = 0;
        int high = n-1;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        while(low < high){
            int mid = (high-low)/2;
            mid += low;

            cout << low << " " << high << " " << mid << endl;

            if(mid == n-1){
                if(intervals[mid][1] > newStart){
                    intervals[mid][0] = newStart;
                    intervals[mid][1] = max(newEnd, intervals[mid][1]);
                } else
                    intervals.insert(intervals.end(), vector<int>{newStart, newEnd});
                break; // TLE
            }
            if(newStart > intervals[mid][0] && newStart < intervals[mid+1][0]){
                if(newStart > intervals[mid][1] && newEnd < intervals[mid + 1][0]) // NI between two intervals
                    intervals.insert(intervals.begin()+ mid, vector<int>{newStart, newEnd});
                else if (newStart < intervals[mid][1])// NI merges with first interval{
                    // todo: find the intervals that can be merged with the new interval and remove
                    intervals[mid][1] = newEnd;
                }
                else {
                    intervals[mid+1][0] = newStart;// NI merges with second interval from mid
                    // todo: find the intervals that can be merged with the new interval and remove
                }
                break; // TLE
            } else if (newStart > intervals[mid][0] ) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return intervals;
    }
};