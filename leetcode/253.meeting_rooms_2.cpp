/* 253. meeting rooms 2
instinct: sort intervals by start time. iterate and mark intervals that do not overlap.
repeat until all intervals are marked and count iterations
O(n*n)// iterate all the intervals n times, in worst case the intervals dont overlap
suggested solution: result is the maximum number of overlapping meetings
sort meetings by start date. at any point, count the number of active meetings.
track the maximum concurrent meetings
note: [TRICK] sort start time and end time separately. all that is required is only whether a meeting ended at a given time, doesnt matter which meeting
note: (0,8),(8,10) are not conflicting
tracking start times and end times separately is complex. either start time or end time must be processed depending on which comes first.
instead, put start times and end times in a sequential timeline, marking whether it is start or end time and process sequentially.
*/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starttimes;
        vector<int> endtimes;

        for(auto i : intervals){
            starttimes.push_back(i.start);
            endtimes.push_back(i.end);
        }
        sort(starttimes.begin(), starttimes.end());
        sort(endtimes.begin(), endtimes.end());

        int days =0;
        int countDays = 0;
        
        for(int i = 0, j = 0; i < starttimes.size() || j < endtimes.size();){
            cout << i << " " << j << " " << starttimes[i] << " " << endtimes[j]<< endl;
            //b oth indices must be checked to compare value
            if(i < starttimes.size() && j < endtimes.size()){
                if(starttimes[i] < endtimes[j]){
                    cout << "processing start " << starttimes[i] << endl;
                    countDays++;
                    i++;
                    cout << "count days " << countDays << endl;
                     // when meeting ends, count days always decreases
                     // calculate only when a new meeting starts, not when a meeting ends
                     // min is asked but still new BIGGER VALUES are considered. when more and more concurrent meetings happen, the highest number of days is the solution
                    if(countDays > days) 
                        days = countDays;
                }else if (endtimes[j] < starttimes[i]){
                    cout << "processing end " << endtimes[j] << endl;
                    countDays--;
                    j++;
                } else {
                    cout << "processing start and end " << starttimes[i] << endl;
                    i++;
                    j++;
                }
            } else if(i < starttimes.size()){ // if start or end already processed in tihs iteration, skip to next iteration
                cout << "processing rem start " << starttimes[i] << endl;
                countDays++;
                i++;
                 // when meeting ends, count days always decreases
                 // calculate only when a new meeting starts
                if(countDays > days) 
                    days = countDays;
            }else if (j < endtimes.size()){
                cout << "processing rem end " << starttimes[i] << endl;
                countDays--;
                j++;
            }

            cout << "count days " << countDays << endl;
            cout << "days " << days << endl;
        }

        return days;
    }
};
